#include "GraphTraversal.h"

// Graph and current node
void GraphTraversal::DepthFirst(Node* G, Node* v)
{
	// Set visit to true for current
	v->visited = true;

	// For w in G neighbours
	for (int i = 0; G->neighbours.size(); i++)
	{
		Node* w = G->neighbours[i];

		if (!w->visited)
		{
			// Recurse
			DepthFirst(G, w);
		}
	}
}

void GraphTraversal::BreadthFirst(Node* G, Node* v)
{
	q.push(v);

	while (q.size() > 0)
	{
		// Get the front of the queue
		v = q.front();
		q.pop();

		if (!v->visited)
		{
			v->visited = true;

			for (int i = 0; G->neighbours.size(); i++)
			{
				Node* w = G->neighbours[i];
				
				if (!w->visited)
				{
					q.push(w);
				}
			}
		}
	}
}
