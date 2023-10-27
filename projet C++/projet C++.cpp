#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h>
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

/*int getNumberDigits(int i)
{
    int log = round(log10(i) + 1);
    if (isinf(log))
        return 1;
    return round(log10(i) + 1);
}

void printVector(vector<int> const& input)
{
	int i;
	for (i = 0; i < input.size(); i++)
	{
        int digits = getNumberDigits(input[i]);
        string before_space = "  ";
        string after_space = " ";
        if (digits == 2)
            before_space = " ";
        else if (digits == 3)
        {
            before_space = " ";
            after_space = "";
        }
        else if (digits == 4)
        {
            before_space = "";
            after_space = "";
        };
		cout << "|" << before_space << input[i] << after_space ;
	};
	cout << "|" << endl;
};

void printGrid(vector<vector <int>> const& input)
{
    int i;
    for (i = 0; i < input.size(); i++)
    {
        printVector(input[i]);
    };
	cout << endl;
};

void setValue(vector<vector <int>>& input, int value, int x, int y)
{
    if (x > 0 && x <= 4 && y > 0 && y <= 4)
        input[y - 1][x - 1] = value;
}*/

int main()
{
	//srand(time(NULL));
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> randomValue(1, 2);
    uniform_int_distribution<int> randomCase(1, 4);

	HANDLE hConsole;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    Grid* grid = new Grid();

    int val1, val2;
    val1 = rand() % 2 + 1;
    val2 = rand() % 2 + 1;
    val1 = val1 * 2;
    val2 = val2 * 2;

    int vX1 = rand() % 4 + 1;
    int vY1 = rand() % 4 + 1;
    int vX2 = rand() % 4 + 1;
    int vY2 = rand() % 4 + 1;

    while (vX1 == vX2 && vY1 == vY2)
    {
        vX1 = rand() % 4 + 1;
        vY1 = rand() % 4 + 1;
        vX2 = rand() % 4 + 1;
        vY2 = rand() % 4 + 1;
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
        cout << "score: " << grid->getScore() << endl;
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
                    //SetConsoleTextAttribute(hConsole, 10);
                    //cout << "Pressed Up" << endl;
                    grid->MoveToUp();
                    break;
                case KEY_DOWN: // Flèche bas
                    action = true;
                    //SetConsoleTextAttribute(hConsole, 20);
                    //cout << "Pressed Down" << endl;
                    grid->MoveToDown();
                    break;
                case KEY_LEFT: // Flèche gauche
                    action = true;
                    //SetConsoleTextAttribute(hConsole, 40);
                    //cout << "Pressed Left" << endl;
                    grid->MoveToLeft();
                    break;
                case KEY_RIGHT: // Flèche droite
                    action = true;
                    //SetConsoleTextAttribute(hConsole, 50);
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
                        srand(time(NULL));
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
    system("timeout /t 2 /NOBREAK");
    system("pause");

    delete grid;

    return 0;
}