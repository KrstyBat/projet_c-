#include <iostream>

#include "grid.h"
#include "case.h"

Grid::Grid()
{
	int i;
	for (i = 0; i < sizeY; i++)
	{
		vector<Case*> v(sizeX, new Case());
		grid.push_back(v);
	};
}

void Grid::setValue(int x, int y, int value)
{
	grid[y - 1][x - 1]->setValue(value);
}

void Grid::print()
{
	int i;
	for (i = 0; i < sizeY; i++)
	{
		printVector(grid[i]);
	};
}

void Grid::printVector(vector<Case*>& vect)
{
	int i;
	for (i = 0; i < sizeX; i++)
	{
		int val = vect[i]->getValue();
		double digits = getNumberDigits(val);
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
		cout << "|" << before_space << val << after_space;
	};
	cout << "|" << endl;
}

double Grid::getNumberDigits(int value)
{
	double log = round(log10(value) + 1);
	if (isinf(log))
		return 1;
	return log;
}