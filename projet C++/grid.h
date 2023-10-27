#include <vector>
#include <windows.h>
#include "case.h"

using namespace std;
	
class Grid
{
	int sizeX = 4;
	int sizeY = 4;
	vector<vector<Case*>> grid;
	int score = 0;

	HANDLE cmd;

	public:
		Grid();
		~Grid();

		void print();

		bool setValue(int x, int y, int value, bool force);

		int getScore();

		void setConsoleColor(int value);

		bool isFull();

		void MoveToLeft();
		void MoveToRight();
		void MoveToUp();
		void MoveToDown();

	private:
		void printVector(vector<Case*>& vect);

		int getNumberDigits(int value);
};