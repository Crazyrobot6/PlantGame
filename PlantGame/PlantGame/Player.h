#pragma once

#include <string>
#include <vector>
#include "Unit.h"

class Player
{
private:
	std::string playerName;
	int playerNumber;
	int score;
	double playerMinerals;
	double playerWater;
	std::vector<Unit*> playersUnits;

public:
	Player();	//Takes care of initializing the player
	~Player();	//Garbage collection
	void setName(string name);	//Sets the player's name
	String getName();	//Returns the player's name
	void addToScore(int points);	//Increases the player's score by the value passed to the function 
	int getScore();	//Returns the player's current score
	void giveMinerals(double amount);	//Increases the amount of minerals the player currently has
	double getCurrentMinerals();	//Returns the current amount of minerals the player has
	void subtractMinerals(double amount);	//Deducts minerals from the playe's total
	void giveWater(double amount);	//Increases the amount of water the player currently has
	double getCurrentWater();	//Returns the amount of water the player currently has
	void subtractWater(double amount);	//Decreases the amount of water the player has
	vector* getUnits();	//Returns a pointer to the vector holding the player's units
};
