/***********************************************************************
Author      :	Zane Sebastian Jackson
Mail        :   Zane.Jackson@mds.ac.nz
Description :	Depth first search (DFS) and Breadth first search (BFS)
File name   :   GraphTraversal.h
**************************************************************************/

#pragma once
#include <vector>
#include "item.h"
#include <iostream>
#include <queue> // For breadth first

class GraphTraversal
{
public:
	// For graph traversal
	std::queue<Item*> q;

	void DepthFirst(std::vector<Item*> G, Item* v); // G is the graph Recalculate g everytime you update a node
	void BreadthFirst(std::vector<Item*> G, Item* v);

	void DepthFirst();
	void BreadthFirst();
};

