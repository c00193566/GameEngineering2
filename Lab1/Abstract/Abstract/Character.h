#pragma once
#include <iostream>

using namespace std;

class Character
{
public:
	Character() {};
	virtual ~Character() {};
	virtual void Draw() = 0;
};