#pragma once
#include <vector>

class AStar
{
public:
	void Calculate(std::vector<float> a, std::vector<float> b);
	void CheckVectorLengths(std::vector<float> a, std::vector<float> b);
	float ManHattanDistance(std::vector<float> a, std::vector<float> b);
	float EuclidianDistance(std::vector<float> a, std::vector<float> b);
};

