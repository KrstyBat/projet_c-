#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include <conio.h>

#include <SDL.h>

#include "window.h"

#include "grid.h"

#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_UP 72
#define KEY_DOWN 80

#define KEY_LOWER_T 116
#define KEY_UPPER_T 84

#define KEY_1 49
#define KEY_2 50
#define KEY_3 51
#define KEY_4 52
#define KEY_5 53
#define KEY_6 54
#define KEY_7 55
#define KEY_8 56
#define KEY_9 57
#define KEY_LOWER_A 97
#define KEY_UPPER_A 65
#define KEY_LOWER_B 98
#define KEY_UPPER_B 66
#define KEY_LOWER_C 99
#define KEY_UPPER_C 67
#define KEY_LOWER_D 100
#define KEY_UPPER_D 68

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

using namespace std;

// ┌  ┐  ┘  └
// ─  │
// ┴  ┤  ├  ┬  ┼

int main(int argc, char* argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
        return EXIT_FAILURE;

    Window* game = new Window(WINDOW_WIDTH, WINDOW_HEIGHT);
    game->setBackgroudColor(255, 217, 176, 255);

    Grid* grid = new Grid(game->renderer);
    game->addChild(grid);
    game->grid = grid;

    game->gameLoop();

    //game->showEndingScreen();

    delete grid;
    delete game;

    SDL_Quit();

    return EXIT_SUCCESS;
}