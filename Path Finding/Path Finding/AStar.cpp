#include "AStar.h"

void AStar::Calculate()
{
	// Create 2 lists open and closed
	Queue open; // Heap
	std::vector<Item> closed; // Vector

	// Add the START node to the Open list with f & g values of zero
	Item Start;
	Start.f = 0;
	Start.g = 0;
	open.Push(Start);

	// While there are still items in the open list
	while (open.GetLength() != 0)
	{
		// Remove the node at the head of the open list and add to the back of the closed list
		closed.push_back(open.Pop()); // This becomes the current node
		Item current = closed.back();

		// TODO FIND WAY TO POPULATE NEIGHBOUR LIST
		// For each neighbor n
		for (int i = 0; i < current.neighbour_list.size(); i++)
		{
			// If not an obstacle or on the closed list
			if (current.neighbour_list[i].GetIdentifier() != "x" && std::find(closed.begin(), closed.end(), current.neighbour_list[i]) != closed.end())
			{
				// H: Estimated cost to get from the node n to the goal
				current.neighbour_list[i].h = ManHattanDistance();

				// G: Cost to reach the node n
				current.neighbour_list[i].g = EuclidianDistance();

				// F: Estimated total cost of path through n to the goal
				current.neighbour_list[i].f = current.neighbour_list[i].h + current.neighbour_list[i].g;

				// P = CURRENT Node
				current.neighbour_list[i].p = &current;
				
				// n.g = distance from CURRENT to n + CURRENT.g
				current.neighbour_list[i].g = EuclidianDistance() + current.neighbour_list[i].p->g;

				std::cout << "n.g: " << current.neighbour_list[i].g << ", o.g: " << open.GetItem(current.neighbour_list[i]).g << "\n";

				// N is on the open list and NeighbourList[i].g < Open.g
				// TODO Make another function in Item which returns the found item instead of bool
				if (open.Find(current.neighbour_list[i]) && current.neighbour_list[i].g < open.GetItem(current.neighbour_list[i]).g)
				{
					// Update n.f & n.g & n.p
					std::cout << "Update n.f, n.g, n.p\n";
					current.neighbour_list[i].g = EuclidianDistance();
					current.neighbour_list[i].f = current.neighbour_list[i].h + current.neighbour_list[i].g;
				}

				// Push N to the Open list
				else
				{
					std::cout << "Pushing n to the open list\n";
					open.Push(current.neighbour_list[i]);
				}
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
