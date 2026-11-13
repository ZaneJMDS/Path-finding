#include "AStar.h"

// Return the surrounding nodes of this item
std::vector<Item> AStar::GetNeighbours(Item* a)
{
	std::vector<Item> neighbours;

	int neighbourX;
	int neighbourY;

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
				neighbourX = a->x + j;
				neighbourY = a->y + i;

				// Don't return a node which leaves the level
				if (neighbourX < 20 && neighbourX >= 0 && neighbourY < 20 && neighbourY >= 0)
				{
					Item NewItem(level_path[neighbourX][neighbourY], 0, neighbourX, neighbourY);
					neighbours.push_back(NewItem);
				}
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
		neighbourX = a->x + 1;
		neighbourY = a->y;

		if (neighbourX < 20 && neighbourX >= 0 && neighbourY < 20 && neighbourY >= 0)
		{
			Item ItemA(level_path[neighbourX][neighbourY], 0, neighbourX, neighbourY);
			neighbours.push_back(ItemA);
		}

		// Left
		neighbourX = a->x - 1;
		neighbourY = a->y;

		if (neighbourX < 20 && neighbourX >= 0 && neighbourY < 20 && neighbourY >= 0)
		{
			Item ItemB(level_path[neighbourX][neighbourY], 0, neighbourX, neighbourY);
			neighbours.push_back(ItemB);
		}

		// Up
		neighbourX = a->x;
		neighbourY = a->y + 1;

		if (neighbourX < 20 && neighbourX >= 0 && neighbourY < 20 && neighbourY >= 0)
		{
			Item ItemC(level_path[neighbourX][neighbourY], 0, neighbourX, neighbourY);
			neighbours.push_back(ItemC);
		}

		// Down
		neighbourX = a->x;
		neighbourY = a->y - 1;

		if (neighbourX < 20 && neighbourX >= 0 && neighbourY < 20 && neighbourY >= 0)
		{
			Item ItemD(level_path[a->x][a->y - 1], 0, a->x, a->y - 1);
			neighbours.push_back(ItemD);
		}
	}

	return neighbours;
}

// A star ignores the items and just finds the most efficient path in a 2d array
// Returns true if valid path
bool AStar::Calculate(char _level_array[20][20])
{
	// Add the START node to the Open list with default f & g values of zero
	Item Start('s', 0.f);
	
	// Find the end node for manhattan distance
	Item End('e', 0.f);

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

			// Found end node
			if (level_path[x][y] == 'x')
			{
				// Initilize the x and y values
				End.x = x;
				End.y = y;
			}
		}
	}

	std::cout << PrintLevelPath();

	// Create 2 containers open and closed
	Queue open;
	std::vector<Item> closed;
	Item current('n', 0); // Set the first node to null
	closed.push_back(current);

	open.Push(Start);

	// While there are still items in the open list, and the exit node hasn't been found
	while (open.GetLength() != 0 && current.GetIdentifier() != 'x')
	{
		closed.push_back(open.Pop()); // Remove the node at the head of the open list and add to the back of the closed list
		current = closed.back(); // This becomes the current node
		std::vector<Item> neighbours = GetNeighbours(&current); // Get neighbours of the current node

		// std::cout << "Neighbour size: " << neighbours.size();

		// For each neighbor n
		for (int i = 0; i < neighbours.size(); i++)
		{
			// If not an obstacle or on the closed list
			if (neighbours[i].GetIdentifier() != 'w' && std::find(closed.begin(), closed.end(), neighbours[i]) == closed.end())
			{
				// P = Parent Node of the neighbour is the current
				neighbours[i].p = &current;
				
				// H: Estimated cost to get from the node n to the goal
				neighbours[i].h = ManHattanDistance(&neighbours[i], &End);

				// G: Cost to reach the node n from the current + the g value of p
				neighbours[i].g = EuclidianDistance(&current, &neighbours[i]) + neighbours[i].p->g;

				// F: Estimated total cost of path through n to the goal
				neighbours[i].f = neighbours[i].h + neighbours[i].g;

				// N is on the open list and NeighbourList[i].g < Open.g
				if (open.Find(neighbours[i]) && neighbours[i].g < open.GetItem(neighbours[i])->g)
				{
					// Update n.f, n.g, n.p
					neighbours[i].p = open.GetItem(neighbours[i]);
					neighbours[i].g = EuclidianDistance(&current, &neighbours[i]) + neighbours[i].p->g;
					neighbours[i].f = neighbours[i].h + neighbours[i].g;
				}

				// Push N to the Open list
				else
				{
					// std::cout << "Pushing n to the open list\n";
					open.Push(neighbours[i]);
				}
			}
		}
	}

	std::cout << "Closed size: " << closed.size() << "\n";
	std::cout << "Open size: " << open.GetLength() << "\n";

	// Need to see if closed contains the exit node
	// Valid path
	if (!closed.empty() && closed.back().GetIdentifier() == 'x')
	{
		std::cout << "Valid pathway found\n"; 

		// Every item on the closed list is one that the algorithim has visited
		/*for (int i = 2; i < closed.size() - 1; i++)
		{
			level_path[closed[i].x][closed[i].y] = 'p';
		}*/

		// Walk back through the parents
		Item* back_current = &closed.back();

		while (back_current->p != nullptr)
		{
			level_path[back_current->x][back_current->y] = 'p';
			back_current = back_current->p;
		}

		std::cout << "Test";

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
