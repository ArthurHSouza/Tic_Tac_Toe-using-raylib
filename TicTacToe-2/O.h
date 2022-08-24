#pragma once
#include "Pawn.h"
#include "raylib.h"
class O : public Pawn
{
private:
	char Type { 'O' };
	int outSize{ 130 }; 
	int inSize{ 125 };

public:
	void DrawSymbol(Table& t) override;
	void DrawDemo() override;
	char GetType() override;
};


