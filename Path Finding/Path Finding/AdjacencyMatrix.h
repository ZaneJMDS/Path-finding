/***********************************************************************
Author      :	Zane Sebastian Jackson
Mail        :   Zane.Jackson@mds.ac.nz
Description :	Generate and print an Adjacency Matrix based on graph traversal weightings
File name   :   AdjacencyMatrix.h
**************************************************************************/

#pragma once
#include <iostream>

// Might move this class back to graph traversal
class AdjacencyMatrix
{
public:
	float weightings[11][11];

	void PrintMatrix();
};

