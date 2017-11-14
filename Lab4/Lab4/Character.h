#pragma once
#include "stdafx.h"

class Head
{

};

class Body
{

};

class Character
{
public:
	virtual void print() = 0;

protected:
	Head* head;
	Body* body;
};