#include "RPSTournament.h"
#include<iostream>

void RPSTournament::addPlayer(const Player& player)
{
	players.push_back(player.clone());
}

void RPSTournament::run()
{
	scores.assign(players.size(), 0);

	for (size_t i = 0;i < players.size();i++)
	{
		for (size_t j = i + 1;j < players.size();j++)
		{
			int result = players[i]->playAgainst(*players[j]);
			scores[i] += result;
			scores[j] -= result;
		}
	}
}

void RPSTournament::printResults()const
{
	cout << "Results:" << '\n';
	for (size_t i = 0; i < players.size(); ++i)
	{
		cout << "  " << players[i]->getName()<< ": " << 
			(scores[i] >= 0 ? "+" : "") << scores[i] << "\n";
	}
}

const unique_ptr<Player>& RPSTournament::getWinner()const
{
	auto max = max_element(scores.begin(), scores.end());
	size_t winIndex = static_cast<size_t>(max - scores.begin());

	return players[winIndex];
}
