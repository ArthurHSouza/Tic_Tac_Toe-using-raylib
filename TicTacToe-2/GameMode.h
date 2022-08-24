#pragma once
#include "Raylib.h"
#include "Pawn.h"
#include "Menu.h"
#include "Player.h"
#include "AI.h"
/*
* This class is to control the most part of the gameplay logic
*/

#include "Table.h"
#include <vector>
#include <algorithm>
#include <iostream>
class GameMode
{
private:
	bool switchTime{ false }; //false == X, true == O
	bool win{ false };

	Sound xInput;
	Sound oInput;
public:
	GameMode();
	~GameMode();
	bool GetTime();
	void ChangeTime();
	bool DidWin(Pawn &pa, Menu &m, Player &p);
	bool VerifyDraw(Pawn *pa);
	void ResetGame(std::vector<Pawn*> pawns, std::vector<bool*> playedsSounds, Player& p);
	void PvP(Player& p, Table& t, Pawn& x, Pawn& o);
	void PvAI(Player& p, AI &ai, Table& t, Pawn& x, Pawn& o);
};

