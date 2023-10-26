#include <iostream>

#include "grid.h"


Grid::Grid()
{
	int i;
	for (i = 0; i < sizeY; i++)
	{
		vector<Case*> v;
		int j;
		for (j = 0; j < sizeX; j++)
		{
			v.push_back(new Case());
		};
		grid.push_back(v);
	};
}

Grid::~Grid()
{
	int i, j;
	for (i = 0; i < sizeY; i++)
	{
		vector<Case*> c = grid[i];
		for (j = 0; j < sizeX; j++)
		{
			delete c[j];
		}
	}
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
		int digits = getNumberDigits(val);
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

int Grid::getNumberDigits(int value)
{
	if (value == 0)
	{
		return 1;
	}

	int digits = 0;
	while (value != 0)
	{
		value /= 10;
		digits++;
	}
	return digits;
}

void Grid::MoveToLeft()
{

}
void Grid::MoveToRight()
{

}
void Grid::MoveToUp()
{

}
void Grid::MoveToDown()
{

}