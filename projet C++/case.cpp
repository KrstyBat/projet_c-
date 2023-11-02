#include "case.h"
#include <cmath>

Case::Case(vector<SDL_Texture*> t)
{
	value = 0;
	textures = t;
}

bool Case::setValue(int val, bool force)
{
	if (!force && value != 0)
		return false;
	value = val;
	return true;
}

int Case::getValue()
{
	return value;
}

void Case::setMerged(bool merge)
{
	merged = merge;
}

bool Case::getMerged()
{
	return merged;
}

int Case::upgrade()
{
	value *= 2;
	return value;
}

void Case::kill()
{
	value = 0;
}

void Case::draw(SDL_Renderer* renderer)
{
	//GameObject::draw(renderer);
	//cout << value << endl;
	if (value > 0)
	{
		int index = static_cast<int>(log2(value))-1;
		//cout << value << " ||| " << index << endl;
		//cout << x << " --- " << y << endl;
		//cout << textures.size() << endl;
		SDL_Rect dimensions = { 120 + (50 * (2 * x)), 50 + (50 * (2 * y)),100,100 };
		SDL_RenderCopy(renderer, textures[index], NULL, &dimensions);
	}
}