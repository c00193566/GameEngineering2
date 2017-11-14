#include "Protangonist.h"

Protagonist::Protagonist()
{
	head = new Head;
	body = new Body;
}

Protagonist::~Protagonist()
{
	delete head;
	delete body;
}