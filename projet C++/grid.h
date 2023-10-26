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
		~Grid();

		void print();

		void setValue(int x, int y, int value);

		void MoveToLeft();
		void MoveToRight();
		void MoveToUp();
		void MoveToDown();

	private:
		void printVector(vector<Case*>& vect);

		int getNumberDigits(int value);
};