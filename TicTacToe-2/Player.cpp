#include "Player.h"

bool Player::SetPlayerMouseQuad(Table& t, Pawn &c, Pawn &e)
{
	Vector2 mousePos = GetMousePosition();
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) == true)
	{

		//all first line
		if (mousePos.x <= t.firstColl && mousePos.y <= t.firstLine)
		{
			pQuad = 0;
		}
		else if (mousePos.x > t.firstColl && mousePos.x <= t.secondColl && mousePos.y <= t.firstLine)
		{
			pQuad = 1;
		}
		else if (mousePos.x > t.secondColl && mousePos.y <= t.firstLine)
		{
			pQuad = 2;
		}
		//all second line
		else if (mousePos.x <= t.firstColl && mousePos.y <= t.secondLine)
		{
			pQuad = 3;
		}
		else if (mousePos.x > t.firstColl && mousePos.x <= t.secondColl && mousePos.y <= t.secondLine )
		{
			pQuad = 4;
		}
		else if (mousePos.x > t.secondColl && mousePos.y <= t.secondLine)
		{
			pQuad = 5;
		}
		//all third line
		else if (mousePos.x <= t.firstColl && mousePos.y > t.secondLine)
		{
			pQuad = 6;
		}
		else if (mousePos.x > t.firstColl && mousePos.x <= t.secondColl && mousePos.y > t.secondLine)
		{
			pQuad = 7;
		}
		else if (mousePos.x > t.secondColl && mousePos.y > t.secondLine)
		{
			pQuad = 8;
		}
		//Overlap
		if(c.GetQuads().at(pQuad) == true || e.GetQuads().at(pQuad) == true)
		{
			return false;
		}

		c.GetQuads().at(pQuad) = true;

		return true;
	}
	else
		return false;
}

char& Player::GetType()
{
	return type;
}

bool& Player::GetWin()
{
	return win;
}