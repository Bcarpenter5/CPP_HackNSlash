#pragma once

#include "ECS.h"
#include "../Game.hpp"
#include "Components.h"
#include "../Input.h"


class KeyboardControler : public Component{
    private:
        Input* input;

    public:
        TransformComponent* transform;
        

        void init() override{
            transform = &entity->getComponent<TransformComponent>();
            input = new Input();
        }

        void update() override{
            if(Game::event.type == SDL_KEYDOWN){
                switch(Game::event.key.keysym.sym){
                    case SDLK_w:
                        input->UpadateState(DIR_UP,1 );
                        break;
                    case SDLK_a:
                        input->UpadateState(DIR_LEFT,1 );
                        break;
                    case SDLK_s:
                        input->UpadateState(DIR_DOWN,1 );
                        break;
                    case SDLK_d:
                        input->UpadateState(DIR_RIGHT,1 );
                        break;
                    default:
                        break;
                }
            }

            if(Game::event.type == SDL_KEYUP){
                switch(Game::event.key.keysym.sym){
                    case SDLK_w:
                        input->UpadateState(DIR_UP,0 );
                        break;
                    case SDLK_a:
                        input->UpadateState(DIR_LEFT,0 );
                        break;
                    case SDLK_s:
                        input->UpadateState(DIR_DOWN,0 );
                        break;
                    case SDLK_d:
                        input->UpadateState(DIR_RIGHT,0 );
                        break;
                    default:
                        break;
                }
            }

            transform->velocity = input->GetDirection();

            


        }
};
