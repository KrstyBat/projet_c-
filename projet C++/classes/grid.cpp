#include "grid.h"
#include <string>
#include <iostream>
#include <vector>


Grid::Grid()
{
    int i;
    for (i = 0; i < sizeY; i++)
    {
        grid.push_back(vector <int>(sizeX, new Case(0)));
    };
}

void Grid::print()
{
    int i;
    for (i = 0; i < grid.size(); i++)
    {
        printVector();
    };
    cout << endl;
}

void Grid::setValue(int value, int x, int y)
{
    if (x > 0 && x <= 4 && y > 0 && y <= 4)
        grid[y - 1][x - 1] = value;
}

void Grid::printVector()
{
    int i, j;
    for (i = 0; i < grid.size(); i++)
    {
        const vector<int> g = grid[i];
        for (j = 0; j < g.size(); j++)
        {
            int digits = getNumberDigits(g[j]);
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
            cout << "|" << before_space << g[j] << after_space;
        };
    };
    cout << "|" << endl;
}

int Grid::getNumberDigits(int i)
{
    int log = round(log10(i) + 1);
    if (isinf(log))
        return 1;
    return log;
}