#pragma once
#include "Block.h"

Block::Block(int id)	//Initializes values minearls/water based on ID passed
{
}

Block::~Block()	//Does whatever garbage collection is needed
{
}

ALLEGRO_BITMAP* Block::getBitmap()	//Returns the bitmap so the block can be drawn
{
	return images[blockID];
}

double Block::givePlayerMinerals(int unitNum)	//See function definition for explanation
{
	/*	
		Each player will be assigned a number
		Say there are four players in a game, they will be 0 through 3, taking turns in that order
		This gives player number playerNum the percentage of the resources they are owed
		It also deducts the amount from what is available to the block
		
		The materials will be given to the player like this:
		Player.addMinerals(someBlock.givePlayerMinerals(Player.getPlayerNumber()));
	*/
	double percentage = numUnitRoots[unitNum];
	double amountToGive = percentage * mineralsGivenPerTurn;
	mineralsAvailable -= amountToGive;
	return amountToGive;
}

double Block::givePlayerWater(int unitNum)
{
	double percentage = numUnitRoots[unitNum];
	double amountToGive = percentage * waterGivenPerTurn;
	waterAvailable -= amountToGive;
	return amountToGive;
}

void Block::replenishResources()
{
	mineralsAvailable += mineralsReplenishedPerTurn;
	waterAvailable += waterReplenishedPerTurn;
}