#include "FileInterface.h"

FileInterface::FileInterface()
{
}

FileInterface::~FileInterface()
{
}

bool FileInterface::LoadGraph()
{
	HRESULT hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);

	if (SUCCEEDED(hr))
	{
		IFileSaveDialog* pFileOpen;

		// Create the FileOpenDialog object.
		hr = CoCreateInstance(CLSID_FileOpenDialog, NULL, CLSCTX_ALL,
			IID_IFileOpenDialog, reinterpret_cast<void**>(&pFileOpen));

		// L chooses the file type
		LPCWSTR szTXT = L"Text";
		COMDLG_FILTERSPEC rgSpec[] = { {szTXT, L"*.txt"} };

		// Load text file from file explorer
		pFileOpen->SetFileTypes(1, rgSpec);

		if (SUCCEEDED(hr))
		{
			// Show the Save dialog box.
			hr = pFileOpen->Show(NULL);

			if (SUCCEEDED(hr))
			{
				// Get the file name from the dialog box.
				IShellItem* pItem;
				hr = pFileOpen->GetResult(&pItem);

				if (SUCCEEDED(hr))
				{
					PWSTR pszFilePath;
					hr = pItem->GetDisplayName(SIGDN_FILESYSPATH, &pszFilePath);

					// Display the file name to the user.
					if (SUCCEEDED(hr))
					{
						// TODO DISPLAY INFORMATION TO USER
						myfile.open(pszFilePath);

						std::string load_file_string;
						int line_count = 0;

						// collumns
						while (std::getline(myfile, load_file_string))
						{
							// rows
							for (int i = 0; i < load_file_string.size(); i++)
							{
								level_array[i][line_count] = load_file_string[i];
							}
							line_count++;
						}
						myfile.close();

						MessageBoxW(NULL, L"Text file loaded successfully", L"Success", MB_OK);
						CoTaskMemFree(pszFilePath);
					}
					pItem->Release();
				}
			}
			pFileOpen->Release();
		}
		CoUninitialize();
	}

	int start_tiles = 0;
	int exit_tiles = 0;
	int items = 0;
	int row_count = 0;

	// collumns
	for (int y = 0; y < level_height; y++)
	{
		// rows
		for (int x = 0; x < level_width; x++)
		{
			if (level_array[x][y] == 'x') 
			{ 
				exit_tiles++;
			}

			if (level_array[x][y] == 's')
			{
				start_tiles++;
			}

			if (level_array[x][y] >= 'a' && level_array[x][y] <= 'j')
			{
				items++;
			}
		}
		row_count++;
	}

	// Checks
	if (start_tiles != 1) 
	{
		std::cout << "Only one start tile allowed!\n";
		return false; 
	}
	
	if (exit_tiles != 1) 
	{ 
		std::cout << "Only one exit tile allowed!\n";
		return false; 
	}

	if (items != 10) 
	{
		std::cout << "File dosn't contain 10 exact items!\n";
		return false; 
	}
	
	if (row_count != 20) 
	{ 
		std::cout << "More / less than 20 rows!\n";
		return false; 
	} // Crashes if over

	// TODO needs update
	if (level_height != 20)
	{
		std::cout << "More / less than 20 collumns!\n";
		return false;
	}

	// Passed all checks
	return true;
}

void FileInterface::SaveFile()
{
	HRESULT hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);

	if (SUCCEEDED(hr))
	{
		IFileSaveDialog* pFileSave;

		// Create the FileOpenDialog object.
		hr = CoCreateInstance(CLSID_FileSaveDialog, NULL, CLSCTX_ALL,
			IID_IFileSaveDialog, reinterpret_cast<void**>(&pFileSave));

		// L chooses the file type
		LPCWSTR szTXT = L"Text";

		COMDLG_FILTERSPEC rgSpec[] = { {szTXT, L"*.txt"} };

		// Preload the .txt in the file explorer
		pFileSave->SetFileTypes(1, rgSpec);
		pFileSave->SetFileName(rgSpec[0].pszSpec);
		pFileSave->SetFileNameLabel(szTXT);

		if (SUCCEEDED(hr))
		{
			// Show the Save dialog box.
			hr = pFileSave->Show(NULL);

			if (SUCCEEDED(hr))
			{
				// Get the file name from the dialog box.
				IShellItem* pItem;
				hr = pFileSave->GetResult(&pItem);

				if (SUCCEEDED(hr))
				{
					PWSTR pszFilePath;

					hr = pItem->GetDisplayName(SIGDN_FILESYSPATH, &pszFilePath);

					// Write graph to file
					if (SUCCEEDED(hr))
					{
						writefile.open(pszFilePath);

						// collumns
						for (int y = 0; y < level_height; y++)
						{
							// rows
							for (int x = 0; x < level_width; x++)
							{
								writefile << level_array[x][y];
							}
							writefile << "\n";
						}

						writefile.close();

						MessageBoxW(NULL, pszFilePath, L"Saved to: ", MB_OK);
						CoTaskMemFree(pszFilePath);
					}
					pItem->Release();
				}
			}
			pFileSave->Release();
		}
		CoUninitialize();
	}
}


std::string FileInterface::PrintGraph()
{
	std::string graph = "";

	// collumns
	for (int y = 0; y < level_height; y++)
	{
		// rows
		for (int x = 0; x < level_width; x++)
		{
			graph += level_array[x][y];
		}
		graph += "\n";
	}
	return graph;
}
