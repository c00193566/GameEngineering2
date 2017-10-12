#include "InputHandler.h"

void InputHandler::HandleInput(SDL_Event event, Character* character)
{
	if (event.type == SDL_KEYDOWN)
	{
		if (event.key.keysym.sym == BUTTONA)
		{
			Button_A->execute(character);
		}
		else if (event.key.keysym.sym == BUTTONB)
		{
			Button_B->execute(character);
		}
		else if (event.key.keysym.sym == BUTTONX)
		{
			cout << "No button mapped to ButtonX..." << endl;
		}
		else if (event.key.keysym.sym == BUTTONY)
		{
			cout << "No button mapped to ButtonY..." << endl;
		}
	}
}