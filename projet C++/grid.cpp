#include <iostream>
#include <sstream>
#include <windows.h>
#include <random>
#include "grid.h"




Grid::Grid(SDL_Renderer* renderer)
{
	rect = {120, 50, 400, 400};
	color = { 255-50, 217-50, 176-50, 255 };

	loadCasesTextures(renderer);

	int i;
	for (i = 0; i < sizeY; i++)
	{
		vector<Case*> v;
		int j;
		for (j = 0; j < sizeX; j++)
		{
			v.push_back(new Case(cases_texture));
		};
		grid.push_back(v);
	};

	selectRandomCases();

	cmd = GetStdHandle(STD_OUTPUT_HANDLE);
}

void Grid::selectRandomCases()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> randomValue(1, 2);
	uniform_int_distribution<int> randomCase(1, 4);

	int val = randomValue(gen)*2;
	int rX = randomCase(gen);
	int rY = randomCase(gen);
	while (!setValue(rX, rY, val, false))
	{
		rX = randomCase(gen);
		rY = randomCase(gen);
	}
	val = randomValue(gen)*2;
	rX = randomCase(gen);
	rY = randomCase(gen);
	while (!setValue(rX, rY, val, false))
	{
		rX = randomCase(gen);
		rY = randomCase(gen);
	}
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

	for (int i = 0; i < cases_texture.size(); i++)
	{
		SDL_DestroyTexture(cases_texture[i]);
	}
}

bool Grid::setValue(int x, int y, int value, bool force)
{
	return grid[y - 1][x - 1]->setValue(value, force);
}

int Grid::getScore()
{
	return score;
}

int Grid::getSizeX()
{
	return sizeX;
}

int Grid::getSizeY()
{
	return sizeY;
}

void Grid::setGrid(vector<vector<int>> simple_grid)
{
	for (int i = 0; i < sizeY; i++)
	{
		for (int j = 0; j < sizeX; j++)
		{
			setValue(j+1, i+1, simple_grid[i][j], true);
		}
	}
}

bool Grid::isFull()
{
	bool is_full = true;
	for (int i = 0; i < sizeY; i++)
	{
		for (int j = 0; j < sizeX; j++)
		{
			if (grid[j][i]->getValue() == 0)
			{
				is_full = false;
				break;
			}
		}
		if (!is_full)
			break;
	}
	return is_full;
}

