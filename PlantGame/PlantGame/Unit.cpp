#include "Unit.h"

Unit::Unit()
{
}

Unit::~Unit()
{
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

int Unit::getDefense()
{
	return defense;
}

int Unit::produceSeeds()
{
	if (turnsUntilSeeds > 0)
	{
		turnsUntilSeeds--;
		return 0;
	}
	else
	{
		//Give turnsUntilSeeds some non-zero value
		return seeds;
	}
}

void Unit::addBlock(Block* newBlock)
{
	ownedBlocks.push_back(newBlock);
}

void Unit::removeBlock(Block* blockToRemove)
{
	//Erase the block from the vector of owned blocks
}