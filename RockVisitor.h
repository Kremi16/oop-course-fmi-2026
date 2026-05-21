#pragma once
#include"Visitor.h"

class RockVisitor:public Visitor
{
public:
	RockVisitor() = default;

	int visitRock(const Rock& rock) const override;
	int visitPaper(const Paper& paper) const override;
	int visitScissors(const Scissors& scissors) const override;
};

