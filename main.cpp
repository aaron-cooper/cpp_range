#include <iostream>
#include <string>
#include <cstdio>
#include <vector>

#include "range.h"

std::vector<std::string> parseArgs(int argc, char** argv)
{
	std::vector<std::string> args;

	for (int x = 0; x < argc; x++)
	{
	    args.push_back(std::string(argv[x]));
	}

	return args;
}

int main(int argc, char** argv)
{
	std::vector<std::string> args = parseArgs(argc, argv);

	if (argc == 2)
	{
		for (int i : range(stoi(args[1])))
		{
			std::cout << i << std::endl;
		}
	}
	else if (argc == 3)
	{
		for (int i : range(stoi(args[1]), stoi(args[2])))
		{
			std::cout << i << std::endl;
		}

	}
	else if (argc == 4)
	{
		for (int i : range(stoi(args[1]), stoi(args[2]), stoi(args[3])))
		{
			std::cout << i << std::endl;
		}
	}
}