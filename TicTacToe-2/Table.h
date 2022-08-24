#pragma once
#include "raylib.h"
#include <vector>
class Table
{
private:
	float thickness{ 5.f };

public:
	//edges
	float rbEdge = (float)GetScreenHeight(); //right and botoon
	float edge{ 0 }; //top and left

	float firstColl = GetScreenWidth() / 3.f;
	float secondColl = GetScreenWidth() * (2 / 3.f);
	//do not needs a third coll

	float firstLine = GetScreenHeight() / 3.f;
	float secondLine = GetScreenHeight() * (2 / 3.f);
	//do not needs a thirdLine

	void DrawTable();
};
