#pragma once

#include <string>
#include <iostream>
#include <string>
#include <fstream>

inline void GetLines(const std::string& fName, std::vector<std::string>& lines)
{
	char line[1024];

	lines.clear();

	std::ifstream file(fName);
	if (file.is_open())
	{
		while (!file.eof())
		{
			file.getline(line, sizeof(line) - 1);
			if (strlen(line) >= sizeof(line) - 1)
			{
				printf("GetLines: line too long\n");
				exit(-1);
			}

			lines.push_back(line);
		}
	}
}