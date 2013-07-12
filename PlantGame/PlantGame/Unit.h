#pragma once

#include <vector>
#include "Block.h"
#include "Player.h"

enum UNIT_CLASSES {FLOWER, BUSH, TREE};

class Player;

class Unit
{
private:
	int hitPoints;	//Number of hitpoints the unit has
	int maxHitPoints;	//Max hp of a unit
	Player* owner;	//Pointer to the player who owns the plant
	std::vector<Block*> ownedBlocks;	//The blocks that the plant has some ownership of; exact percentage is stored within the block
	int defense;	//Maybe a measure of how hardy the plant is? How much it takes for it to start dying?
	int seeds;	//How many seeds are produced by the plant per cycle of seed production
	int turnsUntilSeeds;	//How many more turns until the plant produces another batch of seeds
	
public:
	Unit();	//Initialization
	~Unit();	//Garbage collection
	int getCurrentHitPoints();	//Returns the plant's current hit points
	void restoreHitPoints(int amount);	//Restores a given amount of the plant's hit points
	void subtractHitPoints(int amount);	//Removes a given amount of the plant's hit points
	int getMaxHitPoints();	//Returns the max hp of the plant
	void setOwner(Player* newOwner);	//Sets the player who owns the plant
	Player* getOwner();	//Returns the owner of the plant
	int getDefense();	//Returns the defense stat of the plant
	int produceSeeds();	//Decrements turnsUntilSeeds or produces seeds if turnsUntilSeeds equals 0, in which case turnsUntilSeeds is reset
				//This way we can call produceSeeds() for all of a player's plants rather than
				//checking to see if they are ready to produce seeds
	void addBlock(Block* newBlock);	//Adds another block to the list of blocks the plant posesses
	void removeBlock(Block* blockToRemove);	//Removes a block from the plant's ownership

protected:
	int classID;	//Determines whether the unit is a flower, bush, or tree
};
