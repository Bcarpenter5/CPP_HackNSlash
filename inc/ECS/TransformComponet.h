#include "ECS.h"
#include "../Vector2D.h"

class TransformComponent : public Component
{

    public:
        Vector2D position;
        Vector2D velocity;

        int height = 32;
        int width = 32;
        int scale = 1;

        int speed = 3;

        TransformComponent()
        {
            position.Zero();
            
        }
        TransformComponent(int sc)
        {
            position.Zero();
            scale = sc;
        }

        TransformComponent(int x, int y)
        {
            position.x = x;
            position.y = y;
        }

        TransformComponent(int x, int y, int h, int w, int s)
        {
            position.x = x;
            position.y = y;
            height = h;
            width = w;
            scale = s;
        }

        

        void init() override
        {
            velocity.Zero();
        }


        void update() override
        {
            position.x += velocity.x * speed;
            position.y += velocity.y * speed;
        }

};
