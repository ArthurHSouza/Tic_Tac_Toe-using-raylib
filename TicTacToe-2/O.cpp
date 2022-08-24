#include "O.h"

void O::DrawSymbol(Table& t)
{
	//There are 9 quads, 0 to 8	
	float init = GetScreenWidth() / 6; // Deafult Value
	const float triple = 3.006f;
	const float quintple = 5.015f;
	int aux = 0; // Take The 0 to 2 quads
	int b = 3; // Take The 3 to 5 quads
	int c = 6; // Take The 6 to 8 quads
	for (float i = 1; i < 6.f; i += 2.008)
	{
		if (quadsUseds.at(aux) == true)
		{
			DrawCircleV({ init * i,init }, outSize, color);
			DrawCircleV({ init * i, init }, inSize, BLACK);
		} aux++;
		if (quadsUseds.at(b) == true)
		{
			DrawCircleV({ init * i,init * triple }, outSize, color);
			DrawCircleV({ init * i,init * triple }, inSize, BLACK);
		}b++;
		if (quadsUseds.at(c) == true)
		{
			DrawCircleV({ init * i,init * quintple }, outSize, color);
			DrawCircleV({ init * i,init * quintple }, inSize, BLACK);
		}c++;
	}
}

void O::DrawDemo()
{
	DrawCircleV({ GetScreenWidth()/2.f, GetScreenWidth() * 0.75f}, outSize, color);
	DrawCircleV({ GetScreenWidth() / 2.f, GetScreenWidth() * 0.75f }, inSize, BLACK);
}

char O::GetType()
{
	return Type;
}