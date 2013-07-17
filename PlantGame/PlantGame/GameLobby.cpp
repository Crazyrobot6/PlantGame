#pragma once
#include "GameLobby.h"

GameLobby::GameLobby()
{
	font36 = al_load_ttf_font("Fonts/A_Sensible_Armadillo.ttf", 36, 0);
	exitToStart = false;
	startGame = false;
	map = new GameMap(10,10,8);
}

GameLobby::~GameLobby()
{
	delete map;
	delete options;
	al_destroy_font(font36);
}
//===========================================================================================================
void GameLobby::keyPressA()
{
	if(map != NULL)
	{
		Player* newPlayer = new Player();
		std::string str = "a";
		newPlayer->setName("Player A");
		map->addPlayer(newPlayer);
	}
}

void GameLobby::keyPressD()
{
	if(map != NULL)
	{
		Player* newPlayer = new Player();
		std::string str = "a";
		newPlayer->setName("Player D");
		map->addPlayer(newPlayer);
	}
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
//===========================================================================================================
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
	//draw player names
<<<<<<< HEAD
	std::vector<Player*> players = map->getPlayers();
	al_draw_textf(font36, al_map_rgb(255,255,255), 1920/2, 1080/2-35, ALLEGRO_ALIGN_CENTRE, "%i Player(s)", players.size());
	for(unsigned int i=0; i<players.size(); i++)
		al_draw_text(font36, al_map_rgb(255,255,255), 1920/2, 1080/2 + (35*i), ALLEGRO_ALIGN_CENTRE, (char*)(players.at(i)->getName().c_str()));
=======
	al_draw_textf(font36, al_map_rgb(255,255,255), 1920/2, 1080/2-35, ALLEGRO_ALIGN_CENTRE, "%i Player(s)", players.size());
	for(int i=0; i<players.size(); i++)
		al_draw_text(font36, al_map_rgb(255,255,255), 1920/2, 1080/2 + (35*i), ALLEGRO_ALIGN_CENTRE, (char*)(players.at(i)->getName().c_str()));

>>>>>>> 8639776c447251b4a0d0d19bc7abe98d65543898
}