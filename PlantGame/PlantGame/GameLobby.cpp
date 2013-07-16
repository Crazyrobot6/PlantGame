#pragma once
#include "GameLobby.h"

GameLobby::GameLobby()
{
	font36 = al_load_ttf_font("Fonts/A_Sensible_Armadillo.ttf", 36, 0);
	exitToStart = false;
	startGame = false;
}

GameLobby::~GameLobby()
{
	delete map;
	delete options;
	al_destroy_font(font36);
}

int GameLobby::update()
{
	if(exitToStart)
		return 2;
	if(startGame)
		return 3;
	return -1;
}

void GameLobby::draw()
{
	al_draw_text(font36, al_map_rgb(100,0,100), 25,25,0, "Press Space to start the Game");
	al_draw_text(font36, al_map_rgb(100,0,100), 25,60,0, "This is the GAME LOBBY.");
}

void GameLobby::keyPressA()
{
}

void GameLobby::keyPressD()
{
}

void GameLobby::keyPressS()
{
}

void GameLobby::keyPressW()
{
}

void GameLobby::keyPressSpace()
{
	startGame = true;
}

void GameLobby::scroll(int dz)
{
}

bool GameLobby::writeToTemp()
{
	return false;
}