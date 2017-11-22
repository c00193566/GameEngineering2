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

	//Create Player
	GameObject Player;
	Player.AddComponent(new HealthComponent);
	Player.AddComponent(new PositionComponent(200.0f, 200.0f));
	Player.AddComponent(new ControlComponent);

	//Create Alien
	GameObject Alien;
	Alien.AddComponent(new HealthComponent);
	Alien.AddComponent(new PositionComponent(200.0f, 200.0f));

	//Create Dog
	GameObject Dog;
	Dog.AddComponent(new HealthComponent);
	Dog.AddComponent(new PositionComponent(200.0f, 200.0f));

	//Create Cat
	GameObject Cat;
	Cat.AddComponent(new HealthComponent);
	Cat.AddComponent(new PositionComponent(200.0f, 200.0f));

	//Add to AI System
	AI_System.AddGameObject(Player);
	AI_System.AddGameObject(Alien);
	AI_System.AddGameObject(Dog);
	AI_System.AddGameObject(Cat);

	//Add to Render System
	Render_System.AddGameObject(Player);
	Render_System.AddGameObject(Alien);
	Render_System.AddGameObject(Dog);
	Render_System.AddGameObject(Cat);

	//Add to Control System
	Control_System.AddGameObject(Player);

	if (window == nullptr || renderer == nullptr)
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
	// Update systems
	AI_System.Update(DT);
	Render_System.Update(DT);
	Control_System.Update(DT);
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