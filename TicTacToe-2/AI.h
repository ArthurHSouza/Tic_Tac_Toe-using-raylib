#pragma once
#include "raylib.h"
#include <vector>
#include <stdlib.h>
#include <time.h> 
#include <iostream>
class AI
{
	int difficulty {0};
	int oddsToDefense{ 0 };
	int oddsToAttack{ 0 };
public:
	void Play(std::vector<bool>& aiQuads, std::vector<bool> eQuads);
	void SetDifficulty(int &dif);
};


