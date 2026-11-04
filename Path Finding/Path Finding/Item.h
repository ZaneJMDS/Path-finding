/***********************************************************************
Author      :	Mike Watts
Description :	Used in heap sort (Modified to fit A*)
File name   :   Item.h
**************************************************************************/

#pragma once
#include <string>

class Item
{
public:
	Item(std::string _identifier = "", float _priority = 0.0f)
	{
		identifier = _identifier;
		priority = _priority;
		p = nullptr;
	}

	~Item() {};

	std::string GetIdentifier() { return identifier; }
	float GetPriority() { return priority; }
	void SetPriority(float _priority) { priority = _priority; }

	// Thingies for A*
	std::vector<Item> neighbour_list;
	float f;
	float g;
	float h;
	Item* p;

protected:
	float priority;
	std::string identifier;
};