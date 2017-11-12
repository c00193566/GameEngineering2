#include "stdafx.h"
#include "Game.h"

int main()
{
	cout << "Creating Game..." << endl;
	Game* game = new Game;

	cout << "Initialising Game..." << endl;
	game->Init();

	cout << "Game loop running..." << endl;
	game->Loop();


	return 0;
}