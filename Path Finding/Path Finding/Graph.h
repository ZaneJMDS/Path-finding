/***********************************************************************
Author      :	Zane Sebastian Jackson
Mail        :   Zane.Jackson@mds.ac.nz
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
	std::map<Item*, Item*> node_indices; // Maps node labels to indicies
	std::map<Item*, Item*> node_labels; // Maps node indicies to labels
	Item* max_index = nullptr; // Maximum index adjacency matrix

public:
	Graph() {}

	bool NodeExist(Item* _item); // check if a node exists
	virtual void InsertNode(Item* _node_label); //inserts a node into the graph
	int GetNumNodes(); // returns the number of nodes in the graph
	std::vector<Item*> GetNodeList(); // returns a vector of the node labels
};

