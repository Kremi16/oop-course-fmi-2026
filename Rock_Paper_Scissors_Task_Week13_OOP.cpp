#include <iostream>
#include"Player.h"
#include"RPSTournament.h"
#include "Rock.h"
#include"Paper.h"
#include"Scissors.h"

int main()
{
    Rock r1("Rock");
    Paper p1("Paper");
    Scissors s1("Scissors");
    Rock r2("Rock2");
    Scissors s2("Scissors2");

    RPSTournament tournament;
    tournament.addPlayer(r1);
    tournament.addPlayer(p1);
    tournament.addPlayer(s1);
    tournament.addPlayer(r2);
    tournament.addPlayer(s2);
    tournament.run();

    const auto& winner = tournament.getWinner();
    cout << "Winner: " << winner->getName() << '\n';

    return 0;
}

