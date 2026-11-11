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
#include "FileInterface.h"

class AStar
{
public:
	char level_path[20][20];

	std::vector<Item> GetNeighbours(Item* a);
	bool Calculate(char _level_array[20][20]);

	// Both are continuous methods
	float ManHattanDistance(Item* a, Item* b);
	float EuclidianDistance(Item* a, Item* b);

	std::string PrintLevelPath();
};

