#include "Game.h"

Game::Game()
{
}

Game::~Game()
{
}

void Game::addPlayer(Player* newPlayer)
{
	players.push_back(newPlayer);
}

void Game::setMap(GameMap* newMap)
{
	map = newMap;
}

void Game::setOptions(GameOptions* newOptions)
{
	options = newOptions;
}

int Game::getTurnsTaken()
{
	return turnsTaken;
}

int Game::getGameTime()
{
	return gameTime;
}

void Game::incrementGameClock()
{
	gameTime++;
}

void Game::draw()
{
}

void Game::displayClose()
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