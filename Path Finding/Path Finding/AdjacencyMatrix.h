/***********************************************************************
Author      :	Zane Sebastian Jackson
Mail        :   Zane.Jackson@mds.ac.nz
Description :	AdjacencyMatrix for graph traversal methods
File name   :   AdjacencyMatrix.h
**************************************************************************/

#pragma once
#include <vector>
#include "Graph.h"
#include <iostream>

class AdjacencyMatrix : public Graph
{
public:
	virtual void InsertNode(Item* a);
	virtual void Connect(Item* a, Item* b);
	virtual bool AreConnected(Item* a, Item* b);
	virtual std::vector<Item*> GetNeighbours(Item* a);
	virtual void PrintAdjacencyMatrix();

protected:
	std::vector<std::vector<float>> adjacencies; // The adjacency matrix with weightings
};

