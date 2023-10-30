#include <iostream>
#include "test.h"

using namespace std;

// 0| 1| 2| 3
// 4| 5| 6| 7
// 8| 9|10|11
//12|13|14|15

Test::Test(int sX, int sY)
{
	sizeX = sX;
	sizeY = sY;
	for (int i = 0; i < sizeY; i++)
	{
		vector<int> v;
		for (int j = 0; j < sizeX; j++)
		{
			v.push_back(0);
		};
		start.push_back(v);

		vector<int> v2;
		for (int j = 0; j < sizeX; j++)
		{
			v2.push_back(0);
		};
		result.push_back(v2);
	};

	limit = 0;
};

void Test::setTest(int id)
{
	switch(id)
	{
		case 1:
			start[1][0] = 2;
			start[3][1] = 4;
			start[0][2] = 2048;
			start[2][3] = 16;

			result[0][0] = 2;
			result[0][1] = 4;
			result[0][2] = 2048;
			result[0][3] = 16;

			steps.push_back("Up");
			break;
		case 2:
			start[1][0] = 2;
			start[3][1] = 4;
			start[0][2] = 2048;
			start[2][3] = 16;

			result[3][0] = 2;
			result[3][1] = 4;
			result[3][2] = 2048;
			result[3][3] = 16;

			steps.push_back("Down");
			break;
		case 3:
			start[1][0] = 2;
			start[3][1] = 4;
			start[0][2] = 2048;
			start[2][3] = 16;

			result[1][0] = 2;
			result[3][0] = 4;
			result[0][0] = 2048;
			result[2][0] = 16;

			steps.push_back("Left");
			break;
		case 4:
			start[1][0] = 2;
			start[3][1] = 4;
			start[0][2] = 2048;
			start[2][3] = 16;

			result[1][3] = 2;
			result[3][3] = 4;
			result[0][3] = 2048;
			result[2][3] = 16;

			steps.push_back("Right");
			break;
		case 5:
			start[1][1] = 2;
			start[1][3] = 2;

			result[1][0] = 4;

			steps.push_back("Left");
			break;
		case 6:
			start[1][1] = 2;
			start[1][3] = 2;
			start[3][0] = 4;
			start[3][1] = 4;

			result[1][3] = 4;
			result[3][3] = 8;

			steps.push_back("Right");
			break;
		case 7:
			start[1][1] = 8;
			start[3][1] = 8;

			result[0][1] = 16;

			steps.push_back("Up");
			break;
		case 8:
			start[1][1] = 8;
			start[3][1] = 8;

			result[3][1] = 16;

			steps.push_back("Down");
			break;
		case 9:
			start[0][0] = 2;
			start[0][1] = 4;
			start[0][3] = 2;
			start[1][0] = 8;
			start[1][3] = 16;
			start[2][1] = 32;
			start[3][0] = 32;

			result[0][3] = 2;
			result[0][2] = 4;
			result[0][1] = 2;
			result[1][2] = 8;
			result[1][3] = 16;
			result[2][3] = 32;
			result[3][3] = 32;

			steps.push_back("Right");
			break;
		case 10:
			start[3][0] = 8;
			start[0][0] = 8;
			start[3][1] = 64;
			start[0][1] = 64;
			start[3][2] = 512;
			start[0][2] = 512;
			start[3][3] = 2048;
			start[0][3] = 2048;

			result[0][0] = 16;
			result[0][1] = 128;
			result[0][2] = 1024;
			result[0][3] = 4096;

			steps.push_back("Up");
			break;
		case 11:
			start[0][0] = 4;
			start[0][1] = 4;
			start[0][2] = 4;
			start[0][3] = 4;

			result[0][0] = 16;

			steps.push_back("Left");
			steps.push_back("Left");
			break;
		case 12:
			start[1][2] = 2;
			start[3][1] = 2;

			result[3][3] = 4;

			steps.push_back("Down");
			steps.push_back("Right");
			break;
		case 13:
			start[0][0] = 1024;
			start[1][3] = 512;
			start[3][2] = 512;

			result[3][0] = 2048;

			steps.push_back("Left");
			steps.push_back("Down");
			steps.push_back("Down");
			break;
	}

	limit = steps.size();
}

// 1- start
// 2- result
void Test::printGrid(int which)
{
	if (which == 1)
	{
		for (int i = 0; i < sizeY; i++)
		{
			printVector(start[i]);
		};
	}
	else {
		for (int i = 0; i < sizeY; i++)
		{
			printVector(result[i]);
		};
	}
}

void Test::printVector(vector<int>&vect)
{
	int i;
	for (i = 0; i < sizeX; i++)
	{
		int val = vect[i];
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

void Test::printSteps()
{
	for (int i = steps.size()-limit; i < steps.size(); i++)
	{
		cout << steps[i];
		if (i+1 != steps.size())
			cout << " -> ";
	}
	cout << endl;
}

int Test::getNumberDigits(int value)
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

vector<vector<int>> Test::getStartGrid()
{
	return start;
}

vector<vector<int>> Test::getResultGrid()
{
	return result;
}

int Test::lowerLimit()
{
	limit -= 1;
	return limit;
}

/*int Test::add(int val)
{
	num += val;
	return num; 
};

int Test::getNumber()
{
	return num;
}*/