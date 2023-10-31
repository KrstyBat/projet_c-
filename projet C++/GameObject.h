#include "SDL.h"

class GameObject
{
	//SDL_Point* points;
	SDL_Rect rect;

	public:
		//GameObject(SDL_Point points);
		GameObject(SDL_Rect rect);
		
		void update();
		void draw(SDL_Renderer* renderer);
};