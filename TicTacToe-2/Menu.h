#pragma once
#include "raylib.h"
#include "Pawn.h"
#include <vector>
#include <iostream>
class Menu
{
private:
	Font fon;
	Sound menuInput;

	const float sizeText = GetScreenHeight() / 8.f; //Equals 100 when the size of the screen is 800x800
	const float boxWidth = GetScreenWidth() / 1.4545f; //Equals 550 when the size of the screen is 800x800
	const float boxHeight = GetScreenHeight() / 8.79120f; //Equals 91 when the size of the screen is 800x800

	//Boxes data
	float xWhite = GetScreenWidth() / 6.4f; //Equals 125 when the size of the screen is 800x800
	float xBlack = GetScreenWidth() / 6.1538f; //Equals 130 when the size of the screen is 800x800
	float yWhite = GetScreenHeight() / 2.6845f; //Equals 298 when the size of the screen is 800x800
	float blackEdge = 10; //Its to limit the black box
	//Boxes that will be add to the screen, thoses box are what the player will cilck to choose what he wants
	Rectangle boxWhiteOne{ xWhite,yWhite,boxWidth,boxHeight };
	Rectangle boxBlackOne{ xBlack,303,boxWidth - blackEdge,boxHeight - blackEdge };

	Rectangle boxWhiteTwo{ xWhite,yWhite + 100.f,boxWidth,boxHeight };
	Rectangle boxBlackTwo{ xBlack,403,boxWidth - blackEdge,boxHeight - blackEdge };

	Rectangle boxWhiteThree{ xWhite,yWhite + 200.f,boxWidth,boxHeight };
	Rectangle boxBlackThree{ xBlack,503,boxWidth - blackEdge,boxHeight - blackEdge };

	Rectangle boxWhiteFour{ xWhite,yWhite + 300.f,boxWidth,boxHeight };
	Rectangle boxBlackFour{ xBlack,603,boxWidth - blackEdge,boxHeight - blackEdge };

public:
	Menu();
	~Menu();
	int DrawMenu(float &volumeMusic);
	char DrawSymSelectionMenu(); //The player choose if he wants to play as X or O
	int DrawConfigs();
	void DrawChagePawnColor(Pawn& pa);
	void DrawManual();
	int DrawSetDifficulty();
	void DrawWinText(char c);
	void DrawTieText();
	void AdviceToRestart();
};

