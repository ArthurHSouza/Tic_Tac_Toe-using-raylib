#include "Menu.h"
Menu::Menu()
{
	fon = LoadFontEx("assets/quantum.otf", 100, 0, 0); 
	GenTextureMipmaps(&fon.texture);
	SetTextureFilter(fon.texture, TEXTURE_FILTER_BILINEAR);

	menuInput = LoadSound("assets/menuInput.wav");
}

Menu::~Menu()
{
	UnloadFont(fon); 
	UnloadSound(menuInput);
}

int Menu::DrawMenu(float &volumeMusic)
 {
	const float sizeTextSmall{ 30 };
	//All the strings that will be show on Main Menu
	const char credits[]{ "All sounds from Zapsplat.com" };
	const char title[]{ "TIC TAC TOE" };
	const char textOne[]{ "P VS P" };
	const char textTwo[]{ "P VS AI" };
	const char textcreditsOne[]{ "   CREATED BY\nARTHUR H SOUZA" };
	const char textcreditsTwo[]{ "        USING\n RAYLIB AND CPP" };
	const char configsText[]{ "CONFIGS" };

	Vector2 textConfigsMea = MeasureTextEx(fon, configsText, sizeText, 1);

	//Draw all the text and Buttons (boxes)
	DrawTextEx(fon, credits, { GetScreenWidth() * 0.55f, 0 }, sizeTextSmall - 10, 1, WHITE);
	DrawTextEx(fon, title, { GetScreenWidth() * 0.0125f, GetScreenHeight() * 0.125f }, sizeText, 1, WHITE);

	DrawRectangleRec(boxWhiteOne, WHITE);
	DrawRectangleRec(boxBlackOne, BLACK);
	DrawTextEx(fon, textOne, { 210, 300 }, sizeText, 1, WHITE);

	DrawRectangleRec(boxWhiteTwo, WHITE);
	DrawRectangleRec(boxBlackTwo, BLACK);
	DrawTextEx(fon, textTwo, { 180, 400 }, sizeText, 1, WHITE);

	DrawTextEx(fon, textcreditsOne, { 000, 700 }, sizeTextSmall, 1, WHITE);
	DrawTextEx(fon, textcreditsTwo, { 470, 700 }, sizeTextSmall, 1, WHITE);

	DrawRectangleRec(boxWhiteThree, WHITE);
	DrawRectangleRec(boxBlackThree, BLACK);
	DrawTextEx(fon, configsText, { (GetScreenWidth() / 2) - (textConfigsMea.x / 2), 500 }, sizeText, 1, WHITE);

	//Buttons' logic
	if (CheckCollisionPointRec(GetMousePosition(), boxWhiteOne) == true && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		DrawRectangleRec(boxWhiteOne, GRAY);
		PlaySound(menuInput);
		return 1;
	}
	else if (CheckCollisionPointRec(GetMousePosition(), boxWhiteTwo) == true && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		DrawRectangleRec(boxWhiteTwo, GRAY);
		PlaySound(menuInput);

		return 2;
	}
	else if (CheckCollisionPointRec(GetMousePosition(), boxWhiteThree) == true && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		DrawRectangleRec(boxWhiteThree, GRAY);
		PlaySound(menuInput);
		return 3;
	}
	else
		return 0;
}

