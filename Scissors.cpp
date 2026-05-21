#include "Scissors.h"

Scissors::Scissors(const string& name) :Player(name){}

int Scissors::accept(const Visitor& visitor) const
{
    return visitor.visitScissors(*this);
}

unique_ptr<Visitor> Scissors::createVisitor() const
{
    return make_unique<ScissorsVisitor>();
}

unique_ptr<Player> Scissors::clone()const
{
    return make_unique<Scissors>(*this);
}