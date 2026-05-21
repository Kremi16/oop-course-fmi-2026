#pragma once
#include"Visitor.h"

class PaperVisitor:public Visitor
{
public:
	int visitRock(const Rock& rock) const override;
	int visitPaper(const Paper& paper) const override;
	int visitScissors(const Scissors& scissors) const override;
};

