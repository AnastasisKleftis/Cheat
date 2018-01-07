
#if !defined(GameH)
#define GameH
#include "Mouse.h"
#include "Snake.h"
#include "Userinterface.h"
#include "nut.h"
class Game
{
public:
	void set_up(UserInterface* pui);
	void run();
	bool enableCheatMode();
	bool cheatmode = false;
	void setPlayer(Player* ppl);
	ostream& toFile(ostream& os);
	istream& fromFile(istream& is);
	
private:
	Underground underground_;
	const int find_hole_number_at_position(const int x, const int y);
	Mouse mouse_;
	Snake snake_;
	int key_;
	bool is_arrow_key_code(const int keycode) const;
	bool has_ended(const char& key) const;
	void apply_rules();
	string prepare_grid();
	string prepare_end_message();
	string player_Score();
	int score = 1;
	nut Nut;
	Player* player;
	UserInterface* p_ui;
};

ostream& operator<<(ostream&, Game&);
istream& operator>>(istream&, Game&);
#endif // !defined(SnakeH)

