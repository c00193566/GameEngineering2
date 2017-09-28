#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "InputHandler.h"


class Game {
private:
	bool isRunning;
	InputHandler* Input = new InputHandler;
	SDL_Window* window = nullptr;
	MacroCommand* Commands = new MacroCommand;

public:
	void Initialize();
	void HandleEvents();
	void Update();
	void Render() {};
	void CleanUp() {};

	bool IsRunning() { return isRunning; };
};