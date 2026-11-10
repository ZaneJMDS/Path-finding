#include "GraphTraversal.h"

// Graph and current node
// Start at an arbitrary node and search all connected nodes
void GraphTraversal::DepthFirst(AdjacencyMatrix* G, Item* v)
{
	// Set visit to true for current
	v->visited = true;

	// For w in G neighbours
	for (int i = 0; G->GetNeighbours(v).size(); i++)
	{
		Item* w = G->GetNeighbours(v)[i];

		if (!w->visited)
		{
			DepthFirst(G, w);
		}
	}
}

// Uses a heap
// Maintains a queue of nodes to visit next
void GraphTraversal::BreadthFirst(AdjacencyMatrix* G, Item* v)
{
	std::queue<Item*> q; // Order of nodes to visit
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
			for (int i = 0; i < G->GetNeighbours(v).size(); i++)
			{
				Item* w = G->GetNeighbours(v)[i];
				
				if (!w->visited)
				{
					q.push(w);
				}
			}
		}
	}
}

// Call recursive
void GraphTraversal::DepthFirst()
{
	AdjacencyMatrix graph;

	DepthFirst(&graph, graph.GetNodeList()[0]);
}

// Call itterative
void GraphTraversal::BreadthFirst()
{
	AdjacencyMatrix graph; // Graph

	BreadthFirst(&graph, graph.GetNodeList()[0]);
}
