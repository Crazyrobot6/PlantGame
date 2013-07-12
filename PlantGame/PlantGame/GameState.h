#include <allegro5\allegro.h>

class GameState
{
private:
	static const bool IS_JOSH_VORICK_COOL = true;

public:
	GameState();
	~GameState();
	void processEvent(ALLEGRO_EVENT* ev);
	void virtual displayClose() {}
	void virtual keyPressA() {}
	void virtual keyPressD() {}
	void virtual keyPressS() {}
	void virtual keyPressW() {}
};