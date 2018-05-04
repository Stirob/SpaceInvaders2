#ifndef Media_H
#define MEDIA_H

#include <iostream>
#include <SDL.h>
using namespace std;

class Media {
private:
	SDL_Window* gameWindow = nullptr;
	SDL_Renderer* renderer = nullptr;
	SDL_Surface* Scoreboard = nullptr;
	SDL_Surface* Aliens = nullptr;
	SDL_Texture* drawable;
	SDL_Texture* drawable2;
	SDL_Texture* drawable3;
	SDL_Rect ScoreboardXY;
	SDL_Rect AlienXY;
	SDL_Event event;

public: 
	Media();
	~Media();


	bool Media::InitWindow();
	void Media::setRender();
	void Media::CloseImage();
	bool Media::SetScoreBoard();
	bool Media::setAliens();
	void Media::setRenderCopy();

};
#endif 
//MEDIA_H