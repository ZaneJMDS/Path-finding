/***********************************************************************
Author      :	Zane Sebastian Jackson
Mail        :   Zane.Jackson@mds.ac.nz
Description :	Path Finding
File name   :   Main.cpp
**************************************************************************/

#include "FileInterface.h"

// Clear console text
void ClearText()
{
	std::cout << "\x1b[2J\x1b[3J"; // Evil command that clears console text
	std::cout << "\x1b[H"; // Moves text back to top left alligned
}

// Check input is a integer
int NumCheck(int _num)
{
	std::cin.ignore(100000, '\n'); // Clears floating points
	// Don't accept a number less than or equal to 0
	while (std::cin.fail() || _num < 0)
	{
		std::cin.clear();
		std::cin.ignore(100000, '\n'); // Clears floating points

		// Keep prompting them until they get it right
		std::cout << "Please enter a valid integer above 0: ";
		std::cin >> _num;
		std::cin.ignore(100000, '\n'); // Clears floating points
	}

	return _num;
}

int main()
{
	int action = 0;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); // Colour text for the console
	FileInterface File;

	// Menu
	while (action != 10)
	{
		SetConsoleTextAttribute(h, 7); // White as default
		std::cout << "Menu\n\n";
		std::cout << "Load Graph (1)\n";
		std::cout << "Quit (10)\n";

		SetConsoleTextAttribute(h, 9); // Bright blue for input
		std::cout << "Please enter an action: ";
		std::cin >> action;
		NumCheck(action);

		SetConsoleTextAttribute(h, 7); // White as default
		std::cout << "\n";

		// Load graph
		if (action == 1)
		{
			if (File.LoadGraph())
			{
				std::cout << File.PrintGraph();

				std::cout << "Graph traversal (1)\n";
				std::cout << "Path finding (2)\n";
				std::cout << "Back to menu (3)\n";
				
				SetConsoleTextAttribute(h, 9); // Bright blue for input
				std::cout << "Please enter an action: ";
				std::cin >> action;
				NumCheck(action);

				SetConsoleTextAttribute(h, 7); // White as default
				std::cout << "\n";

				// Graph traversal
				if (action == 1) 
				{
					std::cout << "Depth-First Search (1)\n";
					std::cout << "Breadth-First Search (2)\n";
					SetConsoleTextAttribute(h, 9); // Bright blue for input
					std::cout << "Traversal algorithim: ";
					std::cin >> action;
					NumCheck(action);

					SetConsoleTextAttribute(h, 7); // White as default
					std::cout << "\n";

					// Depth-First Search
					if (action == 1)
					{

					}

					// Breadth-First Search
					else if (action == 2)
					{

					}
				}

				// Path Finding
				else if (action == 2)
				{
					SetConsoleTextAttribute(h, 9); // Bright blue for input
					std::cout << "Do you want to save result to file no (0) yes (1)";
					std::cin >> action;
					NumCheck(action);

					SetConsoleTextAttribute(h, 7); // White as default
					std::cout << "\n";

					// Save file
					if (action == 1)
					{
						File.SaveFile();
					}
				}
			}

			else
			{
				std::cout << "Invalid graph";
			}
		}

		// ClearText();
	}

	return 0;
}
