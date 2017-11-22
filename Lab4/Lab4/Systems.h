#pragma once
#include "stdafx.h"
#include "GameObject.h"

class AISystem 
{
private:
	vector<GameObject> GameObjects;

public:
	void AddGameObject(GameObject g);
	void Update(unsigned int dt);
};

class RenderSystem
{
private:
	vector<GameObject> GameObjects;

public:
	void AddGameObject(GameObject g);
	void Update(unsigned int dt);
};

class ControlSystem
{
private:
	vector<GameObject> GameObjects;

public:
	void AddGameObject(GameObject g);
	void Update(unsigned int dt);
};