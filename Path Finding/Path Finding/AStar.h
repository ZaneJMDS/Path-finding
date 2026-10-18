#pragma once
#include <vector>

class AStar
{
public:
	void Calculate(std::vector<float> a, std::vector<float> b);
	void CheckVectorLengths(std::vector<float> a, std::vector<float> b);

	// Both are continuous methods
	float ManHattanDistance(std::vector<float> a, std::vector<float> b);
	float EuclidianDistance(std::vector<float> a, std::vector<float> b);
};

