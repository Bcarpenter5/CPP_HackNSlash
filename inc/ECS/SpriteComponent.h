#pragma once
#include "Components.h"
#include "../TextureManager.h"
#include "ECS.h"
#include "SDL.h"
#include "Animation.h"
#include <map>

class SpriteComponent : public Component{

    private:
        TransformComponent* transform;
        SDL_Texture* texture;
        SDL_Rect srcRect, destRect;

        bool animated = false;
        int frames = 0;
        int speed = 100;// in ms 


    public:
        int animIndex = 0;
        std::map<const char*, Animation> animations;

        SDL_RendererFlip spriteFlip = SDL_FLIP_NONE;


        SpriteComponent() = default;
        SpriteComponent(const char* path){
            setTex(path);
        }

        SpriteComponent(const char* path, int nframes, int ms){
            animated = true;
            Animation singleAnim = Animation(0, nframes, ms);
            frames = nframes;
            speed = ms;
            setTex(path);
        }
        SpriteComponent(const char* path, int nframes, int ms, bool hasDirections){
            animated = true;
            frames = nframes;
            speed = ms;
            if(hasDirections){
                Animation idle = Animation(0, nframes, ms);
                Animation walk = Animation(1, nframes, ms);

                animations.emplace("Idle", idle);
            }
            else{
                Animation singleAnim = Animation(0, nframes, ms);
                animations.emplace("SingleAnimation", singleAnim);
                animIndex = 0;
                Play("SingleAnimation");
            }
            setTex(path);
        }

        ~SpriteComponent(){
            SDL_DestroyTexture(texture);
        }

        void setTex(const char* path){
            texture = TextureManager::LoadTexture(path);
        }

        void init() override{
            transform = &entity->getComponent<TransformComponent>();

            srcRect.x = srcRect.y = 0;
            srcRect.w = transform->width;
            srcRect.h = transform->height;
            
        }

        void update() override{

            if(animated){
                srcRect.x = srcRect.w * static_cast<int>((SDL_GetTicks() / speed) % frames);
            }
            srcRect.y = animIndex * transform->height;

            destRect.x = (int)transform->position.x;
            destRect.y = (int)transform->position.y;
            destRect.w = transform->width * transform->scale;
            destRect.h = transform->height * transform->scale;
        }

        void draw() override{
            TextureManager::Draw(texture, srcRect, destRect, spriteFlip);
        }

        void Play(const char* animName){
            frames = animations[animName].frames;
            animIndex = animations[animName].index;
            speed = animations[animName].speed;
        }
};

