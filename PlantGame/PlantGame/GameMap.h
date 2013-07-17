#pragma once

#include <vector>
#include "Block.h"
#include "Player.h"

enum CAMERA_ANGLES {NORTH_WEST, NORTH_EAST, SOUTH_WEST, SOUTH_EAST};

class GameMap
{
private:
	int numPlayers;		//Number of players that fit on this map
	std::vector<Player*> players;	//The players in this game
	Block *blockMap[10][10][8];	//Three dimensional game-world map
				//For now this is a 10x10x8 array to make it easier
	ALLEGRO_BITMAP *blockImages[NUM_SOIL_TYPES];
	int blockWidth;		//the width of the image
	int blockHeight;	//the height of the image
	int blockPerceivedHeight;	//the height that the block looks like it has in the image (if it were 3D)
	int x;	//Dimension along the east-west axis
	int y;	//Dimension along the north-south axis
	int z;	//Dimension along the up-down axis
	int angleID;
        
public:
	GameMap(int x, int y, int z);	//Creates an x by y by z map
	~GameMap();
	bool addPlayer(Player* newPlayer);
	std::vector<Player*> getPlayers() {return players;}
	int getNumPlayers() {return players.size();}
	Block* getBlock(int camX, int camY, int camZ);	//Returns pointer to block at coordinate (x, y, z)
	void draw(int x, int y,int z);	//Draws based on camera position
};
