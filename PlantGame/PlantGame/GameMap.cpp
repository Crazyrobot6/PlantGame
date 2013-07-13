#pragma once
#include "GameMap.h"

GameMap::GameMap(int x, int y, int z)
{
	this->x = x;
	this->y = y;
	this->z = z;
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

void GameMap::setBlocks(std::vector<std::vector<std::vector<Block*>>>* newMap)
{
	//This function takes a pointer to a 3D vector of pointers
	//which it then dereferences
	//and stores the vector to which it points
	blockMap = *newMap;
}

Block* GameMap::getBlock(int x, int y, int z)
{
	return blockMap[x][y][z];
}

void GameMap::draw()
{
}