#include "Game.h"

Game::Game()
{
	quit = false;
}

Game::~Game()
{
	delete(window);
	delete(renderer);
}

void Game::Init()
{
	quit = false;

	window = SDL_CreateWindow("Entity Component System", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_SHOWN);

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

void Game::Loop()
{
	while (!quit)
	{
		Update();
		Event();
		Render();
	}
}

void Game::Update()
{

}

void Game::Event()
{
	SDL_Event LocalEvent;

	while (SDL_PollEvent(&LocalEvent))
	{
		if (LocalEvent.type == SDL_QUIT)
		{
			quit = true;
		}
	}

}

void Game::Render()
{
	SDL_RenderClear(renderer);

	SDL_RenderPresent(renderer);
}