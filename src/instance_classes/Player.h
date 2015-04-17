#include "stdafx.h"

class Player : public Entity {
private :
public :
	Player(const char* img, SDL_Renderer* rend);
	void update(SDL_Event* thisEvent = NULL);
protected :
};