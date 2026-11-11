#include "AStar.h"

// Return the surrounding nodes of this item
std::vector<Item> AStar::GetNeighbours(Item* a)
{
	std::vector<Item> neighbours;

	// Eight neighbours
	// Collumns
	for (int i = -1; i < 2; i++)
	{
		// Rows
		for (int j = -1; j < 2; j++)
		{
			// Don't return the current node
			if (i != 0 && j != 0)
			{
				Item NewItem(level_path[a->x +i][a->y + j], 0, a->x + i, a->y + j);
				neighbours.push_back(NewItem);
			}
		}
	}

	bool near_wall = false;

	for (int i = 0; i < neighbours.size(); i++)
	{
		neighbours[i].GetIdentifier() == 'w'; // Wall
		near_wall = true;
	}

	// If neighbours contain a wall, only return the 4 cardinal directions
	if (near_wall)
	{
		neighbours.clear();

		// Right
		Item ItemA(level_path[a->x + 1][a->y], 0, a->x + 1, a->y);
		neighbours.push_back(ItemA);

		// Left
		Item ItemB(level_path[a->x - 1][a->y], 0, a->x - 1, a->y);
		neighbours.push_back(ItemB);
		
		// Up
		Item ItemC(level_path[a->x][a->y + 1], 0, a->x, a->y + 1);
		neighbours.push_back(ItemC);

		// Down
		Item ItemD(level_path[a->x][a->y - 1], 0, a->x, a->y - 1);
		neighbours.push_back(ItemD);
	}

	return neighbours;
}

// A star ignores the items and just finds the most efficient path in a 2d array
// Returns true if valid path
bool AStar::Calculate(char _level_array[20][20])
{
	// Add the START node to the Open list with default f & g values of zero
	Item Start('s', 0.f);

	// Move the level array to level path to not adjust the original level
	for (int y = 0; y < 20; y++)
	{
		for (int x = 0; x < 20; x++)
		{
			level_path[x][y] = _level_array[x][y];

			// Found start node
			if (level_path[x][y] == 's')
			{
				// Initilize the x and y values
				Start.x = x;
				Start.y = y;
			}
		}
	}

	std::cout << PrintLevelPath();

	// Create 2 containers open and closed
	Queue open;
	std::vector<Item> closed;

	open.Push(Start);
	
	closed.push_back(open.Pop()); // Remove the node at the head of the open list and add to the back of the closed list
	Item current = closed.back(); // This becomes the current node

	// While there are still items in the open list, and the exit node hasn't been found
	while (open.GetLength() != 0 && current.GetIdentifier() != 'x')
	{
		closed.push_back(open.Pop()); // Remove the node at the head of the open list and add to the back of the closed list
		current = closed.back();
		std::vector<Item> neighbours = GetNeighbours(&current); // Get neighbours of the current node

		std::cout << "Neighbour size: " << neighbours.size();

		// For each neighbor n
		for (int i = 0; i < neighbours.size(); i++)
		{
			// If not an obstacle or on the closed list
			if (neighbours[i].GetIdentifier() != 'w' && std::find(closed.begin(), closed.end(), neighbours[i]) == closed.end())
			{
				// H: Estimated cost to get from the node n to the goal
				neighbours[i].h = ManHattanDistance(&current, &neighbours[i]);

				// G: Cost to reach the node n
				neighbours[i].g = EuclidianDistance(&current, &neighbours[i]);

				// F: Estimated total cost of path through n to the goal
				neighbours[i].f = neighbours[i].h + neighbours[i].g;

				// P = CURRENT Node
				// neighbours[i].p = &current;
				
				// n.g = distance from CURRENT to n + CURRENT.g
				// neighbours[i].g = EuclidianDistance(&current, &neighbours[i]) + neighbours[i].p->g;

				// std::cout << "n.g: " << neighbours[i].g << ", o.g: " << open.GetItem(neighbours[i]).g << "\n";

				// N is on the open list and NeighbourList[i].g < Open.g
				if (open.Find(neighbours[i])) // && current.neighbour_list[i].g < open.GetItem(current.neighbour_list[i]).g)
				{
					std::cout << "Update n.f, n.g, n.p\n";
					neighbours[i].g = EuclidianDistance(&current, &neighbours[i]);
					neighbours[i].f = neighbours[i].h + neighbours[i].g;
				}

				// Push N to the Open list
				else
				{
					std::cout << "Pushing n to the open list\n";
					open.Push(neighbours[i]);
				}
			}
		}
	}

	std::cout << "Closed size: " << closed.size() << "\n";
	
	// Need to see if closed contains the end node
	// Valid path
	if (current.GetIdentifier() == 'x')
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
