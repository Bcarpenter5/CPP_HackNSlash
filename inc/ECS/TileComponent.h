#pragma once

#include "ECS.h"
#include "Components.h"
#include "ECS/SpriteComponent.h"
#include <SDL2/SDL.h>


class TileComponent : public Component
{
    public:
        TransformComponent* transform;
        SpriteComponent* sprite;

        SDL_Rect tileRect;
        int tileID;
        char* path;


        TileComponent() = default;

        TileComponent(int x, int y, int w, int h, int id)
        {
            tileRect.x = x;
            tileRect.y = y;
            tileRect.w = w;
            tileRect.h = h;
            tileID = id;

            switch(tileID)
            {
                case 1:
                    path = "../assets/dirt.png";
                    break;
                case 0:
                    path = "../assets/grass.png";
                    break;
                case 2:
                    path = "../assets/water.png";
                    break;
                default:
                    break;
            }
        }

        void init() override
        {
            entity->addComponent<TransformComponent>(tileRect.x, tileRect.y, tileRect.w, tileRect.h, 1);
            transform = &entity->getComponent<TransformComponent>();
            //std::cout << "TileComponent init" << std::endl;

            if(tileID == 2)
            {
                entity->addComponent<ColliderComponent>("water");
                entity->addComponent<SpriteComponent>(path, 4, 400);
            }
            else entity->addComponent<SpriteComponent>(path);
            sprite = &entity->getComponent<SpriteComponent>();
        }




};
