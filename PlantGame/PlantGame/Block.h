#pragma once

#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include <vector>
#include <string>

enum blockIDS {AIR, SOIL1, SOIL2, SOIL3, SOIL4};

class Block
{
private:
	int blockID;				//Pretty obvious -- an ID describing what type of block it is
	ALLEGRO_BITMAP* image;				//File path for the corresponding bitmap image
	int mineralsAvailable;		//How many minerals are currently available in the soil block
	int mineralsGivenPerTurn;	//How many total minerals the block gives per turn -- to be divided up among players
	int mineralsReplenishedPerTurn;	//How many minerals are given to the block after each turn cycle
	int waterAvailable;		//How much water is currently available in the soil block
	int waterGivenPerTurn;	//How much total water the block gives per turn -- to be divided up among players
	int waterReplenishedPerTurn;	//How much water is given to the block after each turn cycle
	std::vector<double> percentControlledByPlayer;	//Array of doubles giving the percent owned by each player as a decimal

	Block* below;	//Pointers for adjacent blocks; will be initialized to null
	Block* above;
	Block* north;
	Block* south;
	Block* east;
	Block* west;

public:
	Block(int id);	//Initializes values minearls/water based on ID passed
	~Block();	//Does whatever garbage collection is needed
	Block* getBelow();	//Self-explanatory
	Block* getAbove();
	Block* getNorth();
	Block* getSouth();
	Block* getEast();
	Block* getWest();
	ALLEGRO_BITMAP* getBitmap();	//Returns the bitmap so the block can be drawn
	double givePlayerMinerals(int playerNum);	//See function definition for explanation
	double givePlayerWater(int playerNum);
	void replenishResources();	//To be called after all players have taken their turns
};