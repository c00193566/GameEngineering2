#pragma once
#include "Character.h"

class Boss : public Character
{
public:
	Boss();
	~Boss();
	void print()
	{
		cout << "Boss printing..." << endl;
	}
};