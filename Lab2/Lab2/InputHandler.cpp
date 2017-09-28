#include "InputHandler.h"

void InputHandler::HandleInput(SDL_Event event, MacroCommand* c)
{
	if (event.type == SDL_KEYDOWN)
	{
		if (event.key.keysym.sym == BUTTONA)
		{
			c->add(Button_A);
		}
		else if (event.key.keysym.sym == BUTTONB)
		{
			c->add(Button_B);
		}
		else if (event.key.keysym.sym == BUTTONX)
		{
			if (c->LastExecutedCommand != nullptr)
			{
				c->add(c->LastExecutedCommand);
			}
		}
	}
}