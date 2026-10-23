/***********************************************************************
Author      :	Zane Sebastian Jackson
Mail        :   Zane.Jackson@mds.ac.nz
Description :	Depth first search (DFS) and Breadth first search (BFS)
File name   :   GraphTraversal.h
**************************************************************************/

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

