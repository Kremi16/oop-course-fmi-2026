#pragma once
#include"Player.h"
#include"ScissorsVisitor.h"

class Scissors:public Player
{
public:
	Scissors(const string& name);

	int accept(const Visitor& visitor) const override;
	unique_ptr<Visitor> createVisitor() const override;
	unique_ptr<Player> clone()const override;
};

