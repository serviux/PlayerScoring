#include "Player.h"

Player::Player(const char* n, int w, int l) :
	name(n),
	wins(w), 
	losses(l)
{
	this->top = 0;
}

void Player::addLast(const char* playerName)
{
	if (top < 5)
	{
		this->lastFive[top] = playerName;
		this->top++;
	}
}
