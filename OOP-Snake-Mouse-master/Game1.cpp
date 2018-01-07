//--------------------------------
//include standard libraries
#include <iostream>		//for output and input
#include <string>		//for string
#include <sstream>		//for streamstring

//include class modules
#include "Mouse.h"
#include "Snake1.h"
#include "Underground.h"
#include "UserInterface.h"
#include"Game1.h"
#include"Player.h"
using namespace std;
void Game::set_up(UserInterface* pui) {
	//prepare game
	//set up the holes
	underground_.set_hole_no_at_position(0, 4, 3);
	underground_.set_hole_no_at_position(1, 15, 10);
	underground_.set_hole_no_at_position(2, 7, 15);
	//mouse state already set up in its contructor
	
	//set up snake
	snake_.position_at_random();
	snake_.spot_mouse(&mouse_);




	Nut.new_nut(8, 9);
	//snake_.moveTail.position_at_random();
	
	//set up the UserInterface
	p_ui = pui;
}

void Game::setPlayer(Player* ppl)
{
	player = ppl;
}


void Game::run()
{
	assert(p_ui != nullptr);
	p_ui->draw_grid_on_screen(prepare_grid(),
		player_Score());


	key_ = p_ui->get_keypress_from_user();

	while (!has_ended(key_))
	{
		if (is_arrow_key_code(key_) && !enableCheatMode())
		{
			mouse_.scamper(key_);
			snake_.chase_mouse();
			p_ui->draw_grid_on_screen(prepare_grid(), player_Score());
			apply_rules();
		}
		else

		if (enableCheatMode())
			{
				if (cheatmode == false)
				{
					cheatmode = true;
					cout << "\t\tCHEATMODE ENABLED \n";
					cout << "\t\t\t\tSnake has stopped moving!";
					p_ui->draw_grid_on_screen(prepare_grid(), player_Score());
					apply_rules();
				}
				else
				{
					cheatmode = false;
			

					cout << "\t\tCHEATMODE DISABLED ";
					cout << "\t\t\t\t				";

				}
			}
		
		
			
			//	else
			//	{
			//		cheatmode = false;
			//		//mouse_.scamper(key_);
			//		//snake_.chase_mouse();
			//		//p_ui->draw_grid_on_screen(prepare_grid(), player_Score());
			//		//apply_rules();
			//		cout << "\t\tCHEATMODE DISABLED ";
			//		cout << "\t\t\t\t                         ";
			//	}
				/*if (is_arrow_key_code(key_))
				{
					p_ui->draw_grid_on_screen(prepare_grid(), player_Score());
					apply_rules();
				}
			*/
			//else
			//{
			//	if (is_arrow_key_code(key_))
			//	{
			//		//mouse_.scamper(key_);
			//		//snake_.chase_mouse();
			//		p_ui->draw_grid_on_screen(prepare_grid(), player_Score());
			//		apply_rules();
			//	}
			//	else
			//	{
			//		cout << "\nInvalid Key!!";
			//		cout << "\n             ";
			//	}
			//}
	
				
			
			key_ = p_ui->get_keypress_from_user();
		}
		key_ = p_ui->get_keypress_from_user();
		p_ui->show_results_on_screen(prepare_end_message());
		p_ui->draw_grid_on_screen(prepare_grid(),player_Score());
}


string Game::prepare_grid() {
	//prepare a string that holds the grid information
	ostringstream os;

	for (int row(1); row <= SIZE; ++row)	//for each row (vertically)
	{
		for (int col(1); col <= SIZE; ++col)	//for each column (horizontally)
		{
			if ((row == snake_.get_y()) && (col == snake_.get_x()))
			{   
				snake_.moveTail();
				os << snake_.get_symbol();
				
		

			}


			else if ((row == mouse_.get_y()) && (col == mouse_.get_x()))
			{
				os << mouse_.get_symbol();	//show mouse
			}

			else if ((row == Nut.get_y()) && (col == Nut.get_x()) && (Nut.has_been_collected() == false))
			{
				os << Nut.get_symbol();	//show Nut
			}
			else
			{
				const int hole_no(find_hole_number_at_position(col, row));
				if (hole_no != -1)
				{
					os << underground_.get_hole_no(hole_no).get_symbol();	//show hole
				}
				
				else
				{
					os << FREECELL;	//show free grid cell
				}
			}

			for (int i = 0; i < snake_.tail_.size(); i++)
			{
				os << snake_.tail_.at(i).get_symbol();
				os << snake_.tail_.at(i).get_symbol();
				os << snake_.tail_.at(i).get_symbol();
				snake_.tail_.pop_back();
			}

		} 
		os << endl;
	} 
	return os.str();
} 

bool Game::is_arrow_key_code(const int keycode) const
{
	return (keycode == LEFT) || (keycode == RIGHT) || (keycode == UP) || (keycode == DOWN);
}

const int Game::find_hole_number_at_position(int x, int y) 
{
	for (int h_no(0); h_no < underground_.holes_.size(); ++h_no)
	{
		if (underground_.get_hole_no(h_no).is_at_position(x, y))
			return h_no;		//number of the hole
	}
	return -1;				//not a hole
}

void Game::apply_rules() 
{
	
	if (snake_.has_caught_mouse())
		{
		mouse_.die();
		

		if (player->getScoreAmount() > 0)
		{
			
			player->updateScoreAmount(-score);
		}
		else if (player->getScoreAmount() == 0)
		{
			score = 0;
			player->updateScoreAmount(score);
		}

	}

	
	else if (mouse_.has_reached_a_hole(underground_))
	{   
		if (Nut.has_been_collected())
		{
			mouse_.escape_into_hole();

			player->updateScoreAmount(score);
		}
	}
	else if (mouse_.can_collect_nut(Nut))
	{
		Nut.disappear();
	}
	
}
bool Game::enableCheatMode()
{
	return toupper(key_) == CHEAT;
}

bool Game::has_ended(const char& key) const
{
	return ((key == 'Q') || (!mouse_.is_alive()) || (mouse_.has_escaped()));
}

string Game::prepare_end_message() 
{
	ostringstream os;
	if (mouse_.has_escaped())
	{
		os << "\n\nEND OF GAME: THE MOUSE ESCAPED UNDERGROUND!";

	}
	else if (!mouse_.is_alive())
	{
		os << "\n\nEND OF GAME: THE SNAKE ATE THE MOUSE!";
	}
	else
	{
		os << "\n\nEND OF GAME: THE PLAYER ENDED THE GAME!" ;
	}
	return os.str();
}

string Game::player_Score() 
{ 
	ostringstream os;
	os << "\nPlayer Name:" + player->getName() + "\tScore:";
	os <<  player->getScoreAmount();
	return os.str();
};

ostream& Game::toFile(ostream& os) {  //save game into file
	os << "\nPlayer name: " + player->getName() << "\t Score: ";
	os <<  player->getScoreAmount();

	return os;
}
istream& Game::fromFile(istream& is) {   //read game from file

	//is >>  snake_.position_in_middle_of_grid;
	//is >>  mouse_.position_in_middle_of_grid;

	return is;
}
ostream& operator <<(ostream& os, Game& g)
{
	return(g.toFile(os));
}
istream& operator >>(istream&is, Game&g) {

	return(g.fromFile(is));
}