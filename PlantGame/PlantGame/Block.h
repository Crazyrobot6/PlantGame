#pragma once

#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include <vector>
#include <string>

enum blockIDS {SOIL1, SOIL2, SOIL3, SOIL4}; //AIR is NULL pointer, see GameMap
const int NUM_SOIL_TYPES = 4;
const int MAX_PLAYERS = 8;

class Block
{
private:
	int blockID;				//Pretty obvious -- an ID describing what type of block it is
	ALLEGRO_BITMAP* images[NUM_SOIL_TYPES];		//File path for the corresponding bitmap image
	int mineralsAvailable;		//How many minerals are currently available in the soil block
	int mineralsGivenPerTurn;	//How many total minerals the block gives per turn -- to be divided up among players
	int mineralsReplenishedPerTurn;	//How many minerals are given to the block after each turn cycle
	int waterAvailable;		//How much water is currently available in the soil block
	int waterGivenPerTurn;	//How much total water the block gives per turn -- to be divided up among players
	int waterReplenishedPerTurn;	//How much water is given to the block after each turn cycle
	std::vector<int> numUnitRoots;	//Array of intes giving the number of roots of each unit in the block
	//Each unit has an id, given to it at creation. Every time a unit is created, an int is added (starting at 0) for every block

public:
	Block(int id);	//Initializes values minearls/water based on ID passed
	~Block();	//Does whatever garbage collection is needed
	ALLEGRO_BITMAP* getBitmap();	//Returns the bitmap so the block can be drawn	//Maybe do a Render(int x, int y) instead of getBitmap()??
	//either here or in GameMap, we need to add functionality to draw the unit on top of the block right after drawing that block
	double givePlayerMinerals(int playerNum);	//See function definition for explanation
	double givePlayerWater(int playerNum);
	void replenishResources();	//To be called after all players have taken their turns
};