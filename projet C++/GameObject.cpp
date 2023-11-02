#include "GameObject.h"
#include "SDL.h"

/*GameObject::GameObject(SDL_Point points)
{

}*/

GameObject::GameObject(SDL_Rect r)
{
	rect = r;
}

GameObject::GameObject()
{
	SDL_Rect r = { 0, 0, 100, 100 };
	rect = r;
}

void GameObject::update()
{

}

void GameObject::draw(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
	SDL_RenderFillRect(renderer, &rect);
}

void GameObject::onSDLEvent(SDL_Event event)
{

}

void GameObject::setColor(int r, int g, int b, int a)
{
	color.r = r;
	color.g = g;
	color.b = b;
	color.a = a;
}