#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

// ┌  ┐  ┘  └
// ─  │
// ┴  ┤  ├  ┬  ┼

void printVector(vector<int> const& input)
{
	int i;
	for (i = 0; i < input.size(); i++)
	{
		cout << "|" << input[i] ;
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
}

int main()
{
	srand(time(NULL));
    int i;

    int valeur = rand()% 2 + 1;
    valeur = valeur * 2;

    int vX = rand() % 4 + 1;
    int vY = rand() % 4 + 1;

    vector <vector <int>> grille;
    for (i = 0; i < 4; i++)
    {
        grille.push_back(vector <int>(4, 0));
        
    };

    // setValue(grille, valeur, y, x);
    setValue(grille, valeur, vX, vY);

    printGrid(grille); 

    return 0;
}