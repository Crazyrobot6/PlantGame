#pragma once
#include "Game.h"

Game::Game()
{
}

Game::~Game()
{
	delete map;
	delete options;
}

void Game::addPlayer(Player* newPlayer)
{
	players.push_back(newPlayer);
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
	return -1;
}

void Game::draw()
{
}

void Game::keyPressA()
{
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