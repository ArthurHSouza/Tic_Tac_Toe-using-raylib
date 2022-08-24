/*
* Pawn it's what the player or the AI controls, in this cases are Symbols, the X or O.
*/
#pragma once
#include "Table.h"
#include <vector>
class Pawn
{
protected:
	Color color{ WHITE }; //Color of the symbol
	bool win{ false };
	char type{}; //Type of the Pawn
	std::vector<bool>quadsUseds{ false,false,false,false,false,false,false,false,false }; //This are the places where the Symbol is Drawn
public:
	virtual ~Pawn() {}
	virtual void DrawSymbol(Table &t) {}
	virtual void DrawDemo() {} //This is used to demostrate the symbol when is changing his color
	virtual std::vector<bool>& GetQuads();
	virtual char GetType();
	virtual bool& GetWin();
	virtual Color& GetColor();
};

