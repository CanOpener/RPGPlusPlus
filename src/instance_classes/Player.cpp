#include "stdafx.h"

Player::Player(const char* img, SDL_Renderer* rend) : Entity(100, 100, 100, 180, img, rend){}

void Player::update(SDL_Event* thisEvent)
{
	static bool keyPressed = false;
	static int direction = 0;

	switch (thisEvent->type)
	{

	case SDL_KEYDOWN:

		switch (thisEvent->key.keysym.sym)
		{

		case SDLK_w:
			std::cout << "here";
			direction = 0;
			keyPressed = true;
			break;

		case SDLK_s:
			direction = 1;
			keyPressed = true;
			break;

		case SDLK_a:
			direction = 2;
			keyPressed = true;
			break;

		case SDLK_d:
			direction = 3;
			keyPressed = true;
			break;

		}

		break;

	case SDL_KEYUP:

		switch (thisEvent->key.keysym.sym)
		{

		case SDLK_w:
			keyPressed = false;
			break;

		case SDLK_s:
			keyPressed = false;
			break;

		case SDLK_a:
			keyPressed = false;
			break;

		case SDLK_d:
			keyPressed = false;
			break;

		}

		break;
	}

	if (keyPressed)
	{
		switch (direction)
		{
		case 0:
			move(entityRect.x, entityRect.y - 1);
			break;
		case 1:
			move(entityRect.x, entityRect.y + 1);
			break;
		case 2:
			move(entityRect.x - 1, entityRect.y);
			break;
		case 3:
			move(entityRect.x + 1, entityRect.y);
			break;
		}
	}
}