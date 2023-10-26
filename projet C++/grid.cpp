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
	for (int col = 0; col < sizeX; col++) {
		for (int row = 1; row < sizeY; row++) {
			int cur_col = col;
			while (cur_col >= 1)
			{
				if (grid[row][cur_col]->getValue() != 0)
				{
					if (cur_col-1 < 0) {
						break;
					}

					if (grid[row][cur_col - 1]->getValue() == 0) {
						grid[row][cur_col - 1]->setValue(grid[row][cur_col]->getValue());
						grid[row][cur_col]->kill();
					}
					else if (grid[row][cur_col]->getValue() == grid[row][cur_col]->getValue()) {
						grid[row][cur_col - 1]->upgrade();
						grid[row][cur_col]->kill();
					}
				}
				cur_col -= 1;
			}
		}
	}
}
void Grid::MoveToRight()
{
	for (int col = sizeX-1; col > 0; col--) {
		for (int row = 1; row < sizeY; row++) {
			int cur_col = col;
			while (cur_col <= sizeX-1)
			{
				if (grid[row][cur_col]->getValue() != 0)
				{
					if (cur_col + 1 > sizeX-1) {
						break;
					}

					if (grid[row][cur_col + 1]->getValue() == 0) {
						grid[row][cur_col + 1]->setValue(grid[row][cur_col]->getValue());
						grid[row][cur_col]->kill();
					}
					else if (grid[row][cur_col]->getValue() == grid[row][cur_col]->getValue()) {
						grid[row][cur_col + 1]->upgrade();
						grid[row][cur_col]->kill();
					}
				}
				cur_col += 1;
			}
		}
	}
}
void Grid::MoveToUp() {
	for (int col = 0; col < sizeX; col++) {
		for (int row = 1; row < sizeY; row++) {
			int cur_row = row;
			while (cur_row >= 1)
			{
				if (grid[cur_row][col]->getValue() != 0) {
					if (cur_row - 1 < 0) {
						break;
					}

					if (grid[cur_row - 1][col]->getValue() == 0)
					{
						grid[cur_row - 1][col]->setValue(grid[cur_row][col]->getValue());
						grid[cur_row][col]->kill();
					}
					else if (grid[cur_row - 1][col]->getValue() == grid[cur_row][col]->getValue())
					{
						grid[cur_row - 1][col]->upgrade();
						grid[cur_row][col]->kill();
					}
				}
				cur_row -= 1;
			}
		}
	}
}
void Grid::MoveToDown()
{
	for (int col = 0; col < sizeX; col++) {
		for (int row = 1; row >= 0; row--) {
			int cur_row = row;
			while (cur_row <= sizeY-1)
			{
				if (grid[cur_row][col]->getValue() != 0) {
					if (cur_row + 1 < 0) {
						break;
					}

					if (grid[cur_row + 1][col]->getValue() == 0)
					{
						grid[cur_row + 1][col]->setValue(grid[cur_row][col]->getValue());
						grid[cur_row][col]->kill();
					}
					else if (grid[cur_row + 1][col]->getValue() == grid[cur_row][col]->getValue())
					{
						grid[cur_row + 1][col]->upgrade();
						grid[cur_row][col]->kill();
					}
				}
				cur_row += 1;
			}
		}
	}
}