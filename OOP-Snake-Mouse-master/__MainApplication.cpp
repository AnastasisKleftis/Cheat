//include class modules
// all files now in a serperate module //
#include "Mouse.h"
#include "Snake1.h"
#include "Underground.h"
#include "UserInterface.h"
#include"Game1.h"
#include"Player.h"

UserInterface ui;
Player pl;

int main()
{
	char again;
	do
	{
		Game game;
		game.set_up(&ui);
		game.setPlayer(&pl);
		game.run();
		ui.hold_window();
		cout << "would you like to Play Again?";
		cin >> again;

		ofstream fout;
		fout.open("Game.txt", ios::out);
		if (fout.fail())
			cout << "\n An error has occured when opening the file";
		else
			fout << game;
		fout.close();
		ifstream fin;
		fin.open("Game.txt", ios::in);
		if (fin.fail())
			cout << "\n An error has occured when opening the file";
		else
			fin >> game;
		fin.close();

	} while (again == 'y' || again =='Y');
}

