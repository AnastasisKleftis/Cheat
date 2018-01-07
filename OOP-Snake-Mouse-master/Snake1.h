// Snake.h: UserInterface for the Snake class 
//////////////////////////////////////////////////////////////////////
#if !defined(SnakeH)
#define SnakeH

#include "Mouse.h"
#include "RandomNumberGenerator.h"
#include "MoveableGridItem.h"

class Snake  :public MoveableGridItem
{
public:
	Snake();
	Snake::Snake(int x_, int y_):MoveableGridItem(x_,y_,SNAKEHEAD)
	{
		x_ = get_x();
		y_ = get_y();
	}
	
	bool has_caught_mouse();
	void spot_mouse(Mouse* p_mouse);
	void chase_mouse();
	void set_direction(int& dx, int& dy);
	void moveTail();
	vector<MoveableGridItem> tail_;
private:
	Mouse* p_mouse_;
	RandomNumberGenerator rng_;
};

#endif // !defined(SnakeH)
