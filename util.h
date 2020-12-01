#pragma once

#include <string>
#include <iostream>
#include <string>
#include <fstream>

inline void GetLines(const std::string& fName, std::vector<std::string>& lines)
{
	lines.clear();

	std::ifstream file(fName);
	if (file.is_open())
	{
		while (!file.eof())
		{
			lines.push_back("");
			file >> lines.back();
		}
	}
}