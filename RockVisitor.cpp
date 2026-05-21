#include "RockVisitor.h"

int RockVisitor::visitRock(const Rock& rock) const
{
    return 0;
}

int RockVisitor::visitPaper(const Paper& paper) const
{
    return -1;
}

int RockVisitor::visitScissors(const Scissors& scissors) const
{
    return 1;
}
