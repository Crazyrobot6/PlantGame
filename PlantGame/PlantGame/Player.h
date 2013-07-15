#pragma once

#include <string>
#include <vector>
#include "Unit.h"
#include "EvoTree.h"

class Unit;

class Player
{
private:
	std::string playerName;
	int playerNumber;
	int score;
	std::vector<Unit*> playersUnits;
	EvoTree* evoTree;

public:
	Player();	//Takes care of initializing the player
	~Player();	//Garbage collection
	void setName(std::string name);	//Sets the player's name
	std::string getName();	//Returns the player's name
	void addToScore(int points);	//Increases the player's score by the value passed to the function 
	int getScore();	//Returns the player's current score
	std::vector<Unit*> getUnits();	//Returns the vector holding the player's units
	EvoTree* getEvoTree();	//Returns the player's evolution tree
};
