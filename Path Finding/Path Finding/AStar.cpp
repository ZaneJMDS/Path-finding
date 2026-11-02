#include "AStar.h"

// Calculating A Star with 
void AStar::Calculate()
{
	// Create 2 lists open and closed
	Queue open;
	std::vector<Item> closed;

	// Add the START node to the Open list with f & g values of zero
	Item Start;
	open.Push(Start);

	// While there are still items in the open list
	while (open.GetLength() != 0)
	{
		// For each neighbor n
/*		for (int i = 0; i < neighbour_list.size(); i++)
		{
			// If not an obstacle or on the closed list
			if (neighbour_list[i] != 'x' && std::find(closed.begin(), closed.end(), neighbours_list[i]))
			{
				// Heuristic value
				// float H = ManHattanDistance(open, closed);

				// Cost
				// float G = EuclidianDistance(open, closed);

				// Total cost
				float F = G + H;

				If n is on the open list
					update n.f & n.g
				
			}

			else
			{
				add n to the Open list
			}
		}*/
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

// Compare distance between 2 points assuming you CAN NOT go diagonally
float AStar::ManHattanDistance(std::vector<float> a, std::vector<float> b)
{
	CheckVectorLengths(a, b);
	return abs(a[0] - b[0]) + abs(a[1] - b[1]);
}

// Compare distance between 2 points assuming you CAN go diagonally
float AStar::EuclidianDistance(std::vector<float> a, std::vector<float> b)
{
	CheckVectorLengths(a, b);

	// pythagorous therom
	return sqrt(pow((a[0] - b[0]), 2) + pow(a[1] - b[1], 2));
}
