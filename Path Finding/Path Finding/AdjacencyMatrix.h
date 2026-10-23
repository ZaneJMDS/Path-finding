/***********************************************************************
Author      :	Zane Sebastian Jackson
Mail        :   Zane.Jackson@mds.ac.nz
Description :	Generate and print an Adjacency Matrix based on graph traversal weightings
File name   :   AdjacencyMatrix.h
**************************************************************************/

#pragma once
#include <iostream>

class AdjacencyMatrix
{
public:
	float weightings[11][11];

	void PrintMatrix();
};

