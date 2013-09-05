#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_rotozoom.h>
#include <string>
#include "Classes/sprite.h"

#define REAL_X 640
#define REAL_Y 480

#define VIRTUAL_X 48
#define VIRTUAL_Y 32

SDL_Surface* screen_surf;
unsigned char screen[VIRTUAL_X][VIRTUAL_Y];
bool isRunning = true;
SDL_Event event;

    Sprite player;
int scale = REAL_X / VIRTUAL_X;

int playerX = (VIRTUAL_X / 2) - 4;
int playerY = VIRTUAL_Y - 14;

bool setScale = true;

SDL_Surface* LoadImage(std::string filename)
{
    SDL_Surface* loadedImage = NULL;
    SDL_Surface* optimizedImage = NULL;

    if (setScale)
    {
        loadedImage = IMG_Load(filename.c_str());
        loadedImage = zoomSurface(loadedImage, scale, scale, 0);
    }
    else
    {
        loadedImage = IMG_Load(filename.c_str());
    }

    if (loadedImage != NULL)
    {
        optimizedImage = SDL_DisplayFormatAlpha(loadedImage);

        SDL_FreeSurface(loadedImage);
    }

    return optimizedImage;
}

void DrawImage(int x, int y, SDL_Surface* src, SDL_Surface* dest)
{
    SDL_Rect offset;

    offset.x = x * scale;
    offset.y = y * scale;
    offset.w = scale;
    offset.h = scale;

    SDL_BlitSurface(src, NULL, dest, &offset);
}

void HandleInput()
{
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
        {
            isRunning = false;
        }
    }
}

void DrawPixel()
{
    SDL_FillRect(screen_surf, NULL, 0x000000);

    for (int y = 0; y < VIRTUAL_Y; y++)
    {
        for (int x = 0; x < VIRTUAL_X; x++)
        {
            if (screen[x][y] == 1)
            {
                SDL_Rect dest;
                dest.x = x * scale;
                dest.y = y * scale;
                dest.w = scale;
                dest.h = scale;

                SDL_FillRect(screen_surf, &dest, SDL_MapRGB(screen_surf->format, 0xFF, 0xFF, 0x00));
            }

            if (screen[x][y] == 2)
            {
                SDL_Rect dest;
                dest.x = x * scale;
                dest.y = y * scale;
                dest.w = scale;
                dest.h = scale;

                SDL_FillRect(screen_surf, &dest, SDL_MapRGB(screen_surf->format, 0xFF, 0x00, 0x00));
            }

            if (screen[x][y] == 3)
            {
                SDL_Rect dest;
                dest.x = x * scale;
                dest.y = y * scale;
                dest.w = scale;
                dest.h = scale;

                SDL_FillRect(screen_surf, &dest, SDL_MapRGB(screen_surf->format, 0x00, 0xFF, 0xFF));
            }

            if (screen[x][y] == 4)
            {
                SDL_Rect dest;
                dest.x = x * scale;
                dest.y = y * scale;
                dest.w = scale;
                dest.h = scale;

                SDL_FillRect(screen_surf, &dest, SDL_MapRGB(screen_surf->format, 0xFF, 0xC8, 0x00));
            }

            if (screen[x][y] == 5)
            {
                SDL_Rect dest;
                dest.x = x * scale;
                dest.y = y * scale;
                dest.w = scale;
                dest.h = scale;

                SDL_FillRect(screen_surf, &dest, SDL_MapRGB(screen_surf->format, 0x00, 0x00, 0xFF));
            }

            if (screen[x][y] == 6)
            {
                SDL_Rect dest;
                dest.x = x * scale;
                dest.y = y * scale;
                dest.w = scale;
                dest.h = scale;

                SDL_FillRect(screen_surf, &dest, SDL_MapRGB(screen_surf->format, 0xFF, 0x00, 0xFF));
            }

            if (screen[x][y] == 7)
            {
                SDL_Rect dest;
                dest.x = x * scale;
                dest.y = y * scale;
                dest.w = scale;
                dest.h = scale;

                SDL_FillRect(screen_surf, &dest, SDL_MapRGB(screen_surf->format, 0x00, 0xFF, 0x00));
            }
        }
    }
}

