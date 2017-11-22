#pragma once
#include "stdafx.h"
#include "SDL.h"

class Component
{
public:
	string getComponentType() { return type; };

protected:
	string type;
};

class HealthComponent : public Component
{
public:
	HealthComponent() 
	{ 
		Health = 100;
		type = "Health Component";
	};

	int getHealth() { return Health; };
	void setHealth(int h) { Health = h; };

private:
	int Health;
};

class PositionComponent : public Component
{
public:
	PositionComponent(float X = 0, float Y = 0)
	{ 
		x = X;
		y = Y;
		type = "Position Component";
	};

	~PositionComponent() {};

	float getX() { return x; }
	float getY() { return y; };

	void setPosition(float X, float Y) { x = X; y = Y; };

private:
	float x;
	float y;
};

class ControlComponent : public Component
{
public:
	ControlComponent()
	{
		type = "Control Component";
	};

	SDL_Keycode getKeyPressed() { return KeyCode; };
	void setKeyPressed(SDL_Keycode k) { KeyCode = k; };

private:
	SDL_Keycode KeyCode;
};