#include <iostream>
#include "Game.hpp"

Game *game = nullptr;


int main()
{ 
    // Fram rate conmtrol
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;
    Uint32 frameStart;
    int frameTime;


    game = new Game();
    game->init("Dungeon ...", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);
    while(game->running())
    {
        frameStart = SDL_GetTicks();
        game->handleEvents();
        game->update();
        game->render();

        // frame rate control
        frameTime = SDL_GetTicks() - frameStart;
        if(frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }

    }
    game->clean();

    return 0;


}

