#include "Game.h"

void Game::Initialize() 
{
	isRunning = true;
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("Testing", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	player = new Character;
	player->Initialise(renderer);
	
	//Frame Rate Testing
	FramesPerSecond = 10000.0f / 80.0f;

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
		
		Input->HandleInput(localEvent, player);
	}
}

void Game::Update()
{
	TickStart = SDL_GetTicks();

	HandleEvents();

	Render();

	if (FramesPerSecond > SDL_GetTicks() - TickStart)
	{
		SDL_Delay(FramesPerSecond - (SDL_GetTicks() - TickStart));
	}

}

void Game::Render()
{
	SDL_RenderClear(renderer);

	player->Render(renderer);

	SDL_RenderPresent(renderer);
}