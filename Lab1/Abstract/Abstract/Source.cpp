#include <iostream>
#include <vector>
#include "CharacterFactory.h"

using namespace std;

int main()
{
	Factory* factory = new CharacterFactory;

	vector<Character*> Characters;

	Characters.push_back(factory->CreatePlayer());
	Characters.push_back(factory->CreateOpponents());

	for (int i = 0; i < Characters.size(); i++)
	{
		Characters[i]->Draw();
	}

	system("Pause");

	return 0;
}