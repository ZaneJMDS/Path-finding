#pragma once
#include <vector>
#include "Node.h"
#include <queue> // For breadth first

class GraphTraversal
{
public:
	std::queue<Node*> q;

	void DepthFirst(Node* G, Node* v);
	void BreadthFirst(Node* G, Node* v);
};

