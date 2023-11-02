#ifndef GAME_H
#define GAME_H

#include "SDL.h"
#include <vector>
#include "GameObject.h"
#include "grid.h"

using namespace std;

class Window
{
	SDL_Color bg_color = { 255, 255, 255, 255 };

	vector<GameObject*> children;

	public:
		SDL_Window* win;
		SDL_Renderer* renderer;

		Grid* grid;

		Window(int w, int h);
		~Window();

		void gameLoop();

		void addChild(GameObject* obj);

		void setBackgroudColor(int r, int g, int b, int a);

	private:
		void update();
		void draw();
};

#endif