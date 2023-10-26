#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <windows.h>
#include "conio.h"

//#include "classes/grid.h"
#include "test.h"
#include "grid.h"

#define KEY_ENTER 13
#define KEY_SPACE 32

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
	srand(time(NULL));
	HANDLE hConsole;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    Grid* grid = new Grid();
    Test* test = new Test();

    int valeur = rand()% 2 + 1;
    valeur = valeur * 2;

    int vX = rand() % 4 + 1;
    int vY = rand() % 4 + 1;

    test->add(valeur);
    test->add(vX);
    test->add(vY);
    cout << test->getNumber() << endl;

	SetConsoleTextAttribute(hConsole, 1);

    //vector <vector <int>> grille;
    //for (i = 0; i < 4; i++)
    //{
    //    grille.push_back(vector <int>(4, 0));
    //    
    //};

    grid->setValue(vX, vY, valeur);
    grid->setValue(1, 1, 2048);
    grid->setValue(2, 3, 248);
    grid->setValue(2, 2, 24);

    grid->print(); 
    int action;
    //system("pause");
    while (1)
    {
        system("cls");
        action = 0;
        grid->print();
        while (1) {
            if (_kbhit()) {
                int key = _getch();
                switch (key)
                {
                case KEY_UP: // Flèche haut
                    action = 1;
                    SetConsoleTextAttribute(hConsole, 10);
                    cout << "Pressed Up" << endl;
                    grid->MoveToUp();
                    break;
                case KEY_DOWN: // Flèche bas
                    action = 1;
                    SetConsoleTextAttribute(hConsole, 20);
                    cout << "Pressed Down" << endl;
                    break;
                case KEY_LEFT: // Flèche gauche
                    action = 1;
                    SetConsoleTextAttribute(hConsole, 40);
                    cout << "Pressed Left" << endl;
                    grid->MoveToLeft();
                    break;
                case KEY_RIGHT: // Flèche droite
                    action = 1;
                    SetConsoleTextAttribute(hConsole, 50);
                    cout << "Pressed Right" << endl;
                    break;

                case KEY_SPACE:
                case KEY_ENTER: //Entrée ou Espace: démine une case
                    action = 1;
                    SetConsoleTextAttribute(hConsole, 15);
                    cout << "Pressed Space or Enter" << endl;
                    break;
                }
            }
            if (action == 1) {
                break;
            }
        }
    }

    delete grid;

    return 0;
}