#pragma once
#include"Player.h"
#include"RockVisitor.h"

class Rock:public Player
{
public:
	Rock(const string& name);

	int accept(const Visitor& visitor) const override;
	unique_ptr<Visitor> createVisitor() const override;
	unique_ptr<Player> clone()const override;
};

