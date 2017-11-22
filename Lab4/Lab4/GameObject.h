#pragma once
#include "stdafx.h"
#include "Component.h"

class GameObject
{
public:
	GameObject() { Components = vector<Component*>(); };
	~GameObject() {};
	void AddComponent(Component * c) { Components.push_back(c); };
	void RemoveComponent(Component c) {};
	vector<Component*> getComponents() { return Components; };
	Component * getComponent(string c)
	{
		Component* toReturn = nullptr;
		for (int i = 0; i < Components.size(); i++)
		{
			if (c == Components.at(i)->getComponentType())
			{
				toReturn = Components.at(i);
			}
		}

		return toReturn;
	}

	bool ComponentExists(string c)
	{
		for (int i = 0; i < Components.size(); i++)
		{
			if (c == Components.at(i)->getComponentType())
			{
				return true;
			}
		}

		return false;
	}

private:
	vector<Component*> Components;
};