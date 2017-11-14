#pragma once
#include "stdafx.h"
#include "SDL_Timer.h"
#include "SDL.h"
#include "Boss.h"
#include "Protangonist.h"
#include "Actors.h"

class Game
{
private:
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	bool quit;
	unsigned int LastTime;

	Actors* actors = nullptr;

public:
	Game();
	~Game();

	bool Init();
	void Loop();
	void Update(unsigned int);
	void Render();
	void Event();
};