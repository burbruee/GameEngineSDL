#include <SDL/SDL.h>
#include <SDL/SDL_rotozoom.h>
#include <string>

class Sprite
{
    private:
        float x;
        float y;

        float vx;
        float vy;

        int speed;

    public:
        Sprite();
        void HandleInput(SDL_Event *event);
        void Move(Uint32 deltaTicks);
        void Display();
};
