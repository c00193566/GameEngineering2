#include "Character.h"

void Character::Initialise(SDL_Renderer* renderer)
{
	FSM = new Animation;

	texture = IMG_LoadTexture(renderer, "ASSETS/Yoshi.png");

	if (texture == NULL)
	{
		cout << "Failed to Load Yoshi.png..." << endl;
	}

	Attributes.Position = Vector2D(300, 300);
	Attributes.Dimensions = Vector2D(64, 64);
	Attributes.Rect.x = Attributes.Position.x;
	Attributes.Rect.y = Attributes.Position.y;
	Attributes.Rect.w = Attributes.Dimensions.x;
	Attributes.Rect.h = Attributes.Dimensions.y;

	Attributes.SheetRect.x = 0;
	Attributes.SheetRect.y = 0;
	Attributes.SheetRect.w = 64;
	Attributes.SheetRect.h = 64;
}

void Character::Render(SDL_Renderer* renderer)
{
	FSM->Update(Attributes.SheetRect, Frames, CurrentFrame);
	SDL_RenderCopy(renderer, texture, &Attributes.SheetRect, &Attributes.Rect);
}

void Character::Jump()
{
	if (!FSM->getJumping() && !FSM->getFiring())
	{
		FSM->jump();
		SetFrame();
	}
	else
	{
		cout << "Unable to carry out command..." << endl;
	}
}

void Character::Fire()
{
	if (!FSM->getJumping() && !FSM->getFiring())
	{
		FSM->fire();
		SetFrame();
	}
	else
	{
		cout << "Unable to carry out command..." << endl;
	}
}