#include <vector>
#include <string>

using namespace std;

class Test
{
	vector<vector<int>> start;
	vector<vector<int>> result;

	vector<string> steps;

	int sizeX;
	int sizeY;

	int limit;

	public:
		Test(int sizeX, int sizeY);	

		void setTest(int id);

		void printGrid(int which);

		void printSteps();

		int lowerLimit();

		vector<vector<int>> getStartGrid();
		vector<vector<int>> getResultGrid();

	private:
		void printVector(vector<int>& vect);

		int getNumberDigits(int value);
};