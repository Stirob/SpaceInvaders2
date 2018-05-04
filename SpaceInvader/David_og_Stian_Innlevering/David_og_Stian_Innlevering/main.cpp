//David og Stian Innlevering CPP fil.


#include "Media.h"
int main(int argc, char* argv[])
{
	Media window;


	window.InitWindow();
	window.setRender();
	window.setAliens();
	window.SetScoreBoard();
	

	SDL_Event event;
	bool runningGame = true;

	//GameLoop
	while (runningGame) {
		window.setRenderCopy();
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym) {
				case SDLK_SPACE:
					//Shoot Projectile
					cout << "You shoot!" << endl;
					break;
				case SDLK_LEFT:
					cout << "You hit the left key" << endl;
					break;
				case SDLK_RIGHT:
					cout << "You hit the right key" << endl;
					break;
				case SDLK_ESCAPE:
					//Quit
					runningGame = false;
					break;
				case SDL_QUIT:
					//Quit
					runningGame = false;
					break;
				default:
					break;
				}
			}
		}
	}
	
	window.CloseImage();
	return 0;
}

