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
	LastExecutedCommand = c;
	Commands->push_back(c);
}

void MacroCommand::redo()
{
	LastExecutedCommand->execute();
}

void MacroCommand::undo()
{
	Commands->pop_back();
	cout << Commands->size() << endl;
}

void MacroCommand::remove(Command* c)
{
	Commands->remove(c);
}