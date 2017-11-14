#pragma once
#include "stdafx.h"
#include "SDL.h"
#define SDL_MAIN_HANDLED

class SDL_Timer
{
public:
	SDL_Timer();

	void Start();
	void Stop();
	void Pause();
	void Unpause();

	Uint32 getTicks()
	{
		Uint32 timer = 0;

		if (Started)
		{
			if (Paused)
			{
				timer = PausedTicks;
			}
			else
			{
				timer = SDL_GetTicks() - StartTicks;
			}
		}

		return timer;
	}

	static int GameTime()
	{
		return SDL_GetTicks();
	}

	bool isStarted();
	bool isPaused();

private:
	Uint32 StartTicks;
	Uint32 PausedTicks;
	bool Paused;
	bool Started;
};