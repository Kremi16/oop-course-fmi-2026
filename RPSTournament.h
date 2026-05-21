#pragma once
#include"Player.h"
#include"Visitor.h"
#include<memory>
#include<vector>
using namespace std;

class RPSTournament
{
private:
	vector<unique_ptr<Player>> players;
	vector<int> scores;

public:
	void addPlayer(const Player& player);
	void run();
	void printResults()const;
	const unique_ptr<Player>& getWinner()const;
};

