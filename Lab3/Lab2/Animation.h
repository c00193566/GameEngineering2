#pragma once
#include "SDL.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Animation {
private:
	class State* current;

public:
	Animation();

	void setCurrent(State* s)
	{
		current = s;
	}

	void idle();
	void jumping();
	void firing();
	void Update(SDL_Rect &SpriteSheet, int &Frames, int &CurrentFrame);

	State* getCurrent() { return current; };
};

class State {
public:
	virtual void idle(Animation* a)
	{
		cout << "State::Idling" << endl;
	};

	virtual void jump(Animation* a)
	{
		cout << "State::Jumping" << endl;
	};

	virtual void fire(Animation* a)
	{
		cout << "State::Firing" << endl;
	}

	virtual void Animate(SDL_Rect &SpriteSheet, int &Frames, int &CurrentFrame, Animation* a) = 0;
};

class Idle : public State {
public:
	Idle() {};
	~Idle() {};

	void jump(Animation*);
	void fire(Animation*);
	virtual void Animate(SDL_Rect &SpriteSheet, int &Frames, int &CurrentFrame, Animation* a);
};

class Jump : public State {
public:
	Jump() {};
	~Jump() {};

	void idle(Animation* a);
	virtual void Animate(SDL_Rect &SpriteSheet, int &Frames, int &CurrentFrame, Animation* a);
};

class Fire : public State {
public:
	Fire() {};
	~Fire() {};

	void idle(Animation* a);
	virtual void Animate(SDL_Rect &SpriteSheet, int &Frames, int &CurrentFrame, Animation* a);
};