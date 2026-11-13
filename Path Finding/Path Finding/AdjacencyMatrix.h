/***********************************************************************
Author      :	Zane Sebastian Jackson
Description :	AdjacencyMatrix for graph traversal methods
File name   :   AdjacencyMatrix.h
**************************************************************************/

#pragma once
#include <vector>
#include <iomanip> // For set width function
#include "Graph.h"
#include <iostream>
#include <queue>

class AdjacencyMatrix : public Graph
{
public:
	virtual void Connect(char a, char b, int ax, int bx, int ay, int by);
	virtual bool AreConnected(char a, char b);
	virtual void GenerateNeighbours(char _level_array[20][20]);
	virtual std::vector<char> GetNeighbours(char a);
	virtual void PrintAdjacencyMatrix();

protected:
	float adjacencies[11][11]; // The adjacency matrix with weightings
};

