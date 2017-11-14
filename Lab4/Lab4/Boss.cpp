#include "Boss.h"

Boss::Boss()
{
	head = new Head;
	body = new Body;
}

Boss::~Boss()
{
	delete head;
	delete body;
}