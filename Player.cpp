#include "Player.h"

Player::Player(const string& name):name(name){}

int Player::playAgainst(const Player& opponent)const
{
	auto v = createVisitor();
	int result = opponent.accept(*v);
	return result;
}

const string& Player::getName()const
{
	return name;
}