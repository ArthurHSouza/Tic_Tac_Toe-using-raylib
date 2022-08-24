#include "GameMode.h"

GameMode::GameMode()
{
	xInput = LoadSound("assets/player_input.wav");
	oInput = LoadSound("assets/enemy_input.wav");
}

GameMode::~GameMode()
{
	UnloadSound(xInput);
	UnloadSound(oInput);
}

bool GameMode::GetTime()
{
	return switchTime;
}

void GameMode::ChangeTime()
{
	switchTime = !switchTime;
}

bool GameMode::DidWin(Pawn& pa, Menu& m, Player &p)
{
	//Win Lines
	std::vector<bool> B = pa.GetQuads();
	float screenW = (float) GetScreenWidth(); //Screen Width
	float screenH = (float) GetScreenHeight(); //Screen Height
	float middle = (screenW / 6.0f); //The middle of the left quad
	float startPoint = 10.f;
	int aux = 0; //To change the middle
	int changeLorC = 0; //Change line or column
	Rectangle yLine{ 0, 0, screenW / 80.f, screenH - startPoint * 2};
	Rectangle xLine{ 0, 0, screenW - startPoint * 2 , screenH / 80.f };

	//Vertical Line
	for (int i = 0; i < 3; i++)
	{
		changeLorC = 1 + (i * 2);
		if (B.at(i) == true && B.at(i + 3) == true && B.at(i + 6) == true)
		{
			middle *= changeLorC;
			DrawRectanglePro(yLine, { yLine.x - middle + (yLine.width/2.f), yLine.y - startPoint }, 0.f, pa.GetColor());
		}
	}
	//Horizontal Lines
	for (int i = 0; i < 7; i += 3)
	{
		changeLorC = 1 + (aux * 2);
		if (B.at(i) == true && B.at(i + 1) == true && B.at(i + 2) == true)
		{
		
			middle *= changeLorC;
			DrawRectanglePro(xLine, { xLine.x - startPoint, xLine.y - middle + (xLine.height / 2.f) }, 0.f, pa.GetColor());
		}
		aux++;
	}
	//Diagonal Lines
	if (B.at(0) == true && B.at(4) == true && B.at(8) == true)
		DrawLineEx({ startPoint, startPoint }, { screenW - startPoint, screenH - startPoint }, screenW / 80.f, pa.GetColor());
	if (B.at(2) == true && B.at(4) == true && B.at(6) == true)
		DrawLineEx({ startPoint, screenH - startPoint }, { screenW - startPoint, startPoint }, screenW / 80.f, pa.GetColor());

	//Verify if wins
	if ((B.at(0) == true && B.at(1) == true && B.at(2) == true) || (B.at(0) == true && B.at(4) == true && B.at(8) == true) ||
		(B.at(2) == true && B.at(4) == true && B.at(6) == true) || (B.at(3) == true && B.at(4) == true && B.at(5) == true) ||
		(B.at(6) == true && B.at(7) == true && B.at(8) == true) || (B.at(0) == true && B.at(3) == true && B.at(6) == true) ||
		(B.at(1) == true && B.at(4) == true && B.at(7) == true) || (B.at(2) == true && B.at(5) == true && B.at(8) == true))
	{
		m.DrawWinText(pa.GetType());
		if(p.GetType() == pa.GetType())
			p.GetWin() = true;
		else
			p.GetWin() = false;
		return true;
	}
	else
	{
		p.GetWin() = false;
		return false;
	}
}

bool GameMode::VerifyDraw(Pawn *pa)
{
	int xCount = 0; //How many X have on the table
	for (int i = 0; i < pa->GetQuads().size(); i++)
	{
		if (pa->GetQuads().at(i) == true)
			xCount++;
	}
	if (xCount == 5 && pa->GetWin() == false)
	{
		return true;
	}
	else
		return false;
}

void GameMode::ResetGame(std::vector<Pawn*> pawns, std::vector<bool*> playedsSounds, Player &p)
{
	switchTime = false;
	p.GetWin() = false;
	std::for_each(pawns.begin(), pawns.end(), [](auto pawn)
		{ 
			for (auto b : pawn->GetQuads())
				b = false;
		}
	);
	std::for_each(playedsSounds.begin(), playedsSounds.end(), [](auto played) {*played = false; });
}

void GameMode::PvP(Player& p, Table& t, Pawn& x, Pawn& o)
{
	if (GetTime() == false && p.SetPlayerMouseQuad(t, x, o) == true)
	{
		ChangeTime();
		PlaySound(xInput);
	}
	else if (GetTime() == true && p.SetPlayerMouseQuad(t, o, x) == true)
	{
		ChangeTime();
		PlaySound(oInput);
	}
}

void GameMode::PvAI(Player& p, AI& ai, Table& t, Pawn& x, Pawn& o)
{
	static int time = 0; //To delay the AI
	//Player with X
	if (p.GetType() == 'X')
	{
		if (GetTime() == false && p.SetPlayerMouseQuad(t, x, o) == true)
		{
			ChangeTime();
			PlaySound(xInput);
		}
		else if (GetTime() == true)
		{
			time++;
			if (time >= 15)
			{
				ai.Play(o.GetQuads(), x.GetQuads());
				ChangeTime();
				PlaySound(oInput);
				time = 0;
			}
		}
	}
	//Player with O
	else
	{
		if (GetTime() == false)
		{
			time++;
			if (time >= 15)
			{
				ai.Play(x.GetQuads(), o.GetQuads());
				ChangeTime();
				PlaySound(xInput);
				time = 0;
			}
		}
		else if (GetTime() == true && p.SetPlayerMouseQuad(t, o, x) == true)
		{
			ChangeTime();
			PlaySound(oInput);
		}
	}
}
