#include "GameState.h"

GameState::GameState()
{
}

GameState::~GameState()
{
}

void GameState::processEvent(ALLEGRO_EVENT* ev)
{
	if (ev->type == ALLEGRO_EVENT_DISPLAY_CLOSE)
	{
		displayClose();
	}
	else if (ev->type == ALLEGRO_EVENT_KEY_DOWN)
	{
		switch (ev->keyboard.keycode)
		{
		case ALLEGRO_KEY_A:
			keyPressA();
			break;
		case ALLEGRO_KEY_D:
			keyPressD();
			break;
		case ALLEGRO_KEY_S:
			keyPressS();
			break;
		case ALLEGRO_KEY_W:
			keyPressW();
			break;
		}
	}
}