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

	float weightings = GetWeightings(ax, bx, ay, by);

	adjacencies[indexA][indexB] = weightings; 
	adjacencies[indexB][indexA] = weightings;
}

void AdjacencyMatrix::Connect(char a, char b, float _weighting)
{
	if (!NodeExist(a) || !NodeExist(b))
	{
		throw "Node dosn't exist";
	}

	int indexA = node_indices[a];
	int indexB = node_indices[b];

	adjacencies[indexA][indexB] = _weighting;
	adjacencies[indexB][indexA] = _weighting;
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
	std::vector<char> node_list = GetNodeList();

	std::vector<char> to_connect;
	std::vector<char> nodeX;
	std::vector<char> nodeY;

	// Search through map for items
	for (int y = 0; y < 20; y++)
	{
		for (int x = 0; x < 20; x++)
		{
			// Found an item
			if (std::find(node_list.begin(), node_list.end(), _level_array[x][y]) != node_list.end())
			{
				to_connect.push_back(_level_array[x][y]);
				nodeX.push_back(x);
				nodeY.push_back(y);
			}
		}
	}

	std::vector<float> temp_weightings;

	// Search for connections
	for (int i = 0; i < to_connect.size(); i++)
	{
		temp_weightings.clear();

		for (int j = 0; j < to_connect.size(); j++)
		{
			if (i != j)
			{
				temp_weightings.push_back(GetWeightings(nodeX[i], nodeX[j], nodeY[i], nodeY[j]));
			}

			else
			{
				temp_weightings.push_back(1000);
			}
		}

		// Create connections
		float weighting1 = 1000;
		float weighting2 = 1000;
		char connectA = ' ';
		char connectB = ' ';

		for (int j = 0; j < temp_weightings.size(); j++)
		{
			if (temp_weightings[j] < weighting1)
			{
				weighting1 = temp_weightings[j];
				connectA = to_connect[j];
			}

			if (temp_weightings[j] < weighting2 && temp_weightings[j] != weighting1)
			{
				weighting2 = temp_weightings[j];
				connectB = to_connect[j];
			}
		}

		Connect(to_connect[i], connectA, weighting1);
		Connect(to_connect[i], connectB, weighting2);
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

// Get the distance between the nodes
float AdjacencyMatrix::GetWeightings(int ax, int bx, int ay, int by)
{
	return sqrt(pow(abs(ax - bx), 2) + pow(abs(ay - by), 2));
}
