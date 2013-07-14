#pragma once
#include "Game.h"

Game::Game()
{
	mouseX = 0;
	mouseY = 0;
	numberOfPlayers = 0;	//starts at zero, incrememnts with calls of addPlayer()
	gameTime = 0;
	turnsTaken = 0;
	font36 = al_load_ttf_font("Fonts/A_Sensible_Armadillo.ttf", 36, 0);
	done = false;
	map = new GameMap(10,10,5);
	camX = 0;
	camY = 0;
	camZ = 3;
}

Game::~Game()
{
	delete map;
	delete options;
	al_destroy_font(font36);
}

void Game::addPlayer(Player* newPlayer)
{
	players.push_back(newPlayer);
	numberOfPlayers++;
}
/*
void Game::setMap(GameMap* newMap)
{
	map = newMap;
}

void Game::setOptions(GameOptions* newOptions)
{
	options = newOptions;
}
*/
int Game::getTurnsTaken()
{
	return turnsTaken;
}

int Game::getGameTime()
{
	return gameTime;
}

int Game::update()
{
	gameTime++;
	if(done)
		return 2;
	return -1;
}

void Game::draw()
{
	map->draw(camX,camY,camZ);	//draws map
	al_draw_text(font36, al_map_rgb(100,0,100), 25,25,0, "Press Space to toggle through Game States");
	al_draw_text(font36, al_map_rgb(100,0,100), 25,60,0, "This is the game.");
}

void Game::keyPressA()
{
	camX += 100;
}

void Game::keyPressD()
{
	camX -= 100;
}

void Game::keyPressS()
{
	camY -= 100;
}

void Game::keyPressW()
{
	camY += 100;
}

void Game::keyPressSpace()
{
	done = true;
}

void Game::scroll(int dz)
{
	camZ += dz;			//camZ changes by whatever the mousewheel changed by
	if(camZ < 1)
		camZ = 1;		//These are
	else if(camZ > 5)		//to keep camZ in bounds
		camZ = 5;
	else camY += dz * -32;	//to make it look like the blocks are actually going on top of eachother
}