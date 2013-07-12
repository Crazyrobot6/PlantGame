//Allegro Headers -- add to as needed
#include <allegro5\allegro5.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_primitives.h>

//Class Headers
#include "Block.h"
#include "Bush.h"
#include "EvoTree.h"
#include "Flower.h"
#include "Game.h"
#include "GameMap.h"
#include "GameOptions.h"
#include "Player.h"
#include "Tree.h"
#include "Unit.h"

//Function Prototypes

//Global Constants and Variables as needed

int main()
{
	//Create local variables

	//Create Allegro variables

	/*
	.ini File stuff
	-Read .ini file -- prob has graphics options and stuff
	-Process .ini file -- this is where we save the data from the .ini to variables in the program
	*/

	/*
	Initialize Allegro components
	-Main part of allegro
	-Initialize display
	-Initialize fonts
	-Initialize sound
	-Whatever other parts of Allegro we need
	*/

	/*
	Load game and assets
	-Create ALLEGRO_BITMAP* variables for all bitmaps
		--We'll hold these in some location
		--Say Object1 needs Bitmap2. What we do is when we create Object1, we give it a copy of the ALLEGRO_BITMAP pointer
		--Now we've only loaded the bitmap once, but allow multiple objects to use it to draw
	-Load in the sound, I haven't read about how that works yet
	-Maybe load maps at this time? Otherwise we could load them when the game is starting
	*/

	//Set state to start menu
	
	/*
	Game Loop
		-Read input
		-Process input
		-Update internals
		-Render output to screen
	*/

	return 0;
}