#pragma once
#include"Visitor.h"
#include<memory>
#include<string>

using namespace std;

class Player
{
private:
	string name;

public:
	explicit Player(const string& name);

	virtual ~Player() = default;

	virtual int accept(const Visitor& visitor)const = 0;
	virtual unique_ptr<Visitor> createVisitor()const = 0;
	virtual unique_ptr<Player> clone()const = 0;

	int playAgainst(const Player& opponent)const;
	const string& getName()const;
};

