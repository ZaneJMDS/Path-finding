/***********************************************************************
Author      :	Zane Sebastian Jackson
Mail        :   Zane.Jackson@mds.ac.nz
Description :	Path finding with A* algorithim
File name   :   Astar.h
**************************************************************************/

#pragma once
#include <vector>
#include "Queue.h"

class AStar
{
public:
	std::vector<Item> closed_list;
	Queue open_list;

	void Calculate(std::vector<float> a, std::vector<float> b);
	void CheckVectorLengths(std::vector<float> a, std::vector<float> b);

	// Both are continuous methods
	float ManHattanDistance(std::vector<float> a, std::vector<float> b);
	float EuclidianDistance(std::vector<float> a, std::vector<float> b);
};

