#ifndef RANGE_H
#define RANGE_H

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

#endif