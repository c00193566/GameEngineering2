#pragma once
#include "Command.h"
#include <SDL.h>
#include <SDL_image.h>

using namespace std;

class InputHandler
{
public:
	void HandleInput(SDL_Event, MacroCommand*);

	InputHandler() {
		BUTTONA = SDLK_SPACE;
		BUTTONB = SDLK_z;
		BUTTONX = SDLK_r; // Redo
		BUTTONY = SDLK_u; //undo

		Button_A = new JumpCommand;
		Button_B = new FireCommand;
	}

private:
	Command* Button_X;
	Command* Button_Y;
	Command* Button_A;
	Command* Button_B;
	SDL_Keycode BUTTONX;
	SDL_Keycode BUTTONY;
	SDL_Keycode BUTTONA;
	SDL_Keycode BUTTONB;
};