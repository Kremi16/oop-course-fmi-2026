#include "Rock.h"

Rock::Rock(const string& name):Player(name){}

int Rock::accept(const Visitor& visitor) const
{
	return visitor.visitRock(*this);
}

unique_ptr<Visitor> Rock::createVisitor() const
{
	return make_unique<RockVisitor>();
}

unique_ptr<Player> Rock::clone()const
{
	return make_unique<Rock>(*this);
}