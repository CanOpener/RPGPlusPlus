#include "stdafx.h"

Player::Player(const char* img, std::string n, SDL_Renderer* rend)
{
	init(200,200,100,180,img,rend);
	name = n;

	setMaxHP(500);
	setHP(478);
	setDefence(30);
	setAttackPower(19);

	moveX = moveY = 0;
	movementSpeed = 2;
}

Player::~Player()
{

}

void Player::update()
{
	if (moveX || moveY)
		move(entityRect.x + moveX, entityRect.y + moveY);
}

void Player::updateMovementVariables(int movementType)
{
	std::cout << moveX << std::endl;
	switch (movementType)
	{
		case Player_Move_Enums::BTDOWN_UP :
			moveY = 0 - movementSpeed;
			break;
		case Player_Move_Enums::BTDOWN_DOWN:
			moveY = 0 + movementSpeed;
			break;
		case Player_Move_Enums::BTDOWN_LEFT:
			moveX = 0 - movementSpeed;
			break;
		case Player_Move_Enums::BTDOWN_RIGHT:
			moveX = 0 + movementSpeed;
			break;
		case Player_Move_Enums::BTUP_UP:
			if (moveY == 0 - movementSpeed) moveY = 0;
			break;
		case Player_Move_Enums::BTUP_DOWN:
			if (moveY == 0 + movementSpeed) moveY = 0;
			break;
		case Player_Move_Enums::BTUP_LEFT:
			if (moveX == 0 - movementSpeed) moveX = 0;
			break;
		case Player_Move_Enums::BTUP_RIGHT:
			if (moveX == 0 + movementSpeed) moveX = 0;
			break;
	}
}

void Player::setName(std::string n)
{
	name = n;
}

std::string Player::getName()
{
	return name;
}