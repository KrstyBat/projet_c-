#ifndef GAME_H
#define GAME_H

#include "SDL.h"
#include <SDL_ttf.h>
#include <vector>
#include "GameObject.h"
#include "grid.h"

using namespace std;

class Window
{
	SDL_Color bg_color = { 255, 255, 255, 255 };

	TTF_Font* font;
	SDL_Texture* score_tex;
	SDL_Texture* nb_score_tex;

	SDL_Texture* win_screen;

	bool show_win_screen = false;

	vector<GameObject*> children;

	int score;

	public:
		SDL_Window* win;
		SDL_Renderer* renderer;

		Grid* grid;

		bool want_to_quit = false;

		Window(int w, int h);
		~Window();

		void gameLoop();

		bool showEndingScreen();

		void addChild(GameObject* obj);

		void setBackgroudColor(int r, int g, int b, int a);

	private:
		void update();
		void draw();

		int old_score = -1;
		SDL_Texture* generateNumberScore();
};

#endif