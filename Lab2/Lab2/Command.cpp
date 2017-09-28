#include "Command.h"

void MacroCommand::execute()
{
	list<Command*>::iterator i;

	for (i = Commands->begin(); i != Commands->end(); i++)
	{
		Command* c = *i;

		c->execute();

		remove(c);
	}
}

void MacroCommand::add(Command* c)
{
	Commands->push_back(c);
}

void MacroCommand::remove(Command* c)
{
	LastExecutedCommand = c;
	Commands->remove(c);
}