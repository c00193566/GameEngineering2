#include "Animation.h"

Animation::Animation()
{
	current = new Idle;
	Idling = true;
	Jumping = false;
	Firing = false;
}

void Animation::idle()
{
	current->idle(this);
	Idling = true;
	Jumping = false;
	Firing = false;
}

void Animation::jump()
{
	current->jump(this);
	Idling = false;
	Jumping = true;
	Firing = false;
}

void Animation::fire()
{
	current->fire(this);
	Idling = false;
	Jumping = false;
	Firing = true;
}

void Animation::Update(SDL_Rect &SpriteSheet, int &Frames, int &CurrentFrame)
{
	current->Animate(SpriteSheet, Frames, CurrentFrame, this);
}

// Idle Class
void Idle::jump(Animation* a)
{
	cout << "Jumping" << endl;
	a->setCurrent(new Jump);
	
	delete this;
}

void Idle::fire(Animation* a)
{
	cout << "Firing" << endl;
	a->setCurrent(new Fire);
	delete this;
}

void Idle::Animate(SDL_Rect &SpriteSheet, int &Frames, int &CurrentFrame, Animation* a)
{
	Frames = 4;
	SpriteSheet.y = 0;

	if (CurrentFrame == Frames)
	{
		SpriteSheet.x = 0;
		CurrentFrame = 0;
	}
	else
	{
		SpriteSheet.x += 64;
		CurrentFrame += 1;
	}
}

// Jump Class
void Jump::idle(Animation* a) 
{
	cout << "going from jumping to idling" << endl;
	a->setCurrent(new Idle);
	a->idle();
	delete this;
}

void Jump::Animate(SDL_Rect &SpriteSheet, int &Frames, int &CurrentFrame, Animation* a)
{
	Frames = 7;
	SpriteSheet.y = 64;

	if (CurrentFrame == Frames)
	{
		CurrentFrame = 0;
		SpriteSheet.x = 0;
		idle(a);
	}
	else
	{
		SpriteSheet.x += 64;
		CurrentFrame += 1;
	}
}

// Fire Class
void Fire::idle(Animation* a)
{
	cout << "going from firing to idling" << endl;
	a->setCurrent(new Idle);
	a->idle();
	delete this;
}

void Fire::Animate(SDL_Rect &SpriteSheet, int &Frames, int &CurrentFrame, Animation* a)
{
	Frames = 6;
	SpriteSheet.y = 128;

	if (CurrentFrame == Frames)
	{
		CurrentFrame = 0;
		SpriteSheet.x = 0;
		idle(a);
	}
	else
	{
		SpriteSheet.x += 64;
		CurrentFrame += 1;
	}
}
