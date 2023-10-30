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

		int getSizeX();
		int getSizeY();

		void setGrid(vector<vector<int>> simple_grid);

		bool isFull();

		bool compare(vector<vector<int>> simple_grid);

		void MoveToLeft();
		void MoveToRight();
		void MoveToUp();
		void MoveToDown();

		void resetMergedCases();

	private:
		void printVector(vector<Case*>& vect);

		int getNumberDigits(int value);

		void setConsoleColor(int value);
};