#ifndef GRID_H
#define GRID_H

#include <vector>
#include <windows.h>
#include "case.h"

using namespace std;
	
class Grid : public GameObject
{
	int sizeX = 4;
	int sizeY = 4;
	vector<vector<Case*>> grid;

	HANDLE cmd;

	public:
		int score = 0;
		vector<SDL_Texture*> cases_texture;

		Grid(SDL_Renderer* renderer);
		~Grid();

		void selectRandomCases();

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

		void reset();

		void update() override;
		void draw(SDL_Renderer* renderer) override;
		void onSDLEvent(SDL_Event event) override;

		int getNumberDigits(int value);

	private:
		void loadCasesTextures(SDL_Renderer* renderer);
		
		void printVector(vector<Case*>& vect);

		void setConsoleColor(int value);
};

#endif