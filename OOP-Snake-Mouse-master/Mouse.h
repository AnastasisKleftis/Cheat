// Mouse.h: UserInterface for the Mouse class
//////////////////////////////////////////////////////////////////////
//---------------------------------------------------------------------
// Date  10/12/2017      Programmer mMuni    Amendments made and justification (if needed)
//---------------------------------------------------------------------
// 
//
//---------------------------------------------------------------------
#if !defined(MouseH)
#define MouseH

#include "constants.h"
#include "Underground.h"
#include "nut.h"
#include "MoveableGridItem.h"

class Mouse :public MoveableGridItem 

{
	public:
			Mouse();
			Mouse::Mouse(int x, int y) :MoveableGridItem(x, y, MOUSE)
			{}
			bool is_alive() const;
			bool has_escaped() const;
			bool has_reached_a_hole(const Underground& ug);
			void die();
			void escape_into_hole();
			void scamper(char k);
			bool can_collect_nut(nut Nut);
			Underground underGround;
	private:
			//data members
			bool alive_;
			bool escaped_;
			int mouse_dx_;
			int mouse_dy_; 	
};

#endif // !defined(MouseH)
