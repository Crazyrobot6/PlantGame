#pragma once

#include <vector>
#include "Block.h"
#include "Player.h"

class Player;
enum UNIT_CLASSES {TREE, FLOWER, BUSH};

class Unit
{
protected:
	int classID;	//Determines whether the unit is a flower, bush, or tree
	int unitID;		//The ID for this plant. different for EVERY unit on the map
	int hitPoints;	//Number of hitpoints the unit has
	int maxHitPoints;	//Max hp of a unit
	int level;		//Level of plant. Increases with mineral surplus
	Player* owner;	//Pointer to the player who owns the plant
	std::vector<Block*> ownedBlocks;	//The blocks that the plant has some ownership of; exact percentage is stored within the block
	int resilience;	//Maybe a measure of how hardy the plant is? How much it takes for it to start dying?
	int seeds;	//How many seeds are produced by the plant per cycle of seed production
	int mineralsUntilSeeds;	//Progress towards seed mineral-wise (can choose to put more minerals towards seeds or growth)
	int waterUntilSeeds;	//Progress towards seed water-wise (can choose to put more minerals towards seeds or growth)
	int mineralsUntilLevelUp;	//same^
	int waterUntilLevelUp;		//same^
	int mineralsStored; //stores excess minerals
	int waterStored;	//same^
	int waterPercentGrowth; //{0,100} Percent of water to be put toward growing, rest goes towards making seeds
	int mineralPercentGrowth; //{0,100} Percent of minerals to be put toward growing, rest goes towards making seeds

public:
	Unit() {}	//Initialization
	~Unit() {}	//Garbage collection
	void setID(int newID) {unitID = newID;}
	int getID() {return unitID;}
	int getClass() {return classID;}
	int getSize() {return level;}
	int getCurrentHitPoints() {return hitPoints;}	//Returns the plant's current hit points
	int getMaxHitPoints() {return maxHitPoints;}	//Returns the max hp of the plant
	void setOwner(Player* newOwner) {owner = newOwner;}	//Sets the player who owns the plant
	Player* getOwner() {return owner;}	//Returns the owner of the plant
	int getResilience() {return resilience;}	//Returns the defense stat of the plant
	int produceSeeds() {return 0;}	//Decrements turnsUntilSeeds or produces seeds if turnsUntilSeeds equals 0, in which case turnsUntilSeeds is reset
				//This way we can call produceSeeds() for all of a player's plants rather than
				//checking to see if they are ready to produce seeds
	void addBlock(Block* newBlock) {ownedBlocks.push_back(newBlock);}	//Adds another block to the list of blocks the plant posesses
	void removeBlock(Block* blockToRemove) {}	//Removes a block from the plant's ownership
	void virtual addMinerals() {level++;}	//Gets minerals from its soil blocks. Also calculates if it needs to make seeds and calculates level and stuff
};