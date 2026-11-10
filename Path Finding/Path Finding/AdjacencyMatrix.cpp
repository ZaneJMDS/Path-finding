#include "AdjacencyMatrix.h"

// Connect 2 items in adjacency list
void AdjacencyMatrix::Connect(char a, char b)
{
	if (!NodeExist(a) || !NodeExist(b))
	{
		throw "Node dosn't exist";
	}

	// Subtract the ascii value
	int indexA = node_indices[a];
	int indexB = node_indices[b];

	adjacencies[indexA][indexB] = 1.f; // Need to get weightings
	adjacencies[indexB][indexA] = 1.f;
}

// Check if 2 items are connected in the adjacency list
bool AdjacencyMatrix::AreConnected(char a, char b)
{
	if (!NodeExist(a) || !NodeExist(b))
	{
		throw "Node dosn't exist";
	}

	int indexA = node_indices[a];
	int indexB = node_indices[b];

	return adjacencies[indexA][indexB] != 0.f; // Order of indices dosn't matter
}

// Neighbours of an item are on the same row or collumn of the adjacency matrix
std::vector<char> AdjacencyMatrix::GetNeighbours(char a)
{
	if (!NodeExist(a))
	{
		throw "Node already exists in graph";
	}

	std::vector<char> neighbours;

	int node_index = node_indices[a];

	// Loop over elements in the node's row of the matrix
	for (int i = 0; i < GetNumNodes(); i++)
	{
		// If there is a value in this collumn
		if (adjacencies[node_index][i] != 0.f)
		{
			neighbours.push_back(node_labels[i]);
		}
	}

	return neighbours;
}

// Print weightings between items
void AdjacencyMatrix::PrintAdjacencyMatrix()
{
	std::cout << "Adjacency matrix\n";
	std::cout << "| |s|a|b|c|d|e|f|g|h|i|j|\n";

	for (int y = 0; y < 11; y++)
	{
		std::cout << '|' << node_labels[y] << '|';

		for (int x = 0; x < 11; x++)
		{
			// Only print if there is a weighting
			if (adjacencies[x][y] != 0.f)
			{
				// Use SETW to even out spaces
				std::cout << adjacencies[x][y] << "|";
				std::cout << node_indices[x] << "|";
				std::cout << std::setw(5);
			}
			else { std::cout << ' ' << "|"; }
		}
		std::cout << std::endl;
	}
}
