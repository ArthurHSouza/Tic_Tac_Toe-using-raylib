#include "X.h"

void X::DrawSymbol(Table &t)
{
	//There are 9 quads, 0 to 8	
	float init{ t.firstLine }; // Deafult Value
	int b = 3; // Take The 3 to 5 quads
	int c = 6; // Take The 6 to 8 quads

	//Draw the X on the table
	for (int i = 0; i < 3; i++)
	{
		if (quadsUseds.at(i) == true)
		{
			DrawLineEx({ (init * i) + limiter,t.firstLine - limiter }, { (init * (i + 1)) - limiter, 0 + limiter}, thickness, color);
			DrawLineEx({ (init * i) + limiter, 0 + limiter}, { (init * (i + 1)) - limiter, init - limiter }, thickness, color);
		}
		if (quadsUseds.at(b) == true)
		{
			DrawLineEx({ (init * i) + limiter, t.secondLine - limiter}, { init * (i + 1) - limiter, init + limiter}, thickness, color);
			DrawLineEx({ (init * i) + limiter, t.firstLine + limiter}, { init * (i + 1) - limiter, t.secondLine - limiter }, thickness, color);
		}b++;
		if (quadsUseds.at(c) == true)
		{
			DrawLineEx({ (init * i) + limiter,t.rbEdge - limiter}, { init * (i + 1) - limiter, t.secondLine + limiter }, thickness, color);
			DrawLineEx({ (init * i) + limiter,t.secondLine + limiter}, { init * (i + 1) - limiter, t.rbEdge - limiter}, thickness, color);
		}c++;
	}
}

void X::DrawDemo()
{
	float xBegin = GetScreenWidth() * 0.375f; //300 (when the screen is 800x800)
	float pulsHalf = GetScreenHeight() * 0.625; //500 (when the screen is 800x800)
	float almostFull = GetScreenHeight() * 0.875; //700 (when the screen is 800x800)
	//Draw the X
	DrawLineEx({xBegin , pulsHalf }, { pulsHalf,almostFull }, thickness, color);
	DrawLineEx({xBegin, almostFull }, { pulsHalf,pulsHalf }, thickness, color);
}

char X::GetType()
{
	return Type;
}