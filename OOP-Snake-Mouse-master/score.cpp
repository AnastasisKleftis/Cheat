#include "score.h"

void  score::updateAmount(int score)
{
	amount = amount + score;
}

const int score::get_amount()
{   
	return amount;
}