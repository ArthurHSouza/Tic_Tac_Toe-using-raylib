#include "Pawn.h"

std::vector<bool>& Pawn::GetQuads()
{
	return quadsUseds;
}

char Pawn::GetType()
{
	return type;
}

bool& Pawn::GetWin()
{
	return win;
}

Color& Pawn::GetColor()
{
	return color;
}