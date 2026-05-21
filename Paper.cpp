#include "Paper.h"

Paper::Paper(const string& name):Player(name){}

int Paper::accept(const Visitor& visitor) const
{
    return visitor.visitPaper(*this);
}

unique_ptr<Visitor> Paper::createVisitor() const
{
    return make_unique<PaperVisitor>();
}

unique_ptr<Player> Paper::clone()const
{
    return make_unique<Paper>(*this);
}