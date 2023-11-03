#include "window.h"
#include <sstream>

#include <SDL_ttf.h>

Window::Window(int w, int h)
{
	SDL_CreateWindowAndRenderer(w, h, 0, &win, &renderer);
	if (win == NULL || renderer == NULL)
		return;

	font = TTF_OpenFont("fonts/font.ttf", 36);
	if (font == NULL) {
		cout << "ERROR: the font could not be loaded! SDL Error: " << SDL_GetError() << endl;
	}
	else {
		SDL_Color color = { 0, 0, 0 };
		SDL_Surface* surface = TTF_RenderText_Solid(font, "Score: ", color);
		score_tex = SDL_CreateTextureFromSurface(renderer, surface);
		SDL_FreeSurface(surface);
	}

	SDL_Surface* win_img = SDL_LoadBMP("img/win.bmp");
	if (win == NULL)
		cout << "ERROR: winning screen surface could not be loaded! SDL Error: " << SDL_GetError() << endl;
	else {
		win_screen = SDL_CreateTextureFromSurface(renderer, win_img);
		if (win_screen == NULL)
		{
			cout << "ERROR: winning screen texture can't be created! SDL Error: " << SDL_GetError() << endl;
			return;
		}
		SDL_FreeSurface(win_img);
	}
}

Window::~Window()
{
	if (win == NULL || renderer == NULL)
		return;
	SDL_DestroyTexture(score_tex);
	SDL_DestroyTexture(nb_score_tex);
	SDL_DestroyTexture(win_screen);
	SDL_DestroyWindow(win);
	SDL_DestroyRenderer(renderer);
	TTF_CloseFont(font);
}

void Window::gameLoop()
{
	bool run = true;
	while (run)
	{
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			/* handle your event here */

			for (int i = 0; i < children.size(); i++)
			{
				children[i]->onSDLEvent(event);
			}

		   //User requests quit
			if (event.type == SDL_QUIT || grid->isFull())
			{
				run = false;
				if (event.type == SDL_QUIT)
					want_to_quit = true;
			}
		}

		update();

		draw();
	}
}

bool Window::showEndingScreen()
{
	show_win_screen = true;

	while (show_win_screen)
	{
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_KEYDOWN)
			{
				switch (event.key.keysym.sym) {
				case SDLK_RETURN:
					show_win_screen = false;
					break;
				case SDLK_ESCAPE:
					show_win_screen = false;
					return false;
				default:
					break;

				}
			}
			else if (event.type == SDL_QUIT)
				return false;
		}

		draw();
	}
	return true;
}

void Window::addChild(GameObject* obj)
{
	children.push_back(obj);
}

void Window::update()
{
	for (int i = 0; i < children.size(); i++)
	{
		children[i]->update();
	}
	draw();
}

void Window::draw()
{
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, bg_color.r, bg_color.g, bg_color.b, bg_color.a);
	SDL_Rect d1 = { 14, 0, 100, 36 };
	SDL_RenderCopy(renderer, score_tex, NULL, &d1);
	SDL_Rect d2 = { 14+100, 0, 20+(10*grid->getNumberDigits(grid->score)-1), 36};
	generateNumberScore();
	SDL_RenderCopy(renderer, nb_score_tex, NULL, &d2);
	for (int i = 0; i < children.size(); i++)
	{
		children[i]->draw(renderer);
		SDL_SetRenderDrawColor(renderer, bg_color.r, bg_color.g, bg_color.b, bg_color.a);
	}
	if (show_win_screen && win_screen != NULL)
	{
		SDL_Rect dimensions = { 0, 0, 640, 480 };
		SDL_RenderCopy(renderer, win_screen, NULL, &dimensions);
	}
	SDL_RenderPresent(renderer);
}

void Window::setBackgroudColor(int r, int g, int b, int a)
{
	bg_color.r = r;
	bg_color.g = g;
	bg_color.b = b;
	bg_color.a = a;
}

SDL_Texture* Window::generateNumberScore()
{
	if (old_score != grid->score)
	{
		old_score = grid->score;
		if (nb_score_tex != NULL)
			SDL_DestroyTexture(nb_score_tex);
		ostringstream o;
		o << grid->score;
		string temp_score = o.str();
		const char* n_score = temp_score.c_str();

		SDL_Color color = { 0, 0, 0 };
		SDL_Surface* surface = TTF_RenderText_Solid(font, n_score, color);
		nb_score_tex = SDL_CreateTextureFromSurface(renderer, surface);
		SDL_FreeSurface(surface);
		return nb_score_tex;
	}
}