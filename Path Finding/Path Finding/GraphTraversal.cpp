#include "GraphTraversal.h"

// Graph and current node
// Start at an arbitrary node and search all connected nodes
void GraphTraversal::DepthFirst(std::vector<Item*> G, Item* v)
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
void GraphTraversal::BreadthFirst(std::vector<Item*> G, Item* v)
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
	std::vector<Item*> graph;
	Item s('s', 0.f); // Start
	DepthFirst(graph, graph[0]);
}

// Call itterative
void GraphTraversal::BreadthFirst()
{
	std::vector<Item*> graph; // Graph
	Item s('s', 0.f); // start
	BreadthFirst(graph, graph[0]);
}
