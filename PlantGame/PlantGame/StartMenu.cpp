#pragma once
#include "StartMenu.h"

StartMenu::StartMenu()
{
	mouseX = 0;
	mouseY = 0;
	startGame = false;	//controls when to start the game and go into the game
}

StartMenu::~StartMenu()
{
}

int StartMenu::update()
{
	if(startGame)
		return 1;
	return -1;
}

void StartMenu::draw()
{
	al_draw_rectangle(mouseX-5, mouseY-5, mouseX+5, mouseY+5, al_map_rgb(255,0,0), 5);	//testing
}

void StartMenu::keyPressA()
{
	startGame = true;	//testing purposes. Pressing A starts the game
}

void StartMenu::keyPressD()
{
}

void StartMenu::keyPressS()
{
}

void StartMenu::keyPressW()
{
}