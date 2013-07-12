//Allegro Headers -- add to as needed
#include <allegro5\allegro.h>
#include <allegro5\allegro5.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_audio.h>
#include <allegro5\allegro_acodec.h>
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
	const int FPS = 60;
	const int NUM_SAMPLES = 8; //number of sounds playing at one time
	const int WIDTH = 100;
	const int HEIGHT = 100;
	int mouseX = 0;
	int mouseY = 0;
	bool done = false;
	//Create Allegro variables
	ALLEGRO_DISPLAY *display;
	ALLEGRO_EVENT_QUEUE *event_queue;
	ALLEGRO_TIMER *timer;

	/*
	.ini File stuff
	-Read .ini file -- prob has graphics options and stuff
	-Process .ini file -- this is where we save the data from the .ini to variables in the program
	*/
	if(!al_init()) return -1;
	al_set_new_display_flags(ALLEGRO_FULLSCREEN);	//changes based on .ini
	display = al_create_display(WIDTH, HEIGHT);
	//al_set_window_position(display,0,0);		//if windowed, then sets position to top left corner

	al_install_keyboard();
	al_install_audio();
	al_init_acodec_addon();
	al_init_primitives_addon();
	al_init_image_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_install_mouse();

	/*
	Initialize Allegro components
	load bitmaps, audio, font, etc
	*/


	timer = al_create_timer(1.0/FPS);
	event_queue = al_create_event_queue();			//create event queue, then register all sources sp ot works
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	//al_register_event_source(event_queue, al_get_display_event_source(display));	//For some reason this isn't working...hm...
	al_register_event_source(event_queue, al_get_mouse_event_source());

	al_reserve_samples(NUM_SAMPLES);	//reserves space for NUM_SAMPLES of samples to play at one time
	//Set state to start menu
	

	al_start_timer(timer);	//starts right before game loop does to keep timing happy
	while(!done)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);	//waits for something to happen (timer, keyboard, mouse etc)
		done = true;		//prevent inf loop
	/*
	Game Loop
		-Read input
		-Process input
		-Update internals
		-Render output to screen
	*/
	}
	al_destroy_timer(timer);
	al_destroy_event_queue(event_queue);
	//al_destroy_display(display);
	al_rest(1);	//Just waits to show that a black box appeared and that this works :D
	return 0;
}