#include "SDL.h"
#include <vector>
#include "GameObject.h"

using namespace std;

class Window
{
	SDL_Window* win;
	SDL_Renderer* renderer;

	SDL_Color white = { 255, 255, 255, 255 };

	vector<GameObject*> children;

	public:
		Window(int w, int h);
		~Window();

		void gameLoop();

		void addChild(GameObject* obj);

	private:
		void update();
		void draw();
};