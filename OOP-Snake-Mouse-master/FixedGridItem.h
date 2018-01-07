#pragma once
#include"GridItem.h"

class FixedGridItem :public GridItem
{
public:
	FixedGridItem(const int x, const int y, const char& symbol);

	const int get_x();
	const int get_y();
	const bool is_at_position(const int x,const int y);

private:
	int x;
	int y;
	
};


