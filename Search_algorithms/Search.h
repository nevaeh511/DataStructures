// Aaron Merrill
// Course: CS 2420 section: 001

#pragma once

#include <iostream>
#include <fstream>

using namespace std;

class Search
{
public:
	bool sequential_find(int num);
	bool recursive_binary_find(int num);
	bool recursive_binary_find(int num, int low, int high);
	bool iterative_binary_find(int num);

	void init_array();
	void init_sorted_array();
	void set_seed(int seed);
	int getSize();

	// this is just for practice and debugging.
	friend ostream& operator<< (ostream& out, const Search& s)
	{
		for (int i = 0; i < s.size; ++i)
		{
			out << s.data[i] << endl;
		}
		return out;
	}

	Search(int s, int seed = 0);
	~Search();

private:
	int size;
	int* data;
	const int MOD = 5;
};


