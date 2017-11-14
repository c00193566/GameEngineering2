#pragma once
#include "Character.h"

class Protagonist : public Character
{
public:
	Protagonist();
	~Protagonist();
	void print()
	{
		cout << "Protagonist printing..." << endl;
	}
};