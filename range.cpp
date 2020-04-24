#include <iostream>
#include <string>
#include <cstdio>
#include <vector>

class range_iter
{
public:

	range_iter(int start) : range_iter(start, 1) {}
	range_iter(int start, int step) : initial(start), curr(start), step(step){}


	int operator*()
	{
		return curr;
	}

	void operator++()
	{
		range_iter::curr += step;
	}

	bool operator != (const range_iter &other) const
	{
		return initial <= curr && curr < other.initial && step > 0 || other.initial < curr && curr <= initial && step < 0;
	}

private:
	int initial;
	int curr;
	int step;
};


class range
{
public:
	range(int stop) : range(0, stop, 1) {}
	range(int start, int stop) : range(start, stop, 1) {}
	range(int start, int stop, int step) : start(start), stop(stop), step(step) {}

	range_iter begin()
	{
		return range_iter(start, step);
	}

	range_iter end()
	{
		return range_iter(stop);
	}

private:
	int start;
	int stop;
	int step;
	bool invalid;
};


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