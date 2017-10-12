#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Vector2D.h"
#include "Animation.h"
#include <chrono>
#include <thread>

using namespace std;

struct CharacterAttributes {
	Vector2D Position;
	Vector2D Dimensions;
	SDL_Rect Rect;
	SDL_Rect SheetRect;
};

class Character {
private:
	SDL_Texture* texture = nullptr;
	CharacterAttributes Attributes;
	int Frames;
	int CurrentFrame = 0;

public:
	Animation* FSM = nullptr;

	Character() {};
	~Character() {};
	void Initialise(SDL_Renderer*);
	void Render(SDL_Renderer*);
	void Jump();
	void Fire();
	void SetFrame() { CurrentFrame = 0; Attributes.SheetRect.x = 0; };
};