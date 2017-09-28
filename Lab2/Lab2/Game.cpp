#include "Game.h"

void Game::Initialize() 
{
	isRunning = true;
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("Testing", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_SHOWN);
}

void Game::HandleEvents()
{
	SDL_Event localEvent;

	while (SDL_PollEvent(&localEvent))
	{
		if (localEvent.type == SDL_QUIT)
		{
			isRunning = false;
		}
		
		Input->HandleInput(localEvent, Commands);

		if (Commands->getCommands()->size() > 3)
		{
			cout << Commands->getCommands()->size() << endl;
			Commands->execute();
		}
	}
}

void Game::Update()
{

}