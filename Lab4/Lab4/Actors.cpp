#include "Actors.h"

void Actors::Add(Character* character)
{
	Characters.push_back(character);
}

void Actors::Update(unsigned int dt)
{
	for each (Character* character in Characters)
	{
		character->print();
	}
}