#pragma once
#include <vector>

class Node
{
public:
	bool visited = false;
	std::vector<Node*> neighbours;
};