char Menu::DrawSymSelectionMenu()
{
	float sizeCText = sizeText / 2.f;
	//All the strings that will be show on Main Menu
	const char cText[]{ "CHOOSE ONE TO CONTROL" };
	const char x[]{ "X" };
	const char o[]{ "O" };

	Vector2 cTextMea = MeasureTextEx(fon, cText, sizeCText, 1);
	Vector2 symtMea = MeasureTextEx(fon, x, sizeText, 1);

	//Draw all the text and boxes
	DrawTextEx(fon, cText, { (GetScreenHeight() / 2) - (cTextMea.x / 2), GetScreenHeight() / 5.5f}, sizeCText, 1, WHITE);

	DrawRectangleRec(boxWhiteOne, WHITE);
	DrawRectangleRec(boxBlackOne, BLACK);
	DrawTextEx(fon, x, { GetScreenWidth()/2.f - symtMea.x/2.f, boxWhiteOne.y}, sizeText, 1, WHITE);

	DrawRectangleRec(boxWhiteTwo, WHITE);
	DrawRectangleRec(boxBlackTwo, BLACK);
	DrawTextEx(fon, o, { GetScreenWidth() / 2.f - symtMea.x / 2.f, boxWhiteTwo.y + 3}, sizeText, 1, WHITE);

	//Buttons' logic
	if (CheckCollisionPointRec(GetMousePosition(), boxWhiteOne) == true && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		DrawRectangleRec(boxWhiteOne, GRAY);
		PlaySound(menuInput);
		return 'X';
	}
	else if (CheckCollisionPointRec(GetMousePosition(), boxWhiteTwo) == true && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		DrawRectangleRec(boxWhiteTwo, GRAY);
		PlaySound(menuInput);
		return 'O';
	}
	else
		return 'P';
}

int Menu::DrawConfigs()
{
	//All the strings that will be show on Main Menu
	const char configsText[]{ "SETTINGS" };
	Vector2 textConfigsMea = MeasureTextEx(fon, configsText, sizeText, 1);

	const char chageXText[]{ "X COLOR" };
	Vector2 textChangeXMea = MeasureTextEx(fon, chageXText, sizeText, 1);

	const char chageOText[]{ "O COLOR" };
	Vector2 textChangeOMea = MeasureTextEx(fon, chageOText, sizeText, 1);

	const char muteText[]{ "MUTE" };
	Vector2 textMuteMea = MeasureTextEx(fon, muteText, sizeText, 1);

	const char manualText[]{ "MANUAL" };
	Vector2 textManualMea = MeasureTextEx(fon, manualText, sizeText, 1);


	//Draw boxes and the all text 
	DrawRectangleRec(boxWhiteOne, WHITE);
	DrawRectangleRec(boxBlackOne, BLACK);

	DrawRectangleRec(boxWhiteTwo, WHITE);
	DrawRectangleRec(boxBlackTwo, BLACK);

	DrawRectangleRec(boxWhiteThree, WHITE);
	DrawRectangleRec(boxBlackThree, BLACK);

	DrawRectangleRec(boxWhiteFour, WHITE);
	DrawRectangleRec(boxBlackFour, BLACK);

	//Draw Configs text
	DrawTextEx(fon, configsText, { (GetScreenWidth()/2.f) - (textConfigsMea.x/2.f), GetScreenHeight() * 0.125f }, sizeText, 1, WHITE);
	//Draw X Color text
	DrawTextEx(fon, chageXText, { (GetScreenWidth() / 2.f) - (textChangeXMea.x / 2.f), boxBlackOne.y }, sizeText, 1, WHITE);
	//Draw O color text
	DrawTextEx(fon, chageOText, { (GetScreenWidth() / 2.f) - (textChangeOMea.x / 2.f), boxBlackTwo.y }, sizeText, 1, WHITE);
	//Draw mute text
	DrawTextEx(fon, muteText, { (GetScreenWidth() / 2.f) - (textMuteMea.x / 2.f), boxBlackThree.y }, sizeText, 1, WHITE);
	//Draw manual text
	DrawTextEx(fon, manualText, { (GetScreenWidth() / 2.f) - (textManualMea.x / 2.f), boxBlackFour.y }, sizeText, 1, WHITE);
	
	//Button's logic
	if (CheckCollisionPointRec(GetMousePosition(), boxWhiteOne) == true && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		DrawRectangleRec(boxWhiteOne, GRAY);
		PlaySound(menuInput);
		return 1;
	}
	else if (CheckCollisionPointRec(GetMousePosition(), boxWhiteTwo) == true && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		DrawRectangleRec(boxWhiteTwo, GRAY);
		PlaySound(menuInput);

		return 2;
	}
	else if (CheckCollisionPointRec(GetMousePosition(), boxWhiteThree) == true && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		DrawRectangleRec(boxWhiteThree, GRAY);
		PlaySound(menuInput);

		return 3;
	}
	else if (CheckCollisionPointRec(GetMousePosition(), boxWhiteFour) == true && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		DrawRectangleRec(boxWhiteFour, GRAY);
		PlaySound(menuInput);

		return 4;
	}

	return 0;
}

