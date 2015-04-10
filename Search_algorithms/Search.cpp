// Aaron Merrill
// Course: CS 2420 section: 001
// I Aaron Merrill have not used any code other than my own (or that in the textbook) for this project.
// I also have not used any function or data-structure from the Standard-Template Library. 
// I understand that any violation of this disclaimer will result in a 0 for the project.

#include<random>
#include<time.h>
#include"Search.h"
using namespace std;


bool Search::sequential_find(int num)
{
	bool found = true;
	//loop through array and test each element is equal to number searching for
	for (int i = 0; i < size; i++)
	{
		//if first element is the number
		if (num == data[i])
		{
			return found;
		}
	}
	return false;
}
bool Search::recursive_binary_find(int num)
{
	return recursive_binary_find(num, 0, size - 1);	
}
bool Search::recursive_binary_find(int num, int low, int high)
{
	//subtract the high index from the low index then divide by two
	//to get the mid point index
	int mid = (high + low) / 2;
	//stopping case: test if the mid point value is equal to the number
	if (num == data[mid])
	{
		return true;
	}
	//case 1: if 
	else if (high < low)
	{
		return false;
	}
	else if (num > data[mid])
	{
		return recursive_binary_find(num, mid+1, high);
	}
	else
	{
		return recursive_binary_find(num, low, mid - 1);
	}
}
bool Search::iterative_binary_find(int num)
{
	int low = 0;
	int high = size - 1;
	bool found = true;
	while (!found && high < low)
	{
		int mid = (high + low) / 2;
		if (data[mid] == num)
		{
			return found;
		}
		else if (num < data[mid])
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
	//return false if the number is not found in the array
	return (!found);
}
void Search::init_array()
{
	for (int i = 0; i < size; i++)
	{
		data[i] = rand() % size;
	}
}
void Search::init_sorted_array()
{
	data[0] = rand() % MOD;
	for (int i = 1; i < size; ++i)
	{
		data[i] = data[i-1] + rand() % MOD +1;
	}
}
void Search::set_seed(int seed)
{
	srand(seed);
}
int Search::getSize()
{
	return size;
}
//constructor
Search::Search(int s, int seed)
{
	size = s;
	data = new int[size];
	set_seed(seed);
}
//destructor
Search::~Search()
{
	delete[] data;
}