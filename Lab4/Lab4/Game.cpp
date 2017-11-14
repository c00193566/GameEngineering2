#include "stdafx.h"
#include "Game.h"

const float FPS = 60.0f;
const float TICKS_PER_FRAME = 1000.0f / FPS;

Game::Game() {}

Game::~Game()
{
	delete window;
	delete renderer;
}

bool Game::Init()
{
	quit = false;

	SDL_Init(SDL_INIT_EVERYTHING);

	window = SDL_CreateWindow("Entity Component System", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_SHOWN);

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	LastTime = 0;

	actors = new Actors;
	actors->Add(new Protagonist);
	actors->Add(new Boss);

	if (window == nullptr || renderer == nullptr || actors == nullptr)
	{
		return false;
	}

	return true;
}

void Game::Loop()
{
	SDL_Timer Timer;

	while (!quit)
	{
		unsigned int CurrentTime = SDL_Timer::GameTime();
		unsigned int DeltaTime = CurrentTime - LastTime;

		Update(DeltaTime);
		Event();
		Render();

		// Update LasstTime for 
		LastTime = CurrentTime;

		// Delay Frame Update
		float FrameTicks = Timer.getTicks();
		if (FrameTicks < TICKS_PER_FRAME)
		{
			SDL_Delay(TICKS_PER_FRAME - FrameTicks);
		}
	}
}

void Game::Update(unsigned int DT)
{
	actors->Update(DT);
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