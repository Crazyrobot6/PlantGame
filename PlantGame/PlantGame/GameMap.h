#pragma once

#include <vector>
#include "Block.h"

enum CAMERA_ANGLES {NORTH_WEST, NORTH_EAST, SOUTH_WEST, SOUTH_EAST};

class GameMap
{
private:
	std::vector<std::vector<std::vector<Block*>>> blockMap;	//Three dimensional game-world map
	int x;	//Dimension along the east-west axis
	int y;	//Dimension along the north-south axis
	int z;	//Dimension along the up-down axis
	int angleID;
        
public:
	GameMap(int x, int y, int z);	//Creates an x by y by z map of null pointers
	~GameMap();
	void setCameraAngle(int newAngleID);	//Sets the angle from which the map is viewed
	void setDimensions(int x, int y, int z);	//Sets dimensions of the map
	void setBlocks(std::vector<std::vector<std::vector<Block*>>>* newMap);	//Sets the actual blocks within the map
	Block* getBlock(int x, int y, int z);	//Returns pointer to block at coordinate (x, y, z)
	void draw();	//Code for drawing the map to the screen; probably pass a pointer to the display
};
