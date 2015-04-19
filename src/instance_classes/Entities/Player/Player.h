#include "stdafx.h"

class Player : public Entity {
private :
	std::string name;

	int moveX;
	int moveY;
	int movementSpeed;

public :
	Player(const char* img, std::string n, SDL_Renderer* rend);
	~Player();

	void update();
	void updateMovementVariables(int movementType);

	void setName(std::string n);
	std::string getName();
};