#include <vector>
#include "case.h"

using namespace std;
	
class Grid
{
	int sizeX = 4;
	int sizeY = 4;
	vector<vector<Case*>> grid;

	public:
		Grid();

		void print();

		void setValue(int x, int y, int value);

	private:
		void printVector(vector<Case*>& vect);

		double getNumberDigits(int value);
};