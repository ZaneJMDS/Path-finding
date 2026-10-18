#include "AdjacencyMatrix.h"

void AdjacencyMatrix::PrintMatrix()
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
