#include "Media.h"

Media::Media() 
{
	//Konstruktør
}

Media::~Media()
{
	//Destruktør
}

bool Media::InitWindow()
{
	// Init. SDL2
	SDL_Init(SDL_INIT_VIDEO); 
	//Lag Vinduet
	gameWindow = SDL_CreateWindow("Space Invaders", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 450, 400, SDL_WINDOW_SHOWN);

	//Sjekk om det er noe galt med vinduet
	if(gameWindow == nullptr)
	{
		cout << "Failed to create window: " << SDL_GetError() << endl;
		SDL_Quit();
		return EXIT_FAILURE;
	} 
	else 
	{	
		//Lag Renderer og sjekk om det er noe galt
		renderer = SDL_CreateRenderer(gameWindow, -1, SDL_RENDERER_ACCELERATED);
		if (renderer == nullptr)
		{
			cout << "Failed to create renderer: " << SDL_GetError() << endl;
			SDL_DestroyWindow(gameWindow); 
			SDL_Quit(); 
			return EXIT_FAILURE;
		} 
	}
	return 0;
}

void Media::setRender()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
}

void Media::CloseImage()
{
	SDL_DestroyWindow(gameWindow);
	SDL_Quit();
}

//Laster opp scoreboard bildet
bool Media::SetScoreBoard()
{

	Scoreboard = SDL_LoadBMP("Scoreboard.bmp");
	if (Scoreboard == nullptr)
	{
		cout << "Failed to load Scoreboard: " << SDL_GetError() << endl;
		SDL_DestroyRenderer(renderer); SDL_DestroyWindow(gameWindow);
		SDL_Quit();
		return EXIT_FAILURE;
	}
	//Last inn på grafikskortet
	drawable = SDL_CreateTextureFromSurface(renderer, Scoreboard);
	//Set koordinatene
	ScoreboardXY.h = 46;
	ScoreboardXY.w = 450;
	ScoreboardXY.x = 0;
	ScoreboardXY.y = 0;

	SDL_FreeSurface(Scoreboard);
	return 0;
}

//Laster opp aliens
bool Media::setAliens()
{
	Aliens = SDL_LoadBMP("Aliens.bmp");
	if (Aliens == nullptr)
	{
		cout << "Failed to load Aliens: " << SDL_GetError() << endl;
		SDL_DestroyRenderer(renderer); SDL_DestroyWindow(gameWindow);
		SDL_Quit();
		return EXIT_FAILURE;
	}
	//Last inn på grafikkortet
	drawable2 = SDL_CreateTextureFromSurface(renderer, Aliens);
	//Set koordinatene
	AlienXY.h = Aliens->h; // Samme bredde og høyde som surface
	AlienXY.w = Aliens->w;
	AlienXY.x = 0; // Endre disse for å "flytte" bildet i vinduet/renderer
	AlienXY.y = 66;

	SDL_FreeSurface(Aliens);
	return 0;
}

void Media::setRenderCopy() {
	SDL_RenderCopy(renderer, drawable, nullptr, &ScoreboardXY);
	SDL_RenderCopy(renderer, drawable2, nullptr, &AlienXY);
	SDL_RenderPresent(renderer);
	SDL_RenderClear(renderer);
}




/*void close(SDL_Window* w, SDL_Surface* m)
{
	SDL_FreeSurface(m);
	m = nullptr;
	SDL_DestroyWindow(w);
	w = nullptr;
	SDL_Quit();
	}*/