int main(int argc, char* argv[])
{
    SDL_Init(SDL_INIT_VIDEO);
    screen_surf = SDL_SetVideoMode(REAL_X, REAL_Y, 16, SDL_HWSURFACE | SDL_DOUBLEBUF);

    SDL_ShowCursor(0);
    SDL_WM_SetCaption("Scale Sprites Test", NULL);

    if (!setScale)
        scale = 1;


    SDL_Surface* key = NULL;
    key = LoadImage("key.png");

    screen[25][2] = 1;
    screen[26][2] = 1;
    screen[25][3] = 1;
    screen[26][3] = 1;

    screen[30][2] = 2;
    screen[31][2] = 2;
    screen[32][2] = 2;
    screen[33][2] = 2;

    screen[37][2] = 6;
    screen[37][3] = 6;
    screen[38][3] = 6;
    screen[38][4] = 6;

    screen[40][7] = 3;
    screen[41][7] = 3;
    screen[42][7] = 3;
    screen[41][8] = 3;

    screen[40][11] = 4;
    screen[41][11] = 4;
    screen[42][11] = 4;
    screen[40][12] = 4;

    screen[40][15] = 7;
    screen[41][15] = 7;
    screen[41][16] = 7;
    screen[42][16] = 7;

    screen[40][19] = 5;
    screen[41][19] = 5;
    screen[42][19] = 5;
    screen[42][20] = 5;

    screen[26][6] = 1;
    screen[27][6] = 1;
    screen[28][6] = 1;
    screen[29][6] = 1;
    screen[30][6] = 1;
    screen[31][6] = 1;
    screen[32][6] = 1;
    screen[33][6] = 1;
    screen[34][6] = 1;
    screen[35][6] = 1;
    screen[36][6] = 1;
    screen[37][6] = 1;

    screen[26][7] = 1;
    screen[37][7] = 1;

    screen[26][8] = 1;
    screen[37][8] = 1;

    screen[26][9] = 1;
    screen[37][9] = 1;

    screen[26][10] = 1;
    screen[37][10] = 1;

    screen[26][11] = 1;
    screen[37][11] = 1;

    screen[26][12] = 1;
    screen[37][12]= 1;

    screen[26][13] = 1;
    screen[37][13] = 1;

    screen[26][14] = 1;
    screen[37][14] = 1;

    screen[26][15] = 1;
    screen[37][15] = 1;

    screen[26][16] = 1;
    screen[37][16] = 1;

    screen[26][17] = 1;
    screen[37][17] = 1;

    screen[26][18] = 1;
    screen[37][18] = 1;

    screen[26][19] = 1;
    screen[37][19] = 1;

    screen[26][20] = 1;
    screen[37][20] = 1;

    screen[26][21] = 1;
    screen[37][21] = 1;

    screen[26][22] = 1;
    screen[37][22] = 1;

    screen[26][23] = 1;
    screen[37][23] = 1;

    screen[26][24] = 1;
    screen[37][24] = 1;

    screen[26][25] = 1;
    screen[37][25] = 1;

    screen[26][26] = 1;
    screen[37][26] = 1;

    screen[26][27] = 1;
    screen[27][27] = 1;
    screen[28][27] = 1;
    screen[29][27] = 1;
    screen[30][27] = 1;
    screen[31][27] = 1;
    screen[32][27] = 1;
    screen[33][27] = 1;
    screen[34][27] = 1;
    screen[35][27] = 1;
    screen[36][27] = 1;
    screen[37][27] = 1;


    while (isRunning)
    {
        HandleInput();

        DrawPixel();
        SDL_Flip(screen_surf);
    }

    return 0;
}
