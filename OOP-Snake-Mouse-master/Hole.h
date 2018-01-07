#include "constants.h"
#include "FixedGridItem.h"

class Hole :public FixedGridItem

{
	public:
			//constructors
			const Hole();
			Hole::Hole(const int x,const int y):FixedGridItem(x,y,HOLE)  
			{}
	private:
			static const int MAXHOLES; //number of holes in underground
			char symbol_;
			int x_, y_;
};

