/***********************************************************************
Author      :	Mike Watts
Description :	Priority queue / min heap for sorting purposes
File name   :   Queue.h
**************************************************************************/

#pragma once
#include "Item.h"
#include <algorithm>
#include <vector>

class Queue
{
public:
	Queue();
	~Queue();

	void Push(Item _Item);
	Item Pop();
	float PriorityFront();
	bool Find(Item _Item);
	Item GetItem(Item _Item);
	int GetLength() { return heap.size(); }

	Item FindNode(float x, float y);
	std::vector<Item> GetNeighbourNodes(Item _Item);

protected:
	std::vector<Item> heap;
};

