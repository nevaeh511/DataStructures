// Aaron Merrill
// Course: CS 2420 section: 001

#include <cstdlib>
using namespace std;
class Heap
{
private:
	// Array to input values
	int* data;
	int size;
	int used;
	int root;
	void BubbleUp(int index, int val);
	void BubbleDown(int childIndx);
	void swap(int& p, int& c);
	void PrintHelp(int index, int depth);

public:
	//constructor
	Heap();
	//Heap(int cap);
	//destructor
	~Heap();
	void Insert(int v);
	int RemoveFront();
	//just print the array
	void Print();
	//print tree in tabbed form
	void PrintTree();
	int GetSize();
	int GetUsed();
};