#pragma once
#include"GridItem.h"
#include"constants.h"
#include "RandomNumberGenerator.h"

class MoveableGridItem :public GridItem
{
	public:
	
			MoveableGridItem(const int x, const int y, const char & symbol);
			const int get_x();
			const int get_y();
			const bool is_at_position(const int x, const int y);
			void update_position(int &dx, int &dy);
			void setPrivateMember(const int dx, const  int dy);
			void position_in_middle_of_grid();
			void position_at_random();
			RandomNumberGenerator rng_;
	private:
			int x;
			int y;
};

