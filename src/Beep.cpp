#include "stdafx.h"
using namespace std;

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
SDL_Event* mainEvent = NULL;
SDL_Texture* grass = NULL;
SDL_Rect grassRect;

int WLENGTH = 1280;
int WHEIGHT = 720;

void render();
void update();
void clear();
void quit();

Player* bob = NULL;


int main(int argc, char *argv[])
{
	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow("RPG++", 100, 100, WLENGTH, WHEIGHT, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	grass = IMG_LoadTexture(renderer, "grass.bmp");
	mainEvent = new SDL_Event();

	bob = new Player("bob.png", renderer);

	grassRect.x = 0; grassRect.y = 0;
	grassRect.w = WLENGTH; grassRect.h = WHEIGHT;

	while (true) 
	{
		clear();
		update();
		render();
	}


	return 0;
}

void render()
{
	SDL_RenderCopy(renderer, grass, NULL, &grassRect);
	bob->draw();

	SDL_RenderPresent(renderer);
}

void update()
{
	SDL_PollEvent(mainEvent);

	switch (mainEvent->type)
	{
	case SDL_QUIT :
		quit();
		return;
	
	case SDL_KEYDOWN :
		bob->update(mainEvent);
		return;

	case SDL_KEYUP :
		bob->update(mainEvent);
		return;
	}

	bob->update(mainEvent);
}

void clear()
{
	SDL_RenderClear(renderer);
}

void quit()
{
	cout << "here";
	SDL_DestroyTexture(grass);
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	delete mainEvent;
	exit(0);
}