int Menu::DrawSetDifficulty()
{
	//All the strings that will be show on Main Menu
	float difficultyTextSize = 80.f;
	const char difficultyText[]{ "SET DIFFCULTY" };
	Vector2 textDifficultyMea = MeasureTextEx(fon, difficultyText, difficultyTextSize, 1);

	const char easyText[]{ "EASY" };
	Vector2 textEasyMea = MeasureTextEx(fon, easyText, sizeText, 1);

	const char mediumText[]{ "MEDIUM" };
	Vector2 textMediumMea = MeasureTextEx(fon, mediumText, sizeText, 1);

	const char hardText[]{ "HARD" };
	Vector2 textHardMea = MeasureTextEx(fon, hardText, sizeText, 1);

	//Draw boxes and the all text 
	DrawRectangleRec(boxWhiteOne, WHITE);
	DrawRectangleRec(boxBlackOne, BLACK);

	DrawRectangleRec(boxWhiteTwo, WHITE);
	DrawRectangleRec(boxBlackTwo, BLACK);

	DrawRectangleRec(boxWhiteThree, WHITE);
	DrawRectangleRec(boxBlackThree, BLACK);

	//Draw Choose Difficulty text
	DrawTextEx(fon, difficultyText, { (GetScreenWidth() / 2.f) - (textDifficultyMea.x / 2.f), GetScreenHeight() * 0.125f }, difficultyTextSize, 1, WHITE);
	//Draw easy text
	DrawTextEx(fon, easyText, { (GetScreenWidth() / 2.f) - (textEasyMea.x / 2.f), boxBlackOne.y }, sizeText, 1, WHITE);
	//Draw medium text
	DrawTextEx(fon, mediumText, { (GetScreenWidth() / 2.f) - (textMediumMea.x / 2.f), boxBlackTwo.y }, sizeText, 1, WHITE);
	//Draw hard text
	DrawTextEx(fon, hardText, { (GetScreenWidth() / 2.f) - (textHardMea.x / 2.f), boxBlackThree.y }, sizeText, 1, WHITE);

	//Button's logic
	if (CheckCollisionPointRec(GetMousePosition(), boxWhiteOne) == true && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		DrawRectangleRec(boxWhiteOne, GRAY);
		PlaySound(menuInput);
		return 1;
	}
	else if (CheckCollisionPointRec(GetMousePosition(), boxWhiteTwo) == true && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		DrawRectangleRec(boxWhiteTwo, GRAY);
		PlaySound(menuInput);

		return 2;
	}
	else if (CheckCollisionPointRec(GetMousePosition(), boxWhiteThree) == true && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		DrawRectangleRec(boxWhiteThree, GRAY);
		PlaySound(menuInput);

		return 3;
	}

	return 0;
}

