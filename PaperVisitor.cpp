#include "PaperVisitor.h"

int PaperVisitor::visitRock(const Rock& rock) const
{
    return 1;
}

int PaperVisitor::visitPaper(const Paper& paper) const
{
    return 0;
}

int PaperVisitor::visitScissors(const Scissors& scissors) const
{
    return -1;
}
