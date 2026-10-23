/***********************************************************************
Author      :	Mike Watts
Description :	Used in heap sort
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
	}

	~Item() {};

	std::string GetIdentifier() { return identifier; }
	float GetPriority() { return priority; }
	void SetPriority(float _priority) { priority = _priority; }

protected:
	float priority;
	std::string identifier;
};