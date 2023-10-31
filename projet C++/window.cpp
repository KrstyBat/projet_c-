#include "window.h"

Window::Window(int w, int h)
{
	SDL_CreateWindowAndRenderer(w, h, 0, &win, &renderer);
}

Window::~Window()
{
	SDL_DestroyWindow(win);
}

void Window::gameLoop()
{
	bool run = true;
	while (run)
	{
		update();

		draw();
	}
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
	SDL_SetRenderDrawColor(renderer, white.r, white.g, white.b, SDL_ALPHA_OPAQUE);
	for (int i = 0; i < children.size(); i++)
	{
		children[i]->draw(renderer);
	}
	SDL_RenderPresent(renderer);
}