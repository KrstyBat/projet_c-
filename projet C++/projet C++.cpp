#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <windows.h>
#include "conio.h"

#include "classes/grid.h"

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
	HANDLE  hConsole;
    int i;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    //Grid* grid = new Grid();

    int valeur = rand()% 2 + 1;
    valeur = valeur * 2;

    int vX = rand() % 4 + 1;
    int vY = rand() % 4 + 1;

	SetConsoleTextAttribute(hConsole, 1);

    //vector <vector <int>> grille;
    //for (i = 0; i < 4; i++)
    //{
    //    grille.push_back(vector <int>(4, 0));
    //    
    //};

    //grid->setValue(valeur, vX, vY);
    //grid->setValue(2048, 1, 1);
    //grid->setValue(248, 2, 3);
    //grid->setValue(28, 4, 4);

    //grid->print(); 
    int action = 0;
    system("cls");
    while (1)
    {
        if (_kbhit()){
            int key = _getch();
            switch (key)
            {
                case KEY_UP: // Flèche haut
                    SetConsoleTextAttribute(hConsole, 1);
                    cout << "Pressed Up" << endl;
                    break;
                case KEY_DOWN: // Flèche bas
                    SetConsoleTextAttribute(hConsole, 2);
                    cout << "Pressed Down" << endl;
                    break;
                case KEY_LEFT: // Flèche gauche
                    SetConsoleTextAttribute(hConsole, 4);
                    cout << "Pressed Left" << endl;
                    break;
                case KEY_RIGHT: // Flèche droite
                    SetConsoleTextAttribute(hConsole, 5);
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

    //delete grid;

    return 0;
}