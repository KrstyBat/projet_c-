#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include <random>
#include <conio.h>

#include "grid.h"

#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_UP 72
#define KEY_DOWN 80

using namespace std;

// ┌  ┐  ┘  └
// ─  │
// ┴  ┤  ├  ┬  ┼

int main()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> randomValue(1, 2);
    uniform_int_distribution<int> randomCase(1, 4);

    Grid* grid = new Grid();

    int val1, val2;
    val1 = randomValue(gen);
    val2 = randomValue(gen);
    val1 = val1 * 2;
    val2 = val2 * 2;

    int vX1 = randomCase(gen);
    int vY1 = randomCase(gen);
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

    grid->print(); 
    bool action;
    bool ending = false;
    while (1)
    {
        system("cls");
        action = false;
        cout << "Score: " << grid->getScore() << endl;
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
                if (!grid->isFull())
                {
                    vX1 = randomCase(gen);
                    vY1 = randomCase(gen);
                    while (!grid->setValue(vX1, vY1, randomValue(gen) * 2, false))
                    {
                        vX1 = randomCase(gen);
                        vY1 = randomCase(gen);
                    }
                } else {
                    ending = true;
                }
                break;
            }
        }

        if (ending)
            break;
    }

    cout << "Game over!" << endl;
    cout << "Your score is " << grid->getScore() << "!" << endl;
    system("timeout /t 2 /NOBREAK >> null");
    system("pause");

    delete grid;

    return 0;
}