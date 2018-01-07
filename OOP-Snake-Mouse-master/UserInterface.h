// UserInterface.h: UserInterface for the UserInterface class
//////////////////////////////////////////////////////////////////////
//---------------------------------------------------------------------
// Date       Programmer    Amendments made and justification (if needed)
//---------------------------------------------------------------------
// 
//
//---------------------------------------------------------------------

#if !defined(UserInterfaceH)
#define UserInterfaceH

//include standard libraries
#include <iostream>		//for output and input: cout << and cin >>
#include <string>		//for string
#include<fstream>		//for text files
using namespace std;
#include"player.h"

class UserInterface 
{
	public:
		int get_keypress_from_user() const;
		void draw_grid_on_screen(const string& grid_data,const string& name) const ;
		void show_results_on_screen(string message) const;
		void hold_window() const;
	private:
};

#endif // !defined(UserInterfaceH)