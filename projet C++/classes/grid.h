#include <vector>

#include "case.h"

using namespace std;

class Grid
{
	int sizeX;
	int sizeY;
	vector <vector <int>> grid;

	public:
		Grid();

		void print();

		void setValue(int value, int x, int y);

	private:
		void printVector();

		int getNumberDigits(int i);
};