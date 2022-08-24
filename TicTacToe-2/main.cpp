#include "raylib.h"
#include "Table.h"
#include "GameMode.h"
#include "Menu.h"
#include "Player.h"
#include "AI.h"
#include "Pawn.h"
#include "O.h"
#include "X.h"
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	//Initialization
	InitWindow(800, 800, "TIC TAC TOE");
	InitAudioDevice();
	Image icon = LoadImage("assets/TicTacToeIcon.png");
	SetWindowIcon(icon);

	//Loading sound effects and songs 
	Sound drawEffect = LoadSound("assets/draw_effect.wav");
	Sound winEffect = LoadSound("assets/win_effect.wav");
	Sound lostEffect = LoadSound("assets/lost_effect.wav");
	Music menuMusic = LoadMusicStream("assets/menuMusic.wav");

	//Objects of the program
	GameMode g;
	Menu m;
	Table t;
	AI ai;
	Player p;
	Pawn *x = new X ();
	Pawn *o = new O ();
	std::vector<Pawn*> pawns{ x,o }; //This is to easier call the methods

	//Auxiliar variables
	int dif = 0; //This is to call the Set Difficulty Menu only one time
	int configMode{ 0 };//This is to call the Configuration Menu only one time
	int mode{ 0 }; //This is to call the Main Menu only when it's needed
	char sym{ 'P' }; //This is to call the Symbol Selection Menu only when it's needed
	//Those variables are to assure the sound effect it's played just once when it's called
	bool playedWinEffect{ false };
	bool playedDrawEffect{ false };
	bool playedLostEffect{ false };
	std::vector<bool*> playedsSounds{ &playedWinEffect, &playedDrawEffect, &playedLostEffect}; //This is to change all the variables' values 
	
	//Music configurations
	float volumeMusic{ 0.4f };
	PlayMusicStream(menuMusic);
	SetMusicVolume(menuMusic, volumeMusic);

	//Set a FPS target
	SetTargetFPS(30);

	while (!WindowShouldClose())
	{
		//This is mandatory to play a music
		UpdateMusicStream(menuMusic);
		//Update the vulume all time
		SetMusicVolume(menuMusic, volumeMusic);

		BeginDrawing();
		ClearBackground(BLACK);
		//Back to The Main Menu
		if (IsKeyReleased(KEY_Q) == true)
		{
			dif = 0;
			mode = 0;
			configMode = 0;
			p.GetType() = 'P';
			g.ResetGame(pawns, playedsSounds, p);
		}
		//Go a page back when it's on the Configurations Menu
		else if (IsKeyReleased(KEY_P) == true)
			configMode = 0;
		//Draw Main Menu
		if (mode == 0)
		{
			mode = m.DrawMenu(volumeMusic);
		}
		//Draw Configuration Menu
		else if (mode == 3)
		{
			if (configMode == 0)
				configMode = m.DrawConfigs(); //ConfigMode gets the value of the pressed button

			else
			{
				switch (configMode)
				{
				case 1:
					m.DrawChagePawnColor(*x);
					break;
				case 2:
					m.DrawChagePawnColor(*o);
					break;
				case 3:
					if (volumeMusic == 0)
						volumeMusic = 0.4f;
					else
						volumeMusic = 0;
					configMode = 0;
					break;
				case 4:
					m.DrawManual();
					break;
				}
			}
		}
		else
		{
			//Draw the Select Symbol Menu
			if (p.GetType() == 'P' && mode == 2)
			{
				p.GetType() = m.DrawSymSelectionMenu(); //p.GetType will get the character returned from the method
	
				//Go a page back when it's on the Configurations Menu
				if (IsKeyReleased(KEY_P) == true)
				{
					configMode = 0;
					mode = 0;
				}
			}
			//Draw the Set Difficulty Menu
			else if (dif == 0 && mode == 2)
			{
				dif = m.DrawSetDifficulty();
				ai.SetDifficulty(dif);
			}
			//The Game
			else
			{
				t.DrawTable();

				//Draw X and O on the screen
				std::for_each(pawns.begin(), pawns.end(), [&t](auto pawn) { pawn->DrawSymbol(t); });

				//Win The Game Or Lost The Game
				if (g.DidWin(*x, m, p) == true || g.DidWin(*o, m, p) == true)
				{
					m.AdviceToRestart();
					if (mode == 2)
					{
						if (((p.GetType() == 'X' && p.GetWin() == false) || (p.GetType() == 'O' && p.GetWin() == false)) && playedLostEffect == false)
						{
							playedLostEffect = true;
							PlaySound(lostEffect);
						}
					
						else if (((p.GetType() == 'X' && p.GetWin() == true) || (p.GetType() == 'O' && p.GetWin() == true)) && playedWinEffect == false)
						{	
							PlaySound(winEffect);
							playedWinEffect = true;
						}
					}
					else
					{
						if (playedWinEffect == false)
						{
							PlaySound(winEffect);
							playedWinEffect = true;

						}
					}
					if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
						g.ResetGame(pawns, playedsSounds, p);
				}

				//Tie The Game
				else if (g.VerifyDraw(x) == true)
				{
					m.DrawTieText();
					m.AdviceToRestart();
					if (playedDrawEffect == false)
					{
						PlaySound(drawEffect);
						playedDrawEffect = true;
					}
					if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
						g.ResetGame(pawns, playedsSounds, p);
				}
				//Gameplay
				else
				{
					//The PvP
					if (mode == 1)
					{
						g.PvP(p, t, *x, *o);
					}
					//The PvAI
					else
					{
						g.PvAI(p,ai ,t, *x, *o);
					}
				}
				//Reset The Game
				if (IsKeyPressed(KEY_ENTER) == true)
					g.ResetGame(pawns, playedsSounds, p);
			}
		}
		EndDrawing();
	}
	delete x;
	delete o;
	UnloadSound(lostEffect);
	UnloadSound(winEffect);
	UnloadSound(drawEffect);
	UnloadImage(icon);
	CloseAudioDevice();
	CloseWindow();
	return 0;
}