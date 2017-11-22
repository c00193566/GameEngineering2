#include "Systems.h"

void AISystem::AddGameObject(GameObject g)
{
	// Prevents a GameObject with no health component from being added
	if (g.ComponentExists("Health Component") && g.ComponentExists("Position Component") && !g.ComponentExists("Control Component"))
	{
		GameObjects.push_back(g);
	}
}

void RenderSystem::AddGameObject(GameObject g)
{
	// Prevents a GameObject with no health component from being added
	if (g.ComponentExists("Position Component"))
	{
		GameObjects.push_back(g);
	}
}

void ControlSystem::AddGameObject(GameObject g)
{
	// Prevents a GameObject with no health component from being added
	if (g.ComponentExists("Position Component") && g.ComponentExists("Control Component"))
	{
		GameObjects.push_back(g);
	}
}

void AISystem::Update(unsigned int dt)
{
	cout << "Updating AI System..." << endl;

	for (int i = 0; i < GameObjects.size(); i++)
	{
		cout << "AI System Update for GameObject : " << i << endl;
	}

	cout << endl;
}

void RenderSystem::Update(unsigned int dt)
{
	cout << "Updating Render System..." << endl;

	for (int i = 0; i < GameObjects.size(); i++)
	{
		cout << "Render System Update for GameObject : " << i << endl;
	}

	cout << endl;
}

void ControlSystem::Update(unsigned int dt)
{
	cout << "Updating Control System..." << endl;

	for (int i = 0; i < GameObjects.size(); i++)
	{
		cout << "Control System Update for GameObject : " << i << endl;
	}

	cout << endl;
}