/***********************************************************************
Author      :	Zane Sebastian Jackson
Mail        :   Zane.Jackson@mds.ac.nz
Description :	Depth first search (DFS) and Breadth first search (BFS)
File name   :   GraphTraversal.h
**************************************************************************/

#pragma once
#include <iostream>
#include <queue> // For breadth first
#include "AdjacencyMatrix.h" // For neighbour list

class GraphTraversal
{
public:
	// G is the graph, and v is the current item / node
	// Recalculate G everytime you update a node
	void DepthFirst(AdjacencyMatrix* G, Item* v);
	void BreadthFirst(AdjacencyMatrix* G, Item* v);

	void DepthFirst();
	void BreadthFirst();
};

