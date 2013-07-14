#pragma once
#include "GameMap.h"

GameMap::GameMap(int x, int y, int z)
{
	this->x = x;
	this->y = y;
	this->z = z;
	for(int i=0; i<x; i++)	//x
		for(int j=0; j<y; j++) //y
			for(int k=0; k<z; k++) //z
			{
				blockMap[i][j][k] = new Block(1);
			}
	blockImages[0] = al_load_bitmap("Bitmaps/Soil1.bmp");
	blockImages[1] = al_load_bitmap("Bitmaps/Soil2.bmp");
	blockImages[2] = al_load_bitmap("Bitmaps/Soil3.bmp");
	blockImages[3] = al_load_bitmap("Bitmaps/Soil4.bmp");
	for(int i=0;i<NUM_SOIL_TYPES;i++)
		al_convert_mask_to_alpha(blockImages[i], al_map_rgb(255,0,255)); //converts hideous magenta to transparent
}

GameMap::~GameMap()
{
}

void GameMap::setCameraAngle(int newAngleID)
{
	angleID = newAngleID;
}

void GameMap::setDimensions(int x, int y, int z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}
/*
void GameMap::setBlocks(std::vector<std::vector<std::vector<Block*>>>* newMap)
{
	//This function takes a pointer to a 3D vector of pointers
	//which it then dereferences
	//and stores the vector to which it points
	blockMap = *newMap;
}
*/ //Implement this later, but for now imma comment it out so it doesn't confuse me ;D
Block* GameMap::getBlock(int x, int y, int z)
{
	return blockMap[x][y][z];
}

void GameMap::draw()
{
	al_draw_bitmap(blockImages[blockMap[0][0][0]->getBitmap()], 250,250,0);
}