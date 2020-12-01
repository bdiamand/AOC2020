#include <string>
#include <vector>
#include "util.h"

void Day1(const std::string& fName)
{
	std::vector<std::string> lines;
	GetLines(fName, lines);

	if (lines.size() < 3)
	{
		printf("Day1 parse error\n");
		return;
	}

	std::vector<int32_t> intLines;
	for (const std::string& line : lines)
	{
		intLines.push_back(std::stoi(line));
	}

	for (std::vector<int32_t>::const_iterator iter0 = intLines.begin(); iter0 != intLines.end() - 1; ++iter0)
	{
		for (std::vector<int32_t>::const_iterator iter1 = iter0 + 1; iter1 != intLines.end(); ++iter1)
		{
			const int64_t sum = (int64_t )*iter0 + (int64_t)*iter1;
			if (sum == 2020)
			{
				const int64_t product = (int64_t)*iter0 * (int64_t)*iter1;
				printf("Day1_0: %llu\n", product);
				goto part2;
			}
		}
	}

part2:
	for (std::vector<int32_t>::const_iterator iter0 = intLines.begin(); iter0 != intLines.end() - 2; ++iter0)
	{
		for (std::vector<int32_t>::const_iterator iter1 = iter0 + 1; iter1 != intLines.end() - 1; ++iter1)
		{
			for (std::vector<int32_t>::const_iterator iter2 = iter1 + 1; iter2 != intLines.end(); ++iter2)
			{
				const int64_t sum = (int64_t)*iter0 + (int64_t)*iter1 + (int64_t)*iter2;
				if (sum == 2020)
				{
					const int64_t product = (int64_t)*iter0 * (int64_t)*iter1 * (int64_t)*iter2;
					printf("Day1_1: %llu\n", product);
				}
			}
		}
	}
}