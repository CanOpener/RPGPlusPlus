#include "stdafx.h"

class Entity {
private :
	int maxHP;
	int HP;
	int defence;
	int attackPower;
	SDL_Renderer* renderer;
	SDL_Texture* entityTexture;
	SDL_Rect entityRect;
	SDL_Rect healthBar;
	SDL_Rect damageBar;

	void calculateBars();

public :
	Entity(int px, int py, int sx, int sy, const char* img, SDL_Renderer* rend);
	~Entity();

	void draw();
	void move(int x, int y);
	void resize(int w, int h);
	SDL_Rect* getRect();
protected :
};