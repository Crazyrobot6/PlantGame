#pragma once

#include <vector>
#include "Player.h"
#include "GameMap.h"
#include "GameOptions.h"
#include "GameState.h"

class Game : public GameState
{
private:
	int camX;	//Each player will have their own game class, so these variables can be in the Game class
	int camY;	//argggg, Imma pirate!!
	int camZ;
	int turnsTaken;	//The number of total turns taken in the game; increments once every time the game cycles through all the players
	int gameTime;	//Maybe this won't be an int, but this will be some variable that holds how long (real-time) the game has been running
    bool exitToStart;


public:
	Game();	//Does initialization, haven't thought through what arguments it might need
	~Game();	//Garbage collection

	void keyPressA();
	void keyPressD();
	void keyPressS();
	void keyPressW();
	void keyPressSpace();
	void scroll(int dz);
	
	int update();	//updates whatever needs it every sixtieth of a second (including 'time')
	void draw();	//Magical function that draws everything in-game to the screen
	/*
	These are unaccessable unless they become members of GameState, so instead, let's do these functions through
	keyPressA() and those types of fncts

	void setMap(GameMap* newMap);	//Sets the map for the game
	void setOptions(GameOptions* newOptions);	//Sets the options for the game; this will let us easily change the options mid-game (I think)

	int getTurnsTaken();	//Returns the number of turns taken during the game
	int getGameTime();	//Returns how long the game has been going on, might be nice to display this to the players
						//If there's a better way to store time than an int, let's do it
	*/					//Otherwise, maybe this can be an int that stores the length of time in seconds
};