#pragma once

#include <vector>
#include "Block.h"

enum CAMERA_ANGLES {NORTH_WEST, NORTH_EAST, SOUTH_WEST, SOUTH_EAST};

class GameMap
{
private:
	Block *blockMap[10][10][5];	//Three dimensional game-world map
				//For now this is a 10x10x5 array to make it easier
	ALLEGRO_BITMAP *blockImages[NUM_SOIL_TYPES];
	int blockWidth;		//the width of the image
	int blockHeight;	//the height of the image
	int blockPerceivedHeight;	//the height that the block looks like it has in the image (if it were 3D)
	int x;	//Dimension along the east-west axis
	int y;	//Dimension along the north-south axis
	int z;	//Dimension along the up-down axis
	int angleID;
        
public:
	GameMap(int x, int y, int z);	//Creates an x by y by z map of null pointers
	~GameMap();
	void draw(int x,int y,int z);	//Draws based on camera position
	void setCameraAngle(int newAngleID);	//Sets the angle from which the map is viewed
	void setDimensions(int x, int y, int z);	//Sets dimensions of the map
	void setBlocks(std::vector<std::vector<std::vector<Block*>>>* newMap);	//Sets the actual blocks within the map
	Block* getBlock(int camX,int camY, int camZ);	//Returns pointer to block at coordinate (x, y, z)
};
