/***********************************************************************
Author      :	Mike Watts
Description :	Priority queue for heap sort
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
	int GetLength() { return heap.size(); }

protected:
	std::vector<Item> heap;
};

