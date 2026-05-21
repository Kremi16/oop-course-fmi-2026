#pragma once
#include"Player.h"
#include"PaperVisitor.h"

class Paper:public Player
{
public:
	Paper(const string& name);

	int accept(const Visitor& visitor) const override;
	unique_ptr<Visitor> createVisitor() const override;
	unique_ptr<Player> clone()const override;
};

