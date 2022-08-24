#pragma once
#include "Table.h"
#include "Pawn.h"
#include <iostream>
#include <vector>
class Player
{
private:
	short int pQuad{ 0 }; //The quad clicked by the player
	char type{ 'P' }; //The player can be the type X or O (the symbol that he use)
	bool win{ false };

public:
	bool SetPlayerMouseQuad(Table &t, Pawn& c, Pawn& e); //Put the symbol where the player clicked
	char& GetType();
	bool& GetWin();
};

