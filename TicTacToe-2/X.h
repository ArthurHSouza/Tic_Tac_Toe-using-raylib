#pragma once
#include "Pawn.h"
#include "Raylib.h"
#include "Table.h"
#include <vector>
class X : public Pawn
{
private:
	char Type{ 'X' };
	float limiter {20}; //defines the boundaries of the X symbol, it's like a size
	int thickness{ 5 }; 
public:
	void DrawSymbol(Table &t) override;
	void DrawDemo() override;
	char GetType() override;
};

