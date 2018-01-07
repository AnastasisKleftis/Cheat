#pragma once
#include "Player.h"
#include <string>		//for string
#include <sstream>		//for streamstring
#include "score.h"
using namespace std;

class Player
{
public:
	Player();
	const string getName();
	score scores;
	const int getScoreAmount();
	void updateScoreAmount(const int);
private:
	string name;
};

