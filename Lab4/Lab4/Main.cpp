#pragma once
#include "stdafx.h"
#include "Game.h"

int main(int argc, char* argv[])
{
	cout << "Creating new game..." << endl;
	Game* game = new Game;

	cout << "Initialising..." << endl;
	if (!game->Init())
	{
		cout << "Failed to initialise game..." << endl;
	}
	else
	{
		cout << "Initialised" << endl;

		cout << "Loop starting..." << endl;
		game->Loop();
	}

	cout << "Game closing..." << endl;

	return 0;
}