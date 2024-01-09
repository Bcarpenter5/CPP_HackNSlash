#include "Game.hpp"
#include "Input.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Map.h"
#include "ECS/Components.h"
#include "Vector2D.h"
#include "Collision.h"


// Map* map;

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;

std::vector<ColliderComponent*> Game::colliders;

Manager manager;
auto& Player(manager.addEntity());
auto& Enemy(manager.addEntity());

enum groupLabels : std::size_t
{
    groupMap,
    groupPlayers,
    groupEnemies,
    groupColliders
};



Game::Game()
{

}
Game::~Game()
{
    //dtor
}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int flags = 0;

    // set the width and height variables
    Width = width;
    Height = height;

    if(fullscreen)// check the fill screen flag
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "Subsystems initialized!..." << std::endl;
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if(window)
        {
            std::cout << "Window created!" << std::endl;
        }
        renderer = SDL_CreateRenderer(window, -1, 0);
        if(renderer)
        {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            std::cout << "Renderer created!" << std::endl;
        }
        isRunning = true;

    }
    else isRunning = false;// set isRunning to false if SDL_Init fails



    // map = new Map();

    // Map::LoadMap("../assets/Test_10x10.map", 10, 10);
    Map::LoadMap("../assets/map2.stp");
    // Map::LoadMap("../assets/Map2.map", 25, 20);
    // Map::LoadMap("../assets/map.map", 25, 20);

    

    //ecs implementation

    Player.addComponent<TransformComponent>(2);
    Player.addComponent<SpriteComponent>("../assets/player_idle.png", 2, 100);
    Player.addComponent<KeyboardControler>();
    Player.addComponent<ColliderComponent>("player");
    Player.addGroup(groupPlayers);

    Enemy.addComponent<TransformComponent>(2);
    Enemy.addComponent<SpriteComponent>("../assets/enemy_Idle.png", 4, 100);
    Enemy.getComponent<TransformComponent>().position = Vector2D(100.0f, 100.0f);
    Enemy.addComponent<ColliderComponent>("enemy");
    Enemy.addGroup(groupEnemies);


}

void Game::handleEvents()
{
    SDL_PollEvent(&event);
    switch(event.type)
    {
        case SDL_QUIT:
            isRunning = false;
            break;
        case SDL_KEYDOWN:
            if(event.key.keysym.sym == SDLK_F11)
            {
                if(SDL_GetWindowFlags(window) & SDL_WINDOW_FULLSCREEN)
                    SDL_SetWindowFullscreen(window, 0);
                else SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
            }
            break;
        default:
            break;
    }
}

void Game::update()
{
    cnt++;
    manager.refresh();
    manager.update();


    if(Player.getComponent<TransformComponent>().position.x > Width)
    {
        Player.getComponent<TransformComponent>().position.x = 0;
    }
    if(Player.getComponent<TransformComponent>().position.x < 0)
    {
        Player.getComponent<TransformComponent>().position.x = Width;
    }
    if(Player.getComponent<TransformComponent>().position.y > Height)
    {
        Player.getComponent<TransformComponent>().position.y = 0;
    }
    if(Player.getComponent<TransformComponent>().position.y < 0)
    {
        Player.getComponent<TransformComponent>().position.y = Height;
    }

    for(auto cc : colliders)
    {
        // if(Collision::AABB(Player.getComponent<ColliderComponent>(), *cc) && Player.getComponent<ColliderComponent>().tag != cc->tag)
        // {
        //     // Player.getComponent<TransformComponent>().velocity * -1;
        //     std::cout << "Player hit wall" << std::endl;
        // }
        
    }
}

auto& tiles(manager.getGroup(groupMap));
auto& players(manager.getGroup(groupPlayers));
auto& enemies(manager.getGroup(groupEnemies));
auto& colliders(manager.getGroup(groupColliders));

void Game::render()
{
    SDL_RenderClear(renderer);// clear the renderer
    
    for(auto& t : tiles)
    {
        t->draw();
    }
    for(auto& p : players)
    {
        p->draw();
    }
    for(auto& e : enemies)
    {
        e->draw();
    }
    for(auto& c : colliders)
    {
        c->draw();
    }

    SDL_RenderPresent(renderer);
}
void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}


void Game::AddTile(int id, int x, int y)
{
    auto& tile(manager.addEntity());
    tile.addComponent<TileComponent>(x, y, 32, 32, id);
    
    tile.addGroup(groupMap);

}




