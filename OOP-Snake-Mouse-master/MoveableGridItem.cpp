#include "MoveableGridItem.h"
MoveableGridItem::MoveableGridItem(const int x, const int y, const char& symbol):GridItem(symbol)
{}

const int MoveableGridItem::get_x() 
{    
	return x;
};

const int MoveableGridItem::get_y() 
{
	return y;
};
const bool MoveableGridItem::is_at_position(const int x_,const int y_)
{	
	return (x == x_) && (y == y_);
}

void MoveableGridItem::update_position(int &dx, int &dy)
{
	x += dx;
	y += dy;
}
void MoveableGridItem::setPrivateMember(const int dx, const int dy) 
{
	x = dx;
	y = dy;
}

void MoveableGridItem::position_in_middle_of_grid() 
{
	x = SIZE / 2;
	y = SIZE / 2;
}

void MoveableGridItem::position_at_random()
{
	x = rng_.get_random_value(SIZE);        //WARNING: may fall on mouse
	y = rng_.get_random_value(SIZE);
}





