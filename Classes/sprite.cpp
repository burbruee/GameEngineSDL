#include "sprite.h"

Sprite::Sprite()
{
    x = 0;
    y = 0;

    vx = 0;
    vy = 0;

    speed = 200;
}

void Sprite::HandleInput(SDL_Event *event)
{
    if (event->type == SDL_KEYDOWN)
    {
        switch (event->key.keysym.sym)
        {
            case SDLK_LEFT:
                vx -= speed;
                break;
            case SDLK_RIGHT:
                vx += speed;
                break;
        }
    }

    else if (event->type == SDL_KEYUP)
    {
        switch (event->key.keysym.sym)
        {
            case SDLK_LEFT:
                vx += speed;
                break;
            case SDLK_RIGHT:
                vx -= speed;
                break;
        }
    }
}

void Sprite::Move(Uint32 deltaTicks)
{
    x += vx * (deltaTicks / 1000.f);

    if (x < 0)
        x = 0;



}

void Sprite::Display()
{

}

