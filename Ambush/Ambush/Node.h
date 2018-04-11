#pragma once
#include <cmath>
#include <vector>
#include <memory>
#include <iostream>
#include <array>
#include <limits>
#include "Vector2D.h"

using namespace std;

class Node
{
private:
	Vector2f m_position;
	Vector2f m_gridposition;
	Vector2f m_size;
	float m_cost; // total cost from start
	float m_heur; // heuristic value
	float m_full; // cost + heusistic
	bool m_active;

public:
	Node * parent;
	vector<Node*> neighbours;

	Node() {};
	Node(int i, int j, int size, bool active)
	{
		m_gridposition = Vector2f(i, j);
		m_size = Vector2f(size, size);

		float x = (i * size) + (size / 2);
		float y = (j * size) + (size / 2);

		m_position = Vector2f(x, y);

		m_cost = numeric_limits<float>::infinity();
		m_heur = numeric_limits<float>::infinity();
		m_full = numeric_limits<float>::infinity();

		parent = nullptr;

		m_active = active;
	}

	void clear()
	{

	}
};