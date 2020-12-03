#include <string>
#include <vector>
#include <cstdlib>
#include "util.h"

struct LineInfo
{
	unsigned long minNum;
	unsigned long maxNum;
	char letter;
	std::string password;
};

void AddLineToInfo(const std::string& line, std::vector<LineInfo>& lineInfos)
{
	LineInfo lineInfo;

	char* endPtr;
	lineInfo.minNum = strtoul(line.c_str(), &endPtr, 0);
	if (lineInfo.minNum < 0)
	{
		printf("Day2:AddLineToInfo bad min\n");
		exit(-1);
	}

	if (*endPtr++ != '-')
	{
		printf("Day2:AddLineToInfo no minus\n");
		exit(-1);
	}

	lineInfo.maxNum = strtoul(endPtr, &endPtr, 0);
	if (lineInfo.maxNum < lineInfo.minNum)
	{
		printf("Day2:AddLineToInfo max < min\n");
		exit(-1);
	}

	lineInfo.letter = endPtr[1];

	lineInfo.password = (endPtr + 4);

	lineInfos.push_back(lineInfo);
}

bool VerifyPassword0(const LineInfo& lineInfo)
{
	const size_t num = std::count(lineInfo.password.begin(), lineInfo.password.end(), lineInfo.letter);
	return ((num >= lineInfo.minNum) && (num <= lineInfo.maxNum));
}

bool VerifyPassword1(const LineInfo& lineInfo)
{
	if (lineInfo.minNum > lineInfo.password.size())
	{
		return false;
	}

	if (lineInfo.maxNum > lineInfo.password.size())
	{
		return false;
	}

	const bool minValid = lineInfo.password[lineInfo.minNum - 1] == lineInfo.letter;
	const bool maxValid = lineInfo.password[lineInfo.maxNum - 1] == lineInfo.letter;

	return minValid ^ maxValid;
}

void Day2(const std::string& fName)
{
	std::vector<std::string> lines;
	GetLines(fName, lines);

	std::vector<LineInfo> lineInfos;
	for (const std::string& line : lines)
	{
		AddLineToInfo(line, lineInfos);
	}

	size_t goodCount0 = 0;
	for (const LineInfo& lineInfo : lineInfos)
	{
		goodCount0 += VerifyPassword0(lineInfo);
	}
	printf("Day2_0: %zu\n", goodCount0);

	size_t goodCount1 = 0;
	for (const LineInfo& lineInfo : lineInfos)
	{
		goodCount1 += VerifyPassword1(lineInfo);
	}
	printf("Day2_1: %zu\n", goodCount1);
}