void Grid::setConsoleColor(int value)
{
	int hex = 0;
	switch (value)
	{
		case 2:
			hex = 7;
			break;
		case 4:
			hex = 8;
			break;
		case 8:
			hex = 14;
			break;
		case 16:
			hex = 6;
			break;
		case 32:
			hex = 5;
			break;
		case 64:
			hex = 9;
			break;
		case 128:
			hex = 1;
			break;
		case 256:
			hex = 10;
			break;
		case 512:
			hex = 2;
			break;
		case 1024:
			hex = 11;
			break;
		case 2048:
			hex = 224;
			break;
		case 4096:
			hex = 160;
			break;
		case 8192:
			hex = 192;
			break;
		default:
			hex = 15;
			break;
	}
	SetConsoleTextAttribute(cmd, hex);
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
		cout << "|" << before_space;
		setConsoleColor(val);
		cout << val << after_space;
		SetConsoleTextAttribute(cmd, 15);
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
		for (int row = 0; row < sizeY; row++) {
			int cur_col = col;
			while (cur_col >= 0)
			{
				if (grid[row][cur_col]->getValue() != 0)
				{
					if (cur_col-1 < 0) {
						break;
					}

					if (grid[row][cur_col - 1]->getValue() == 0) {
						grid[row][cur_col - 1]->setValue(grid[row][cur_col]->getValue(), true);
						grid[row][cur_col]->kill();
					}
					else if (grid[row][cur_col - 1]->getValue() == grid[row][cur_col]->getValue() && !grid[row][cur_col - 1]->getMerged()) {
						score += grid[row][cur_col - 1]->upgrade();
						grid[row][cur_col - 1]->setMerged(true);
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
	for (int col = sizeX-1; col >= 0; col--) {
		for (int row = 0; row < sizeY; row++) {
			int cur_col = col;
			while (cur_col <= sizeX-1)
			{
				if (grid[row][cur_col]->getValue() != 0)
				{
					if (cur_col + 1 > sizeX-1) {
						break;
					}

					if (grid[row][cur_col + 1]->getValue() == 0) {
						grid[row][cur_col + 1]->setValue(grid[row][cur_col]->getValue(), true);
						grid[row][cur_col]->kill();
					}
					else if (grid[row][cur_col + 1]->getValue() == grid[row][cur_col]->getValue() && !grid[row][cur_col + 1]->getMerged()) {
						score += grid[row][cur_col + 1]->upgrade();
						grid[row][cur_col + 1]->setMerged(true);
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
						grid[cur_row - 1][col]->setValue(grid[cur_row][col]->getValue(), true);
						grid[cur_row][col]->kill();
					}
					else if (grid[cur_row - 1][col]->getValue() == grid[cur_row][col]->getValue() && !grid[cur_row - 1][col]->getMerged())
					{
						score += grid[cur_row - 1][col]->upgrade();
						grid[cur_row - 1][col]->setMerged(true);
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
					if (cur_row + 1 > sizeY - 1) {
						break;
					}

					if (grid[cur_row + 1][col]->getValue() == 0)
					{
						grid[cur_row + 1][col]->setValue(grid[cur_row][col]->getValue(), true);
						grid[cur_row][col]->kill();
					}
					else if (grid[cur_row + 1][col]->getValue() == grid[cur_row][col]->getValue() && !grid[cur_row + 1][col]->getMerged())
					{
						score += grid[cur_row + 1][col]->upgrade();
						grid[cur_row + 1][col]->setMerged(true);
						grid[cur_row][col]->kill();
					}
				}
				cur_row += 1;
			}
		}
	}
}

void Grid::resetMergedCases()
{
	for (int row = 0; row < sizeY; row++) {
		for (int col = 0; col < sizeX; col++) {
			if (grid[row][col]->getMerged()) {
				grid[row][col]->setMerged(false);
			}
		}
	}
}

bool Grid::compare(vector<vector<int>> simple_grid)
{
	for (int i = 0; i < sizeY; i++)
	{
		for (int j = 0; j < sizeX; j++)
		{
			if (grid[i][j]->getValue() != simple_grid[i][j])
				return false;
		}
	}
	return true;
}

void Grid::loadCasesTextures(SDL_Renderer* renderer)
{
	string path_before = "img/";
	string path_after = ".bmp";
	for (int i = 2; i <= 8192; i*=2)
	{
		cout << i << endl;
		ostringstream o;
		o << path_before << i << path_after;
		string s = o.str();
		const char* path = s.c_str();

		cout << path << endl;

		SDL_Surface* surf = SDL_LoadBMP(path);

		if (surf == NULL)
		{
			ostringstream error_msg;
			error_msg << "ERROR: Sprite for Case " << i << " is not loaded!";
			string yes = error_msg.str();
			cout << yes << endl;
		}

		cases_texture.push_back(SDL_CreateTextureFromSurface(renderer, surf));

		SDL_FreeSurface(surf);
	}
}

void Grid::update()
{
	GameObject::update();
	for (int i = 0; i < sizeY; i++)
	{
		vector<Case*> c = grid[i];
		for (int j = 0; j < sizeX; j++)
		{
			c[j]->x = j;
			c[j]->y = i;
		}
	}
}

void Grid::draw(SDL_Renderer* renderer)
{
	GameObject::draw(renderer);
	//cout << "O SHIT O FUCK <<" << endl;
	for (int i = 0; i < sizeY; i++)
	{
		vector<Case*> c = grid[i];
		for (int j = 0; j < sizeX; j++)
		{
			c[j]->draw(renderer);
		}
	}
}

void Grid::onSDLEvent(SDL_Event event)
{
	bool pressed = false;
	if (event.type == SDL_KEYDOWN)
	{
		switch (event.key.keysym.sym) {
			case SDLK_LEFT:
				pressed = true;
				MoveToLeft();
				break;
			case SDLK_RIGHT:
				pressed = true;
				MoveToRight();
				break;
			case SDLK_UP:
				pressed = true;
				MoveToUp();
				break;
			case SDLK_DOWN:
				pressed = true;
				MoveToDown();
				break;
			case SDLK_SPACE:
				print();
			default:
				break;
			}
	}

	if (pressed) {
		resetMergedCases();
		if (!isFull())
		{
			random_device rd;
			mt19937 gen(rd());
			uniform_int_distribution<int> randomValue(1, 2);
			uniform_int_distribution<int> randomCase(1, 4);

			int x1 = randomCase(gen);
			int y1 = randomCase(gen);
			while (!setValue(x1, y1, randomValue(gen) * 2, false))
			{
				x1 = randomCase(gen);
				y1 = randomCase(gen);
			}
		}
		else {
			//parent->run = false;
		}
	}
}