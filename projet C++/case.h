#include <iostream>
#include <vector>
#include "GameObject.h"

using namespace std;

class Case : public GameObject
{
	int value;
	bool merged = false;

	vector<SDL_Texture*> textures;

	public:

		int x = 0;
		int y = 0;

		Case(vector<SDL_Texture*> t);

		bool setValue(int val, bool force);
		
		int getValue();

		void setMerged(bool merge);

		bool getMerged();

		int upgrade();

		void kill();

		void draw(SDL_Renderer* renderer) override;
};