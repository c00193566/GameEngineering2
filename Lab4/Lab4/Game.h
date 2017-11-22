#pragma once
#include "stdafx.h"
#include "SDL_Timer.h"
#include "SDL.h"
#include "GameObject.h"
#include "Systems.h"

class Game
{
private:
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	bool quit;
	unsigned int LastTime;

	AISystem AI_System;
	RenderSystem Render_System;
	ControlSystem Control_System;

public:
	Game();
	~Game();

	bool Init();
	void Loop();
	void Update(unsigned int);
	void Render();
	void Event();
};