#pragma once
#include <list>
#include <iostream>
#include "Character.h"

using namespace std;

class Command {
public:
	virtual ~Command() {}
	virtual void execute() = 0;
	virtual void add(Command*) = 0;
	virtual void remove(Command*) = 0;
	virtual void redo() = 0;
	virtual void undo() = 0;

protected:
	Command() {}
};

class MacroCommand : public Command
{
public:
	virtual ~MacroCommand() {};
	virtual void add(Command*);
	virtual void remove(Command*);
	virtual void execute();
	virtual void redo();
	virtual void undo();
	list<Command*>* getCommands() { return Commands; };  
	Command* LastExecutedCommand;

private:
	list<Command*>* Commands = new list<Command*>;
};

// ConcreteCommands
class JumpCommand : public MacroCommand
{
public:
	virtual void execute(Character* a) { a->Jump(); };
};

class FireCommand : public MacroCommand
{
public:
	virtual void execute(Character* a) { a->Fire(); };
};