#include "AStar.h"

// A star ignores the items and just finds the most efficient path in a 2d array
// Returns true if valid path
bool AStar::Calculate()
{
	// Create 2 lists open and closed
	Queue open;
	std::vector<Item> closed;

	// Add the START node to the Open list with default f & g values of zero
	Item Start('s', 0.f);
	
	// Initilize the x and y values
	Start.x;
	Start.y;

	open.Push(Start);

	// While there are still items in the open list
	while (open.GetLength() != 0 && closed.back() != 'x')
	{
		// Remove the node at the head of the open list and add to the back of the closed list
		closed.push_back(open.Pop()); // This becomes the current node
		Item current = closed.back();
		open.GetNeighbourNodes(current); // TODO UPDATE Get neighbours method

		// For each neighbor n
		for (int i = 0; i < current.neighbour_list.size(); i++)
		{
			// If not an obstacle or on the closed list
			if (current.neighbour_list[i].GetIdentifier() != 'x' && std::find(closed.begin(), closed.end(), current.neighbour_list[i]) != closed.end())
			{
				// H: Estimated cost to get from the node n to the goal
				current.neighbour_list[i].h = ManHattanDistance(&current, &current.neighbour_list[i]);

				// G: Cost to reach the node n
				current.neighbour_list[i].g = EuclidianDistance(&current, &current.neighbour_list[i]);

				// F: Estimated total cost of path through n to the goal
				current.neighbour_list[i].f = current.neighbour_list[i].h + current.neighbour_list[i].g;

				// P = CURRENT Node
				current.neighbour_list[i].p = &current;
				
				// n.g = distance from CURRENT to n + CURRENT.g
				current.neighbour_list[i].g = EuclidianDistance(&current, &current.neighbour_list[i]) + current.neighbour_list[i].p->g;

				std::cout << "n.g: " << current.neighbour_list[i].g << ", o.g: " << open.GetItem(current.neighbour_list[i]).g << "\n";

				// N is on the open list and NeighbourList[i].g < Open.g
				// TODO Make another function in Item which returns the found item instead of bool
				if (open.Find(current.neighbour_list[i])) // && current.neighbour_list[i].g < open.GetItem(current.neighbour_list[i]).g)
				{
					std::cout << "Update n.f, n.g, n.p\n";
					current.neighbour_list[i].g = EuclidianDistance(&current, &current.neighbour_list[i]);
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

	std::cout << "Closed size: " << closed.size() << "\n";
	
	// Need to see if closed contains the end node
	// Valid path
	if (closed.back().GetIdentifier() == 'x') // Found the exit node
	{
		std::cout << "Valid pathway found\n"; 

		// Every item on the closed list is one that the algorithim has visited
		// Set that as the pathway
		for (int i = 0; i < closed.size(); i++)
		{
			level_path[closed[i].x][closed[i].y] = 'p';
		}

		// Print out for the user here
		std::cout << PrintLevelPath();

		return true;
	}

	// No path found
	else
	{
		std::cout << "No pathway found\n";
		return false;
	}
}

// Compare distance between 2 points assuming you CAN NOT go diagonally
float AStar::ManHattanDistance(Item* a, Item* b)
{
	// Should return a whole number distance
	return abs(a->x - b->x) + abs(a->y - b->y);
}

// Compare distance between 2 points assuming you CAN go diagonally
float AStar::EuclidianDistance(Item* a, Item* b)
{
	// pythagorous therom
	return sqrt(pow((a->x - b->x), 2) + pow((a->y - b->y), 2));
}

std::string AStar::PrintLevelPath()
{
	std::string graph = "";

	// collumns
	for (int y = 0; y < 20; y++)
	{
		// rows
		for (int x = 0; x < 20; x++)
		{
			graph += level_path[x][y];
		}
		graph += "\n";
	}
	return graph;
}
