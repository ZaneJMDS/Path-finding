#pragma once
#include <vector>

class Node
{
public:
	Node() {}
	~Node() {}

	bool visited = false;
	std::vector<Node*> neighbours;
};

