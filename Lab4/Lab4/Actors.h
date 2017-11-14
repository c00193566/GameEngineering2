#pragma once
#include "Character.h"

class Actors
{
public:
	void Add(Character*);
	void Update(unsigned int);

private:
	vector<Character*> Characters;
};