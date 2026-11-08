#include "GraphTraversal.h"

// Graph and current node
// Start at an arbitrary node and search all connected nodes
void GraphTraversal::DepthFirst(Item* G, Item* v)
{
	// Set visit to true for current
	v->visited = true;

	// For w in G neighbours
	for (int i = 0; G->neighbour_list.size(); i++)
	{
		Item w = G->neighbour_list[i];

		if (!w.visited)
		{
			DepthFirst(G, &w);
		}
	}
}

// Uses a heap
// Maintains a queue of nodes to visit next
void GraphTraversal::BreadthFirst(Item* G, Item* v)
{
	q.push(v);

	while (q.size() > 0)
	{
		// Get the front of the heap
		v = q.front();
		q.pop();

		if (!v->visited)
		{
			v->visited = true;

			// Visit every neighbour until an unvisited one is reached
			for (int i = 0; G->neighbour_list.size(); i++)
			{
				Item w = G->neighbour_list[i];
				
				if (!w.visited)
				{
					q.push(&w);
				}
			}
		}
	}
}

// Call recursive
void GraphTraversal::DepthFirst()
{
	Item a('s', 0.f); // Graph
	Item b('a', 1.f); // Start
	DepthFirst(&a, &b);
}

// Call itterative
void GraphTraversal::BreadthFirst()
{
	std::vector<Item> graph; // Graph
	Item s('s', 0.f); // start
	BreadthFirst(&a, &b);
}

// Print weightings
void GraphTraversal::PrintAdjacencyMatrix()
{
	std::cout << "Adjacency matrix\n";
	std::cout << "| |s|a|b|c|d|e|f|g|h|i|j|\n";

	char letters[11] = { 's', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j' };

	for (int y = 0; y < 11; y++)
	{
		std::cout << '|' << letters[y] << '|';

		for (int x = 0; x < 11; x++)
		{
			// Only print if there is a valid weighting
			if (weightings[x][y] != 0)
			{
				std::cout << weightings[x][y] << "|";
			}
			else { std::cout << ' ' << "|"; }
		}
		std::cout << std::endl;
	}
}
