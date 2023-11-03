#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include <conio.h>

#include <SDL.h>
#include <SDL_ttf.h>

#include "window.h"

#include "grid.h"

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

using namespace std;

// ┌  ┐  ┘  └
// ─  │
// ┴  ┤  ├  ┬  ┼

int main(int argc, char* argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        cout << "FATAL ERROR: SDL could not be initialized! SDL Error: " << SDL_GetError() << endl;
        return EXIT_FAILURE;
    }
    if (TTF_Init() < 0) {
        cout << "FATAL ERROR: SDL_ttf could not be initialized! SDL Error: " << SDL_GetError() << endl;
        SDL_Quit();
        return EXIT_FAILURE;
    }
    //if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) < 0) {
    //    cout << "ERROR: SDL_mixer could not be initialized! SDL Error: " << Mix_GetError() << endl;
    //}

    Window* game = new Window(WINDOW_WIDTH, WINDOW_HEIGHT);
    if (game->win == NULL || game->renderer == NULL)
    {
        cout << "FATAL ERROR: The SDL window and/or renderer could not be created! SDL Error: " << SDL_GetError() << endl;

        delete game;
        SDL_Quit();
        return EXIT_FAILURE;
    }
    game->setBackgroudColor(255, 217, 176, 255);
    SDL_SetWindowTitle(game->win, "C++ 2048");

    SDL_Surface* icon = SDL_LoadBMP("img/2048.bmp");
    if (icon == NULL)
    {
        cout << "ERROR: Could not load icon! SDL Error: " << SDL_GetError() << endl;
    }
    else {
        SDL_SetWindowIcon(game->win, icon);
        SDL_FreeSurface(icon);
    }

    //Mix_Music* bgm = Mix_LoadMUS("aud/test.mp3");

    Grid* grid = new Grid(game->renderer);
    game->addChild(grid);
    game->grid = grid;

    bool run = true;

    while (run)
    {
        game->gameLoop();

        if (!game->want_to_quit)
        {
            if (!game->showEndingScreen())
                run = false;
        }
        else
            run = false;

        grid->reset();
    }

    delete grid;
    delete game;
    //Mix_FreeMusic(bgm);
       
    //Mix_CloseAudio();
    SDL_Quit();

    return EXIT_SUCCESS;
}