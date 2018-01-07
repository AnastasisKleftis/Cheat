#include "constants.h"
#include "nut.h"

void nut::new_nut(const int x_, const int y_)
{
	x = x_;
	y = y_;
	setPrivateMember(x_, y_);
}

const bool nut::has_been_collected()
{
	return collected;
}


void nut::disappear()
{
	collected = true;
}
//Need to ask jamie what functionality he wants here



