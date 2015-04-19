#include "stdafx.h"

class Entity {
protected :
	int maxHP, HP;
	int defence, attackPower;
	SDL_Renderer* renderer;
	SDL_Texture* entityTexture;
	SDL_Rect entityRect;
	SDL_Rect healthBar, damageBar;

	void calculateHealthBar();

public :
	Entity();
	~Entity();

	void init(int px, int py, int sx, int sy, const char* img, SDL_Renderer* rend);
	void move(int x, int y);
	void resize(int w, int h);
	void draw();

	void setMaxHP(int MHP);
	int getMaxHP();
	void setHP(int hp);
	int getHP();
	void setDefence(int d);
	int getDefence();
	void setAttackPower(int ap);
	int getAttackPower();
	SDL_Rect* getRect();
};