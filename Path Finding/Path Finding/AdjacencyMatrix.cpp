#include "AdjacencyMatrix.h"

// Insert a node into the adjacency matrix
void AdjacencyMatrix::InsertNode(Item* a)
{
	// Can't insert a node twice
	if (NodeExist(a))
	{
		throw "Node already exists in graph";
	}

	// Set all items to false
	for (int i = 0; i < GetNumNodes(); i++)
	{
		adjacencies[i].push_back(0.f);
	}

	node_indices[a] = max_index;
	node_labels[max_index] = a;
	max_index++;

	// Create a new row in the adjacency matrices
	std::vector<float> new_row(0.f); // Initialize with 0 as the default
	adjacencies.push_back(new_row);
}

// Connect 2 items in adjacency list
void AdjacencyMatrix::Connect(Item* a, Item* b)
{
	if (!NodeExist(a) || !NodeExist(b))
	{
		throw "Node dosn't exist";
	}

	int indexA = 0; // node_indices[a];
	int indexB = 0; // node_indices[b];

	adjacencies[indexA][indexB];
	adjacencies[indexB][indexA];
}

// Check if 2 items are connected in the adjacency list
bool AdjacencyMatrix::AreConnected(Item* a, Item* b)
{
	if (!NodeExist(a) || !NodeExist(b))
	{
		throw "Node dosn't exist";
	}

	int indexA = 0;//node_indices[a];
	int indexB = 0;//node_indices[b];

	return adjacencies[indexA][indexB] != 0; // Order of indices dosn't matter
}

// Neighbours of an item are on the same row or collumn of the adjacency matrix
std::vector<Item*> AdjacencyMatrix::GetNeighbours(Item* a)
{
	if (!NodeExist(a))
	{
		throw "Node already exists in graph";
	}

	std::vector<Item*> neighbours;

	int node_index = 0; // node_indices[a];

	// Loop over elements in the node's row of the matrix
	for (int i = 0; i < GetNumNodes(); i++)
	{
		if (adjacencies[node_index][i])
		{
			// Item* label = node_labels[i];
			Item label;
			neighbours.push_back(&label);
		}
	}

	return neighbours;
}

// Print weightings
void AdjacencyMatrix::PrintAdjacencyMatrix()
{
	std::cout << "Adjacency matrix\n";
	std::cout << "| |s|a|b|c|d|e|f|g|h|i|j|\n";

	const char letters[11] = { 's', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j' };

	for (int y = 0; y < 11; y++)
	{
		std::cout << '|' << letters[y] << '|';

		for (int x = 0; x < 11; x++)
		{
			// Only print if there is a weighting
			if (adjacencies[x][y] != 0)
			{
				std::cout << adjacencies[x][y] << "|";
			}
			else { std::cout << ' ' << "|"; }
		}
		std::cout << std::endl;
	}
}
