#pragma once

#include <vector>
#include "Player.h"
#include "GameMap.h"
#include "GameOptions.h"

class Game
{
private:
        vector<Player*> players;        //Vector holding all players currently in the game
        int numberOfPlayers;    //The number of players in the game
        GameMap* map;   //The map the game is being played on
        GameOptions* options;   //Object that encapsulates all in-game options like fog of war, etc.
        int turnsTaken; //The number of total turns taken in the game; increments once every time the game cycles through all the players
        int gameTime;   //Maybe this won't be an int, but this will be some variable that holds how long (real-time) the game has been running
        
public:
        Game(); //Does initialization, haven't thought through what arguments it might need
        ~Game();        //Garbage collection
        void addPlayer(Player* newPlayer);   //Adds another player to the game and increments the number of players by one
        void setMap(GameMap* newMap);   //Sets the map for the game
        void setOptions(GameOptions* options);  //Sets the options for the game; this will let us easily change the options mid-game (I think)
        int getTurnsTaken();    //Returns the number of turns taken during the game
        int getGameTime();      //Returns how long the game has been going on, might be nice to display this to the players
                                //If there's a better way to store time than an int, let's do it
                                //Otherwise, maybe this can be an int that stores the length of time in seconds
        void incrementGameClock();      //I just thought of this: a function that increments the in-game clock by one second
                                        //We could call this function somewhere within the main loop to keep track of game time
        void draw();    //Magical function that draws everything in-game to the screen
};
