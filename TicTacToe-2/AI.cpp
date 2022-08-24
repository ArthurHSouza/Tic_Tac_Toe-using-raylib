#include "AI.h"

void AI::Play(std::vector<bool> &aiQuads,std::vector<bool> eQuads)
{
	srand(time(NULL)); //Get a random number

	int randomQuad = rand() % 9;
	int odds = rand() % 100; //A random number between 0 and 100
	bool condReaction{ false };
	bool attackfailed{ false };

	//A strategy when the AI is at level 3
	int eTimesPlayed = 0;
	for (int i = 0; i < eQuads.size(); i++)
	{
		if (eQuads.at(i) == true)
			eTimesPlayed++;
	}
	if (difficulty == 3 && eTimesPlayed == 1 && 
		(eQuads.at(0) == true || eQuads.at(2) == true || eQuads.at(6) == true || eQuads.at(8) == true))
	{
		aiQuads.at(4) = true;
		return;
	}

	//Random attack the player
	while ((eQuads.at(randomQuad) == true || aiQuads.at(randomQuad) == true))
	{
		randomQuad = rand() % 9;
	}

	//Horizontal
	//Attack
	for (int i = 0; i < 7; i += 3)
	{
		if (odds < oddsToAttack)
		{
			if (aiQuads.at(i) == true && aiQuads.at(i + 1) == true && eQuads.at(i + 2) == false)
			{
				aiQuads.at(i + 2) = true;
				return;
			}
			else if (aiQuads.at(i + 2) == true && aiQuads.at(i + 1) == true && eQuads.at(i) == false)
			{
				aiQuads.at(i) = true;
				return;
			}
			else if (aiQuads.at(i + 2) == true && aiQuads.at(i) == true && eQuads.at(i + 1) == false)
			{
				aiQuads.at(i + 1) = true;
				return;
			}
			else
			{
				attackfailed = true;
			}
		}
		else
			attackfailed = true;
	}
	//Defense
	for (int i = 0; i < 7; i += 3)
	{
		if (odds < oddsToDefense && attackfailed == true)
		{
			if (eQuads.at(i) == true && eQuads.at(i + 2) == true && aiQuads.at(i + 1) == false)
			{
				aiQuads.at(i + 1) = true;
				condReaction = true;
				//odds = rand() % 100;
				return;
			}
			else if (eQuads.at(i) == true && eQuads.at(i + 1) == true && aiQuads.at(i + 2) == false)
			{
				aiQuads.at(i + 2) = true;
				condReaction = true;
				//odds = rand() % 100;
				return;
			}
			else if (eQuads.at(i + 2) == true && eQuads.at(i + 1) == true && aiQuads.at(i) == false)
			{
				aiQuads.at(i) = true;
				condReaction = true;
				//odds = rand() % 100;
				return;
			}
		}
	}
	attackfailed = false;

	//vertical
	//Attack
	for (int i = 0; i < 3; i++)
	{
		if (odds < oddsToAttack)
		{
			if (aiQuads.at(i) == true && aiQuads.at(i + 3) == true && eQuads.at(i + 6) == false)
			{
				aiQuads.at(i + 6) = true;
				return;
			}
			else if (aiQuads.at(i + 3) == true && aiQuads.at(i + 6) == true && eQuads.at(i) == false)
			{
				aiQuads.at(i) = true;
				return;
			}
			else if (aiQuads.at(i) == true && aiQuads.at(i + 6) == true && eQuads.at(i + 3) == false)
			{
				aiQuads.at(i + 3) = true;
				return;
			}
			else
			{
				attackfailed = true;
			}
		}
		else
			attackfailed = true;
	}
	//Defense
	for (int i = 0; i < 3; i++)
	{
		
		if (odds < oddsToDefense && attackfailed == true)
		{
			if (eQuads.at(i) == true && eQuads.at(i + 6) == true && aiQuads.at(i + 3) == false)
			{
				aiQuads.at(i + 3) = true;
				condReaction = true;
				//odds = rand() % 100;
				return;
			}
			else if (eQuads.at(i) == true && eQuads.at(i + 3) == true && aiQuads.at(i + 6) == false)
			{
				aiQuads.at(i + 6) = true;
				condReaction = true;
				//odds = rand() % 100;
				return;
			}
			else if (eQuads.at(i + 6) == true && eQuads.at(i + 3) == true && aiQuads.at(i) == false)
			{
				aiQuads.at(i) = true;
				condReaction = true;
				//odds = rand() % 100;
				return;
			}
		}
	}
	attackfailed = false;

	//Diagonal left up to right botton
	//Attack
	if (odds < oddsToAttack)
	{
		if (aiQuads.at(0) == true && aiQuads.at(4) == true && eQuads.at(8) == false)
		{
			aiQuads.at(8) = true;
			return;
		}
		else if (aiQuads.at(8) == true && aiQuads.at(4) == true && eQuads.at(0) == false)
		{
			aiQuads.at(0) = true;
			return;
		}
		else if (aiQuads.at(0) == true && aiQuads.at(8) == true && eQuads.at(4) == false)
		{
			aiQuads.at(4) = true;
			return;
		}
		else
		{
			attackfailed = true;
		}
	}
	else
		attackfailed = true;
	//Defense
	if (odds < oddsToDefense && attackfailed == true)
	{
		if (eQuads.at(0) == true && eQuads.at(8) == true && aiQuads.at(4) == false && odds < oddsToDefense)
		{
			aiQuads.at(4) = true;
			condReaction = true;
			//odds = rand() % 100;
			return;
		}
		else if (eQuads.at(0) == true && eQuads.at(4) == true && aiQuads.at(8) == false && odds < oddsToDefense)
		{
			aiQuads.at(8) = true;
			condReaction = true;
			//odds = rand() % 100;
			return;
		}
		else if (eQuads.at(8) == true && eQuads.at(4) == true && aiQuads.at(0) == false && odds < oddsToDefense)
		{
			aiQuads.at(0) = true;
			condReaction = true;
			//odds = rand() % 100;
			return;
		}
		else
		{
			attackfailed = false;
		}
	}

	//Diagonal left botton to right up
	//Attack
	if (odds < oddsToAttack)
	{
		if (aiQuads.at(6) == true && aiQuads.at(4) == true && eQuads.at(2) == false)
		{
			aiQuads.at(2) = true;
			return;
		}
		else if (aiQuads.at(2) == true && aiQuads.at(4) == true && eQuads.at(6) == false)
		{
			aiQuads.at(6) = true;
			return;
		}
		else if (aiQuads.at(6) == true && aiQuads.at(2) == true && eQuads.at(4) == false)
		{
			aiQuads.at(4) = true;
			return;
		}
		else
		{
			attackfailed = true;
		}
	}
	else
		attackfailed = true;

	//Defense
	if (odds < oddsToDefense && attackfailed == true)
	{
		if (eQuads.at(2) == true && eQuads.at(6) == true && aiQuads.at(4) == false && odds < oddsToDefense)
		{
			aiQuads.at(4) = true;
			condReaction = true;
			//odds = rand() % 100;
		}
		else if (eQuads.at(6) == true && eQuads.at(4) == true && aiQuads.at(2) == false && odds < oddsToDefense)
		{
			aiQuads.at(2) = true;
			condReaction = true;
			//odds = rand() % 100;
		}
		else if (eQuads.at(2) == true && eQuads.at(4) == true && aiQuads.at(6) == false && odds < oddsToDefense)
		{
			aiQuads.at(6) = true;
			condReaction = true;
			//odds = rand() % 100;
		}
		else
		{
			attackfailed = false;
		}
	}

	if (condReaction == false)
		aiQuads.at(randomQuad) = true;
}

void AI::SetDifficulty(int& dif)
{
	switch (dif)
	{
	case 1:
		oddsToAttack = 25;
		oddsToDefense = 30;
		break;
	case 2:
		oddsToAttack = 40;
		oddsToDefense = 50;
		break;
	case 3:
		oddsToAttack = 110;
		oddsToDefense = 110;
		break;
	}
	difficulty = dif;
}