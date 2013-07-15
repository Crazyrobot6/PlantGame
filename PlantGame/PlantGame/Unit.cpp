#pragma once
#include "Unit.h"

Unit::Unit()
{
}

Unit::~Unit()
{
}

int Unit::getID()
{
	return unitID;
}

int Unit::getCurrentHitPoints()
{
	return hitPoints;
}

void Unit::restoreHitPoints(int amount)
{
	hitPoints += amount;
}

void Unit::subtractHitPoints(int amount)
{
	hitPoints -= amount;
}

int Unit::getMaxHitPoints()
{
	return maxHitPoints;
}

void Unit::setOwner(Player* newOwner)
{
	owner = newOwner;
}

Player* Unit::getOwner()
{
	return owner;
}

int Unit::getResilience()
{
	return resilience;
}

int Unit::produceSeeds()
{
	return 0;
}

void Unit::addBlock(Block* newBlock)
{
	ownedBlocks.push_back(newBlock);
}

void Unit::removeBlock(Block* blockToRemove)
{
	//Erase the block from the vector of owned blocks
	//akin to roots dying
}