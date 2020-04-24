#ifndef RANGE_H
#define RANGE_H

#include <stdexcept>

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
		return step > 0 && initial <= curr && curr < other.initial || step < 0 && other.initial < curr && curr <= initial;
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
	range(int start, int stop, int step) : start(start), stop(stop), step(step)
	{
		if (step == 0)
		{
			throw std::invalid_argument("invalid argument: step may not be zero.");
		}
	}

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
};

#endif