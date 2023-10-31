#include "GameObject.h"
#include "SDL.h"

/*GameObject::GameObject(SDL_Point points)
{

}*/

GameObject::GameObject(SDL_Rect r)
{
	rect = r;
}

void GameObject::draw(SDL_Renderer* renderer)
{
	SDL_RenderFillRect(renderer, &rect);
}