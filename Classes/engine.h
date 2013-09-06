#ifndef ENGINE_H
#define ENGINE_H

#include <SDL/SDL.h>

class Engine
{
    private:
        bool isRunning;

    public:
        Engine();

        bool Init();
        void Event(SDL_Event *event);
        void Loop();
        void Render();
        void CleanUp();

};

#endif // ENGINE_H
