/***********************************************************************
Author      :	Zane Sebastian Jackson
Description :	Graph that Adjacency Matrix uses
File name   :   Graph.h
**************************************************************************/

#pragma once
#include <map>
#include "FileInterface.h"
#include "Item.h"

class Graph
{
protected:
	std::map<char, int> node_indices = { {'s', 0}, {'a', 1}, {'b', 2}, {'c', 3}, {'d', 4}, {'e', 5}, {'f', 6}, {'g', 7}, {'h', 8}, {'i', 9}, {'j', 10}}; // Maps node labels to indicies
	std::map<int, char> node_labels = { {0 , 's'}, {1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}, {5, 'e'}, {6, 'f'}, {7, 'g'}, {8, 'h'}, {9, 'i'}, {10, 'j'}}; // Maps node indicies to labels

public:
	Graph() {}

	bool NodeExist(char _item); // check if a node exists
	const int GetNumNodes() { return 11; } // Number of items
	std::vector<char> GetNodeList(); // returns a vector of the node labels
};