void Menu::DrawChagePawnColor(Pawn& pa)
{
	//All the strings that will be show on Main Menu
	float sizeChangeText = 80.f;
	const char changeText[] = "PICK A COLOR";
	Vector2 textChangeMea = MeasureTextEx(fon, changeText, sizeChangeText, 1);

	float addLine = GetScreenHeight() / 8.f;
	float distance = GetScreenHeight() / 8.f;; //20 distances beteween the final of one square and the begining of the next one (when its 800x800)
	
	//The square that will be filled with a color
	Rectangle square{ 0, 0, GetScreenWidth() / 10.f, GetScreenHeight() / 10.f };

	float lineYdistance = 0;

	float middle = ((20 * 5) + (square.width * 6)) /2.f;
	std::vector<std::vector<Color>> colors
	{ 
		{WHITE, PINK, GREEN, SKYBLUE, PURPLE, BEIGE},
		{GRAY, RED, LIME, BLUE, VIOLET, BROWN},
		{DARKGRAY, MAROON, DARKGREEN, DARKBLUE, DARKPURPLE, DARKBROWN} 
	};
	
	DrawTextEx(fon, changeText, { (GetScreenWidth() / 2.f) - (textChangeMea.x / 2.f), GetScreenHeight() * 0.05f}, sizeChangeText, 1, WHITE);
	//Draw how many squares is needed to show all the colors
	for (int i = 0; i < 3; i++)
	{
		for (int p = 0; p < 6; p++)
		{
			square.x = GetScreenWidth()/2.f - middle + (distance * p);
			square.y = GetScreenHeight() * 0.2f + (distance * i);

			DrawRectangleRec(square, colors.at(i).at(p));
			if (CheckCollisionPointRec(GetMousePosition(), square) == true)
			{
				lineYdistance = square.y + square.height + (distance/15);
				DrawLineEx({ square.x, lineYdistance }, { square.x + square.width, lineYdistance }, 1.f, colors.at(i).at(p));
				if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) == true)
					pa.GetColor() = colors.at(i).at(p);
			}
		}
	}
	pa.DrawDemo();
}

void Menu::DrawManual()
{
	int sizeManual = 30;
	const char masnualText[]{"MANUAL"};
	const char manual[]{"!HIT Q TO GO TO THE MAIN MENU\n!HIT P TO GO TO THE PREVIUS PAGE\nON CONFIGURATIONS\n!HIT ENTER TO RESTART THE GAME"};
	Vector2 textManualeMea = MeasureTextEx(fon, masnualText, sizeText, 1);
	DrawTextEx(fon, masnualText, { (GetScreenHeight()/2.f) - (textManualeMea.x/2.f), 0}, sizeText, 1, WHITE);
	DrawTextEx(fon, manual, { 10, GetScreenHeight()/2.5f }, sizeManual, 1, WHITE);
}

void Menu::DrawWinText(char c)
{
	const char xWinText[]{ "X WIN" };
	const char oWinText[]{ "O WIN" };
	Vector2 textWinMea = MeasureTextEx(fon, oWinText, sizeText, 1);
	if (c == 'X')
	{
		DrawTextEx(fon, xWinText, { ((GetScreenWidth() / 2) - (textWinMea.x / 2)),
		((GetScreenHeight() / 2) - (textWinMea.y / 2)) }, sizeText, 1, YELLOW);
	}
	else
	{
		DrawTextEx(fon, oWinText, { ((GetScreenWidth() / 2) - (textWinMea.x / 2)),
		((GetScreenHeight() / 2) - (textWinMea.y / 2)) }, sizeText, 1, YELLOW);
	}	
}

void Menu::DrawTieText()
{
	const char drawT[]{ "DRAW" };
	Vector2 mea = MeasureTextEx(fon ,drawT, sizeText, 1);
	DrawTextEx(fon, drawT, { (GetScreenWidth() / 2.f) - (mea.x / 2) ,(GetScreenHeight() / 2) - (mea.y/2)}, sizeText, 1, YELLOW);
}

void Menu::AdviceToRestart()
{
	short int sizeTextAd{ 45 };
	const char adText[]{ "PRESS ENTER TO RESTART" };
	Vector2 textAdMea = MeasureTextEx(fon, adText, sizeTextAd, 1);

	DrawTextEx(fon, adText, { ((GetScreenWidth() / 2) - (textAdMea.x / 2)),
	((GetScreenHeight() / 2) + (textAdMea.y / 1)) }, sizeTextAd, 1, YELLOW);
}