#include "GraphTraversal.h"

// Graph and current node
// Start at an arbitrary node and search all connected nodes
void GraphTraversal::DepthFirst(AdjacencyMatrix* G, char v)
{
	// Set visit to true for current
	visited.push_back(v);

	// std::cout << "Size of " << v << "'s neighbours: " << G->GetNeighbours(v).size() << "\n";

	// For w in G neighbours
	for (int i = 0; i < G->GetNeighbours(v).size(); i++)
	{
		char w = G->GetNeighbours(v)[i];

		// Hasn't been visited
		if (std::find(visited.begin(), visited.end(), w) == visited.end())
		{
			DepthFirst(G, w);
		}
	}
}

// Uses a heap
// Maintains a queue of nodes to visit next
void GraphTraversal::BreadthFirst(AdjacencyMatrix* G, char v)
{
	std::queue<char> q; // Order of nodes to visit
	q.push(v);
	
	while (q.size() > 0)
	{
		// Get the front of the heap
		v = q.front();
		q.pop();

		// If V has'nt been visited
		if (std::find(visited.begin(), visited.end(), v) == visited.end())
		{
			visited.push_back(v);

			// Visit every neighbour until an unvisited one is reached
			for (int i = 0; i < G->GetNeighbours(v).size(); i++)
			{
				char w = G->GetNeighbours(v)[i];
				
				// If w hasn't been visited
				if (std::find(visited.begin(), visited.end(), w) == visited.end())
				{
					q.push(w);
				}
			}
		}
	}
}

// Call recursive
void GraphTraversal::DepthFirst(AdjacencyMatrix* _graph)
{
	visited.clear();

	DepthFirst(_graph, _graph->GetNodeList()[0]);

	PrintVisited();
}

// Call itterative
void GraphTraversal::BreadthFirst(AdjacencyMatrix* _graph)
{
	visited.clear();

	BreadthFirst(_graph, _graph->GetNodeList()[0]);

	PrintVisited();
}

// Print out to the user the order items were visited
// This is done in post order
void GraphTraversal::PrintVisited()
{
	std::cout << "Order visited:\n";

	// Print out the order nodes were visited
	for (int i = 0; i < visited.size(); i++)
	{
		std::cout << visited[i] << ", ";
	}

	std::cout << std::endl;
}
