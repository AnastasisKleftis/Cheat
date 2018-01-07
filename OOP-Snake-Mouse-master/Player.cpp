#include "Player.h"
#include <string>		//for string
#include <sstream>		//for streamstring
#include <iostream>
using namespace std;

Player::Player()
{
	cout << "ENTER PLAYER NAME";
	cin >> name; 
}

const string Player::getName()
{
	return name;
}
void Player::updateScoreAmount(const int score)
{
	scores.updateAmount(score);
}


const int Player::getScoreAmount()
{
	int score = scores.get_amount();
	return score;
}




