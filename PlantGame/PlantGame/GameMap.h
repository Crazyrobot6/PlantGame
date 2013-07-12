#pragma once

#include <vector>
#include "Block.h"

enum CAMERA_ANGLES {NORTH_WEST, NORTH_EAST, SOUTH_WEST, SOUTH_EAST};

class GameMap
{
private:
        vector<vector<vector<Block*>>> blockMap;        //Three dimensional game-world map
        int x;  //Dimension along the east-west axis
        int y;  //Dimension along the north-south axis
        int z;  //Dimension along the up-down axis
        
public:
        GameMap(int x, int y, int z);   //Creates an x by y by z map of null pointers
        ~GameMap();
        setCameraAngle(int angleID);    //Sets the angle from which the map is viewed
        draw(); //Code for drawing the map to the screen; probably pass a pointer to the display
        
};
