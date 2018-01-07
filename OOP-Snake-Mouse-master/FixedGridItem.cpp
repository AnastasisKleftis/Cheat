#include "FixedGridItem.h"
FixedGridItem::FixedGridItem(const int x_, const int y_, const char& symbol):GridItem(symbol)
{
	x = x_;
	y = x_;
}
const bool FixedGridItem::is_at_position(const int x_, const int y_)
{
	return (x == x_) && (y == y_);
};

const int FixedGridItem::get_x() 
{
	return x;
};
const int FixedGridItem::get_y() 
{
	return y;
};