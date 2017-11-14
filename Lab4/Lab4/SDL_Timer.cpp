#include "SDL_Timer.h"

SDL_Timer::SDL_Timer()
{
	PausedTicks = 0;
	StartTicks = 0;

	Paused = false;
	Started = false;
}

void SDL_Timer::Start()
{
	Started = true;
	Paused = false;

	StartTicks = SDL_GetTicks();
	PausedTicks = 0;
}

void SDL_Timer::Stop()
{
	Started = false;
	Paused = false;

	StartTicks = 0;
	PausedTicks = 0;
}

void SDL_Timer::Pause()
{
	if (Started && !Paused)
	{
		Paused = true;

		StartTicks = SDL_GetTicks() - PausedTicks;

		PausedTicks = 0;
	}
}

void SDL_Timer::Unpause()
{
	if (Started && Paused)
	{
		Paused = false;

		StartTicks = SDL_GetTicks() - PausedTicks;

		PausedTicks = 0;
	}
}

bool SDL_Timer::isStarted()
{
	return Started;
}

bool SDL_Timer::isPaused()
{
	return Started && Paused;
}