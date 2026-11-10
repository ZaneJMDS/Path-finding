/***********************************************************************
Author      :	Zane Sebastian Jackson
Mail        :   Zane.Jackson@mds.ac.nz
Description :	AdjacencyMatrix for graph traversal methods
File name   :   AdjacencyMatrix.h
**************************************************************************/

#pragma once
#include <vector>
#include <iomanip> // For set width function
#include "Graph.h"
#include <iostream>

class AdjacencyMatrix : public Graph
{
public:
	virtual void InsertNode(char a);
	virtual void Connect(char a, char b);
	virtual bool AreConnected(char a, char b);
	virtual std::vector<char> GetNeighbours(char a);
	virtual void PrintAdjacencyMatrix();

protected:
	std::vector<std::vector<float>> adjacencies; // The adjacency matrix with weightings
};

