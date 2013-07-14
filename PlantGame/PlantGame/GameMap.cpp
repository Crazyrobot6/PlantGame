#pragma once
#include "GameMap.h"

GameMap::GameMap(int x, int y, int z)
{
	this->x = x;
	this->y = y;
	this->z = z;
	for(int i=0; i<x; i++)	//x
		for(int j=0; j<y; j++) //y
		{
			for(int k=0; k<(z-1); k++) //z
			{
				blockMap[i][j][k] = new Block(1 + rand() % 3);	//Bottom layers are solid/whole with random soil type
			}
			for(int k=z-1; k<z; k++) //z
			{
				if(rand() % 2 && blockMap[i][j][k-1] != NULL)		//will randomly create some as long as the block below it is soil
					blockMap[i][j][k] = new Block(1 + rand() % 3);
				else
					blockMap[i][j][k] = NULL;
			}
		}

	blockImages[0] = al_load_bitmap("Bitmaps/Soil1.bmp");
	blockImages[1] = al_load_bitmap("Bitmaps/Soil2.bmp");
	blockImages[2] = al_load_bitmap("Bitmaps/Soil3.bmp");
	blockImages[3] = al_load_bitmap("Bitmaps/Soil4.bmp");
	for(int i=0;i<NUM_SOIL_TYPES;i++)
		al_convert_mask_to_alpha(blockImages[i], al_map_rgb(255,0,255)); //converts hideous magenta to transparent
	blockWidth = al_get_bitmap_width(blockImages[0]);
	blockHeight = al_get_bitmap_height(blockImages[0])-1; //-1 because it looks better;
	blockPerceivedHeight = 32;
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

void GameMap::draw(int camX, int camY, int camZ)
{
	//Draws all blocks that are missing a block above or in front of them
	for(int i=0; i<x-1; i++)	//x
		for(int j=0; j<y-1; j++) //y
			for(int k=0; k<camZ-1; k++)//z
				if(blockMap[i][j][k] != NULL && !(blockMap[i+1][j][k] != NULL && blockMap[i][j+1][k] != NULL && blockMap[i][j][k+1] != NULL))
					al_draw_bitmap(blockImages[blockMap[i][j][k]->getBitmap()],
						camX+((x-1)*blockWidth/2)+(i*blockWidth/2)-(j*blockWidth/2),
						camY+(camZ*blockPerceivedHeight)+((j+i)*(blockHeight-blockPerceivedHeight)/2)-((k)*(blockPerceivedHeight-4)),0);
	// draws fron right row
	for(int i=x-1; i<x; i++)	//x
		for(int j=0; j<y-1; j++) //y
			for(int k=0; k<camZ; k++)
				if(blockMap[i][j][k] != NULL)
					al_draw_bitmap(blockImages[blockMap[i][j][k]->getBitmap()],
						camX+((x-1)*blockWidth/2)+(i*blockWidth/2)-(j*blockWidth/2),
						camY+(camZ*blockPerceivedHeight)+((j+i)*(blockHeight-blockPerceivedHeight)/2)-((k)*(blockPerceivedHeight-4)),0);
	//draws front left row
	for(int i=0; i<x; i++)	//x
		for(int j=y-1; j<y; j++) //y
			for(int k=0; k<camZ; k++)
				if(blockMap[i][j][k] != NULL)
					al_draw_bitmap(blockImages[blockMap[i][j][k]->getBitmap()],
						camX+((x-1)*blockWidth/2)+(i*blockWidth/2)-(j*blockWidth/2),
						camY+(camZ*blockPerceivedHeight)+((j+i)*(blockHeight-blockPerceivedHeight)/2)-((k)*(blockPerceivedHeight-4)),0);
	//draws top layer
	for(int i=0; i<x; i++)	//x
		for(int j=0; j<y; j++) //y
			for(int k=camZ-1; k<camZ; k++)
				if(blockMap[i][j][k] != NULL)
					al_draw_bitmap(blockImages[blockMap[i][j][k]->getBitmap()],
						camX+((x-1)*blockWidth/2)+(i*blockWidth/2)-(j*blockWidth/2),
						camY+(camZ*blockPerceivedHeight)+((j+i)*(blockHeight-blockPerceivedHeight)/2)-((k)*(blockPerceivedHeight-4)),0);

				
}