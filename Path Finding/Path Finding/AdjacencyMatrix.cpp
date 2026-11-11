#include "AdjacencyMatrix.h"

// Connect 2 items in adjacency list
void AdjacencyMatrix::Connect(char a, char b, int ax, int bx, int ay, int by)
{
	if (!NodeExist(a) || !NodeExist(b))
	{
		throw "Node dosn't exist";
	}

	int indexA = node_indices[a];
	int indexB = node_indices[b];

	// Pythagorous therom
	float weightings = sqrt(pow(abs(ax - bx), 2) + pow(abs(ay - by), 2));

	adjacencies[indexA][indexB] = weightings; 
	adjacencies[indexB][indexA] = weightings;
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

// Generate the neighbours according to how close they are in the level
void AdjacencyMatrix::GenerateNeighbours(char _level_array[20][20])
{
	Graph graph;
	
	std::queue<char> to_connect;
	std::queue<int> nodeX;
	std::queue<int> nodeY;

	std::vector<char> node_list = GetNodeList(); // Have to do this here

	for (int y = 0; y < 20; y++)
	{
		for (int x = 0; x < 20; x++)
		{
			// Found an item
			if (std::find(node_list.begin(), node_list.end(), _level_array[x][y]) != node_list.end())
			{
				to_connect.push(_level_array[x][y]);
				nodeX.push(x);
				nodeY.push(y);
			}

			// Found 2 items
			if (to_connect.size() == 2)
			{
				char front_node = to_connect.front();
				int frontX = nodeX.front();
				int frontY = nodeY.front();

				to_connect.pop();
				nodeX.pop();
				nodeY.pop();

				Connect(front_node, to_connect.front(), frontX, nodeX.front(), frontY, nodeY.front());
			}
		}
	}
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
	std::cout << "Adjacency matrix:\n";
	std::cout << "| |s      |a      |b      |c      |d      |e      |f      |g      |h      |i      |j      |\n";

	for (int y = 0; y < 11; y++)
	{
		std::cout << '|' << node_labels[y] << '|';

		for (int x = 0; x < 11; x++)
		{
			std::cout << std::setw(7); // Use SETW to even out spaces

			// Only print if there is a weighting
			if (adjacencies[x][y] != 0.f)
			{
				// Use SETW to even out spaces
				std::cout << adjacencies[x][y] << "|";
			}

			else { std::cout << ' ' << "|"; }
		}
		std::cout << "\n";
	}

	std::cout << "\n";
}
