/***********************************************************************
Author      :	Zane Sebastian Jackson
Description :	Load a level with obstacles and items
File name   :   FileInterface.h
**************************************************************************/

#pragma once
#include <fstream> 
#include <iostream>
#include <string>
#include <windows.h>
#include <ShObjIdl.h> // Includes file types

class FileInterface
{
public:
	// Level dimensions
	static const int level_width = 20;
	static const int level_height = 20;

	char level_array[level_width][level_height]; // Array holding level tiles

	FileInterface();
	~FileInterface();

	bool LoadGraph();
	void SavePath(char _level_path[20][20]);
	std::string PrintGraph();
};

