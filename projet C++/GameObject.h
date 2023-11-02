#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "SDL.h"
#include "window.h"

class GameObject
{
	public:
		Window* parent;

		//SDL_Point* points;
		SDL_Rect rect;

		SDL_Color color = { 255, 255, 255, 255 };

		//GameObject(SDL_Point points);
		GameObject(SDL_Rect rect);
		GameObject();
		
		virtual void update();
		virtual void draw(SDL_Renderer* renderer);
		virtual void onSDLEvent(SDL_Event event);

		void setColor(int r, int g, int b, int a);
};
#endif