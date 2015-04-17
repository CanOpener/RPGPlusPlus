#include "stdafx.h"

Entity::Entity(int px, int py, int sx, int sy, const char* img, SDL_Renderer* rend)
{
	entityRect.x = px; entityRect.y = py;
	entityRect.w = sx; entityRect.h = sy;

	entityTexture = IMG_LoadTexture(rend, img);
	renderer = rend;
	maxHP = HP = 100;
	attackPower = 10;
	defence = 14;

	calculateBars();
}

Entity::~Entity()
{
	SDL_DestroyTexture(entityTexture);
}

SDL_Rect* Entity::getRect() 
{
	return &entityRect;
}

void Entity::draw()
{
	SDL_RenderCopy(renderer, entityTexture, NULL, &entityRect);

	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
	SDL_RenderFillRect(renderer, &healthBar);
	
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderFillRect(renderer, &damageBar);

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
}

void Entity::move(int x, int y)
{
	entityRect.x = x;
	entityRect.y = y;
	calculateBars();
}

void Entity::resize(int w, int h)
{
	entityRect.w = w;
	entityRect.h = h;
	calculateBars();
}

void Entity::calculateBars()
{
	healthBar.x = entityRect.x;
	healthBar.y = damageBar.y = entityRect.y - floorf((float)0.1 * (float)entityRect.h);
	healthBar.h = damageBar.h = floorf((float)0.05 * (float)entityRect.h);

	float percentageHealth = ( (float)HP / (float)maxHP );
	healthBar.w = floorf(percentageHealth * entityRect.w);

	damageBar.x = healthBar.x + healthBar.w;
	damageBar.w = entityRect.w - healthBar.w;
}