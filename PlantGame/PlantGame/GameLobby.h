/*
This will server as the buffer between the StartMenu and the game
This will add all players to the game and establish a connection between each player and the host.
When the game is started, all necessary information will be passed on to the game class via parameters or temp file

INFO PASSED FOR HOST PC:
means to communicate with others
numplayers and their chosen class (tree, bush, etc.)
game map
more?
INFO PASSED FOR OTHER PLAYERS:
means to communicate with host
game map
more?
*/
#pragma once

#include <vector>
#include "Player.h"
#include "GameMap.h"
#include "GameOptions.h"
#include "GameState.h"

class GameLobby : public GameState
{
private:
	std::vector<Player*> players;
	bool startGame;
	bool exitToStart;
	GameOptions* options;//options for this game. (time per turn, max numTurns, etc)
	GameMap* map;		//Could be an acutal map, or a file location of a saved map
	bool writeToTemp();		//Writes info to temp file to be read by Game() returns true if it works
							//Writes whether or not this player is the host, then corresponding info
public:
	GameLobby();	//Will have to work for host and non-host joining host's lobby
	~GameLobby();

	int update();	//updates whatever needs it every sixtieth of a second (including 'time')
	void draw();	//Magical function that draws everything in-game to the screen
	
	void keyPressA();
	void keyPressD();
	void keyPressS();
	void keyPressW();
	void keyPressSpace();
	void scroll(int dz);
};