#include "ScissorsVisitor.h"

int ScissorsVisitor::visitRock(const Rock& rock) const
{
    return -1;
}

int ScissorsVisitor::visitPaper(const Paper& paper) const
{
    return 1;
}

int ScissorsVisitor::visitScissors(const Scissors& scissors) const
{
    return 0;
}
