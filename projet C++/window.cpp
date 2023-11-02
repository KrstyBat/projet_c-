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

		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			/* handle your event here */

			for (int i = 0; i < children.size(); i++)
			{
				children[i]->onSDLEvent(event);
			}

		   //User requests quit
			if (event.type == SDL_QUIT || grid->isFull())
				run = false;
		}
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
	SDL_SetRenderDrawColor(renderer, bg_color.r, bg_color.g, bg_color.b, bg_color.a);
	for (int i = 0; i < children.size(); i++)
	{
		children[i]->draw(renderer);
		SDL_SetRenderDrawColor(renderer, bg_color.r, bg_color.g, bg_color.b, bg_color.a);
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