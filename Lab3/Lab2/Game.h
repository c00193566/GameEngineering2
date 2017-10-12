#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <chrono>
#include <thread>
#include "InputHandler.h"
#include "Character.h"

using namespace std;

class Game {
private:
	bool isRunning;
	InputHandler* Input = new InputHandler;
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	Character* player = nullptr;

	//Frame Rate Testing
	Uint32 TickStart;
	float FramesPerSecond;

public:
	void Initialize();
	void HandleEvents();
	void Update();
	void Render();
	void CleanUp() {};

	bool IsRunning() { return isRunning; };
};