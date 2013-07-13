#pragma once
#include "Player.h"

Player::Player()
{
}

Player::~Player()
{
}

void Player::setName(std::string name)
{
	playerName = name;
}

std::string Player::getName()
{
	return playerName;
}

void Player::addToScore(int points)
{
	score += points;
}

int Player::getScore()
{
	return score;
}

void Player::giveMinerals(double amount)
{
	playerMinerals += amount;
}

double Player::getCurrentMinerals()
{
	return playerMinerals;
}

void Player::subtractMinerals(double amount)
{
	playerMinerals -= amount;
}

void Player::giveWater(double amount)
{
	playerWater += amount;
}

double Player::getCurrentWater()
{
	return playerWater;
}

void Player::subtractWater(double amount)
{
	playerWater -= amount;
}

std::vector<Unit*> Player::getUnits()
{
	return playersUnits;
}

EvoTree* Player::getEvoTree()
{
	return evoTree;
}