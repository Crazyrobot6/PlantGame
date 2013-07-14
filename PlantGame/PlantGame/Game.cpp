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

void Game::setMap(GameMap* newMap)
{
	map = newMap;
}
/*
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
	//map->draw();	//draws map
	al_draw_rectangle(100, 100, 200, 200, al_map_rgb(0,255,0), 20);
}

void Game::keyPressA()
{
	done = true;
}

void Game::keyPressD()
{
}

void Game::keyPressS()
{
}

void Game::keyPressW()
{
}