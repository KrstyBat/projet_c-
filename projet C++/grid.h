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
	int score = 0;

	HANDLE cmd;

	public:
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

		void update() override;
		void draw(SDL_Renderer* renderer) override;
		void onSDLEvent(SDL_Event event) override;

	private:
		void loadCasesTextures(SDL_Renderer* renderer);
		
		void printVector(vector<Case*>& vect);

		int getNumberDigits(int value);

		void setConsoleColor(int value);
};

#endif