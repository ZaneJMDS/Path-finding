#include "AStar.h"

void AStar::Calculate(std::vector<float> a, std::vector<float> b)
{
	// Heuristic value
	float H = ManHattanDistance(a, b);

	// Cost
	float G = EuclidianDistance(a, b);

	// While current != END
	while (true)
	{
		// For all neighbours
		for (int i = 0; i < neighbour_list.size(); i++)
		{
			// If not an obstacle
			if (neighbour_list[i] != 'x')
			{
				float F = G + H;

				// If on the open list
				
			}
		}
	}
}


// Both vectors need to be equal
void AStar::CheckVectorLengths(std::vector<float> a, std::vector<float> b)
{
	if (a.size() != b.size())
	{
		throw "Vector lengths dont match";
	}
}

float AStar::ManHattanDistance(std::vector<float> a, std::vector<float> b)
{
	CheckVectorLengths(a, b);
	return abs(a[0] - b[0]) + abs(a[1] - b[1]);
}

float AStar::EuclidianDistance(std::vector<float> a, std::vector<float> b)
{
	CheckVectorLengths(a, b);

	// pythagorous therom
	return sqrt(pow((a[0] - b[0]), 2) + pow(a[1] - b[1], 2));
}
