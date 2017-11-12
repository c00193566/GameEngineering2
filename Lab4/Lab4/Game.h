#pragma once
#include "stdafx.h"
#include "SDL.h"

class Game
{
private:
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	bool quit;

public:
	Game();
	~Game();

	void Init();
	void Loop();
	void Update();
	void Render();
	void Event();
};