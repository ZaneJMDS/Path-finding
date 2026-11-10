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
	char level_path[20][20];

	bool Calculate();

	// Both are continuous methods
	float ManHattanDistance(Item* a, Item* b);
	float EuclidianDistance(Item* a, Item* b);

	std::string PrintLevelPath();
};

