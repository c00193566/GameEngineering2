#include "InputHandler.h"

void InputHandler::HandleInput(SDL_Event event, MacroCommand* c)
{
	if (event.type == SDL_KEYDOWN)
	{
		if (event.key.keysym.sym == BUTTONA)
		{
			c->add(Button_A);
			Button_A->execute();
		}
		else if (event.key.keysym.sym == BUTTONB)
		{
			c->add(Button_B);
			Button_B->execute();
		}
		else if (event.key.keysym.sym == BUTTONX)
		{
			if (c->LastExecutedCommand != nullptr)
			{
				c->redo();
			}
		}
		else if (event.key.keysym.sym == BUTTONY)
		{
			if (c->getCommands()->size() > 0)
			{
				c->undo();
			}
		}
	}
}