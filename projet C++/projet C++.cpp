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
    /*SDL_Window* win = SDL_CreateWindow("100000000000", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
    SDL_Renderer* render = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
    //SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Project SDL ", "OUI OUI", NULL);

    SDL_Color orange = { 255, 127, 40, 255 };

    SDL_SetRenderDrawColor(render, 192, 192, 192, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(render);
    SDL_SetRenderDrawColor(render, 128, 128, 128, SDL_ALPHA_OPAQUE);
    SDL_Rect rect_upper = { 0, 0, 640, 50 };
    SDL_Rect rect_game = { 0, 50, 400, 400 };
    SDL_RenderFillRect(render, &rect_upper);
    SDL_SetRenderDrawColor(render, 155, 155, 155, SDL_ALPHA_OPAQUE);
    SDL_RenderFillRect(render, &rect_game);
    SDL_RenderPresent(render);*/

    Window* game = new Window(WINDOW_WIDTH, WINDOW_HEIGHT);
    game->setBackgroudColor(255, 217, 176, 255);

    Grid* grid = new Grid(game->renderer);
    game->addChild(grid);
    //grid->setColor(255 - 150, 217 - 50, 176 - 50, 255);

    game->gameLoop();

    /*bool test = false;
    bool choose_test = false;

    cout << "Press T to enter Test Mode. Press any key to play normally." << endl;
    while (!choose_test)
        {
        if (_kbhit()) {
            choose_test = true;
            int key = _getch();
            cout << key << endl;
            switch (key)
            {
                case (KEY_LOWER_T):
                case (KEY_UPPER_T):
                    test = true;
                    break;
                default:
                    break;
            }
        }
    }

    int vX1, vY1;
    Test* tester = new Test(grid->getSizeX(), grid->getSizeY());
    if (!test)
    {
        int val1, val2;
        val1 = randomValue(gen);
        val2 = randomValue(gen);
        val1 = val1 * 2;
        val2 = val2 * 2;

        vX1 = randomCase(gen);
        vY1 = randomCase(gen);
        int vX2 = randomCase(gen);
        int vY2 = randomCase(gen);

        while (vX1 == vX2 && vY1 == vY2)
        {
            vX1 = randomCase(gen);
            vY1 = randomCase(gen);
            vX2 = randomCase(gen);
            vY2 = randomCase(gen);
        }

        grid->setValue(vX1, vY1, val1, true);
        grid->setValue(vX2, vY2, val1, true);
    }
    else
    {
        cout << "Please choose a test:" << endl;
        cout << "1- Going up test" << endl;
        cout << "2- Going down test" << endl;
        cout << "3- Going left test" << endl;
        cout << "4- Going right test" << endl;
        cout << "5- Fusion test (Left)" << endl;
        cout << "6- Fusion test (Right)" << endl;
        cout << "7- Fusion test (Up)" << endl;
        cout << "8- Fusion test (Down)" << endl;
        cout << "9- (Not) Fusion test" << endl;
        cout << "A- Digits test" << endl;
        cout << "B- Fusion test (4 in a row)" << endl;
        cout << "C- Move and fusion test" << endl;
        cout << "D- 2048 test" << endl;

        int choose = 0;

        while (choose <= 0)
        {
            if (_kbhit()) {
                choose = _getch();
                
                switch (choose)
                {
                    case (KEY_1):
                        choose = 1;
                        break;
                    case (KEY_2):
                        choose = 2;
                        break;
                    case (KEY_3):
                        choose = 3;
                        break;
                    case (KEY_4):
                        choose = 4;
                        break;
                    case (KEY_5):
                        choose = 5;
                        break;
                    case (KEY_6):
                        choose = 6;
                        break;
                    case (KEY_7):
                        choose = 7;
                        break;
                    case (KEY_8):
                        choose = 8;
                        break;
                    case (KEY_9):
                        choose = 9;
                        break;
                    case (KEY_UPPER_A):
                    case (KEY_LOWER_A):
                        choose = 10;
                        break;
                    case (KEY_UPPER_B):
                    case (KEY_LOWER_B):
                        choose = 11;
                        break;
                    case (KEY_UPPER_C):
                    case (KEY_LOWER_C):
                        choose = 12;
                        break;
                    case (KEY_UPPER_D):
                    case (KEY_LOWER_D):
                        choose = 13;
                        break;
                    default:
                        choose = 0;
                        break;
                }
            }
        }

        tester->setTest(choose);

        cout << "Starting grid" << endl;
        tester->printGrid(1);

        cout << "Result grid" << endl;
        tester->printGrid(2);

        cout << "Steps" << endl;
        tester->printSteps();

        system("pause");

        grid->setGrid(tester->getStartGrid());
    }

    //grid->print(); 
    bool action;
    bool ending = false;
    //system("pause");
    while (1)
    {
        system("cls");
        action = false;
        if (!test)
            cout << "Score: " << grid->getScore() << endl;
        else
        {
            cout << "Steps: ";
            tester->printSteps();
        }
        grid->print();
        if (grid->isFull())
        {
            ending = true;
            break;
        }
        while (true) {
            if (_kbhit()) {
                int key = _getch();
                switch (key)
                {
                case KEY_UP: // Flèche haut
                    action = true;
                    //cout << "Pressed Up" << endl;
                    grid->MoveToUp();
                    break;
                case KEY_DOWN: // Flèche bas
                    action = true;
                    //cout << "Pressed Down" << endl;
                    grid->MoveToDown();
                    break;
                case KEY_LEFT: // Flèche gauche
                    action = true;
                    //cout << "Pressed Left" << endl;
                    grid->MoveToLeft();
                    break;
                case KEY_RIGHT: // Flèche droite
                    action = true;
                    //cout << "Pressed Right" << endl;
                    grid->MoveToRight();
                    break;
                }
            }
            if (action == true) {
                grid->resetMergedCases();
                if (!test)
                {
                    if (!grid->isFull())
                    {
                        vX1 = randomCase(gen);
                        vY1 = randomCase(gen);
                        while (!grid->setValue(vX1, vY1, randomValue(gen) * 2, false))
                        {
                            vX1 = randomCase(gen);
                            vY1 = randomCase(gen);
                        }
                    }
                    else {
                        ending = true;
                    }
                }
                else {
                    if (tester->lowerLimit() == 0)
                    {
                        ending = true;
                        system("cls");
                        grid->print();
                    }
                }
                break;
            }
        }

        if (ending)
            break;
    }

    if (!test)
    {
        cout << "Game over!" << endl;
        cout << "Your score is " << grid->getScore() << "!" << endl;
        system("timeout 2 >> null");
        system("pause");
    }
    else
    {
        if (grid->compare(tester->getResultGrid()))
            cout << "Test réussi!";
        else
            cout << "Echec du test...";
    }*/

    delete grid;
    delete game;

    //SDL_DestroyWindow(win);
    SDL_Quit();

    return EXIT_SUCCESS;
}