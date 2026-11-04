/***********************************************************************
Author      :	Zane Sebastian Jackson
Mail        :   Zane.Jackson@mds.ac.nz
Description :	Path finding with A* algorithim
File name   :   Astar.h
**************************************************************************/

#pragma once
#include <vector>
#include "Queue.h"
#include <iostream>

class AStar
{
public:
	void Calculate();
	void CheckVectorLengths(std::vector<float> a, std::vector<float> b);

	// Both are continuous methods
	float ManHattanDistance(std::vector<float> a, std::vector<float> b);
	float EuclidianDistance(std::vector<float> a, std::vector<float> b);
};

