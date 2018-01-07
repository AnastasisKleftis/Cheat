#pragma once
#include "constants.h"
#include "MoveableGridItem.h"

class nut : public MoveableGridItem

{
	private:
			int x, y;
			bool collected;
	public:
			nut():MoveableGridItem(x, y, Nuts) 
			{};
			void new_nut(const int x, const int y);
			const bool has_been_collected();
			void disappear();
};