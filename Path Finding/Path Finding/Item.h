/***********************************************************************
Author      :	Zane Jackson
Description :	Used in heap sort (Modified to fit A*)
File name   :   Item.h
**************************************************************************/

#pragma once
#include <string>
#include <vector>

class Item
{
public:
	Item(char _identifier = ' ', float _priority = 0.0f)
	{
		identifier = _identifier;
		priority = _priority;
		p = nullptr;
	}

	Item(char _identifier, float _priority, float _x, float _y)
	{
		identifier = _identifier;
		priority = _priority;
		p = nullptr;

		x = _x;
		y = _y;
	}

	~Item() {};

	char GetIdentifier() { return identifier; }
	float GetPriority() { return priority; }
	void SetPriority(float _priority) { priority = _priority; }

	// THX Nic this makes the GetItem method work
	// Compare the x and y value of 2 items
	inline bool operator==(const Item& rhs) const
	{
		return x == rhs.x && y == rhs.y;
	}

	// Thingies for A*
	float f = 0.f;
	float g = 0.f;
	float h = 0.f;
	Item* p;

	// Location
	int x = 0.f;
	int y = 0.f;

protected:
	float priority;
	char identifier;
};