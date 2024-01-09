#ifndef Game_hpp
#define Game_hpp

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <iostream>
#include "Input.h"
#include <vector>

class ColliderComponent;

class Game {
    // private variables
    private:
        bool isRunning;
        SDL_Window *window;
        int Width, Height;
        Input* game_input;

        int cnt = 0;// a counter for the  game loop

        //public methods
    public:
        Game();
        ~Game();

        void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

        void handleEvents();
        void update();
        bool running() { return isRunning; }
        void render();
        void clean();


        static void AddTile(int id, int x, int y);

        static SDL_Renderer *renderer;
        static SDL_Event event;
        static std::vector<ColliderComponent*> colliders;

};

#endif /* Game_hpp */
