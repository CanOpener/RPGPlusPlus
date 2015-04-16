#include "stdafx.h"
using namespace std;

int main(int argc, char *argv[])
{
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window* window = SDL_CreateWindow("Beep", 100, 100, 800, 600, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL_Event* mainEvent = new SDL_Event();
	bool quit = false;

	SDL_Texture* grass = IMG_LoadTexture(renderer, "grass.bmp");
	SDL_Rect grassRect;
	grassRect.x = 0;
	grassRect.y = 0;
	grassRect.w = 800;
	grassRect.h = 600;
	
	Entity bob(200,200,100,180,"bob.png",renderer);

	while (!quit && mainEvent->type != SDL_QUIT) 
	{
		SDL_PollEvent(mainEvent);
		SDL_RenderClear(renderer);

		SDL_RenderCopy(renderer, grass, NULL, &grassRect);
		
		bob.draw();
		
		SDL_RenderPresent(renderer);
	}

	SDL_DestroyTexture(grass);
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	delete mainEvent;
	return 0;
}

