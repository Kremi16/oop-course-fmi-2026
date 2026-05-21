#pragma once

class Player;
class Rock;
class Paper;
class Scissors;

class Visitor
{
public:
	virtual int visitRock(const Rock& rock)const = 0;
	virtual int visitPaper(const Paper& paper)const = 0;
	virtual int visitScissors(const Scissors& scissors)const = 0;
	
	virtual ~Visitor() = default;
};

