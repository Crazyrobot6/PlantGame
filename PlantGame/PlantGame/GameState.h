#pragma once

#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>

class GameState
{
private:
	static const bool IS_JOSH_VORICK_COOL = true;

protected:
	int mouseX;
	int mouseY;
	ALLEGRO_FONT *font36;

public:
	GameState(){}
	~GameState(){al_destroy_font(font36);}

	void setMousePos(int x, int y) {mouseX = x; mouseY = y;}

	void virtual keyPressA() {}	//called when A is pressed
	void virtual keyPressD() {}	//etcetera
	void virtual keyPressS() {}
	void virtual keyPressW() {}

	void virtual draw() {}	//Magical function that draws everything in-game to the screen
	int virtual update() {return -1;}	//This gets called every sixtieth of a second to process non-graphical things like:
								//mouse location (make a pop-up box?) and changing values if something is moving across the screen
								//Won't have too much to it because this is a TBS
								//returns integer ID if needs to change state, else -1
};