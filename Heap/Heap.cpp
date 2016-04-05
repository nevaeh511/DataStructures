// Aaron Merrill
// Course: CS 2420 section: 001

#include <iostream>
#include<iomanip>
#include <cstdlib>
#include"Heap.h"
using namespace std;


Heap::Heap()
{
	used = 0;
	size = 25;
	data = new int[size];
	root = 1;
}
Heap::~Heap()
{
	delete data;
}
//Heap::Heap(int cap)
//{
//	used = 0;
//	size = cap;
//	myHeap = new int[size];
//	parentIndex = 0;
//	rightIndex = 0;
//	leftIndex = 0;
//}

void Heap::Insert(int v)
{
	int value = v;
	//if heap is full
	if (used == size)
	{
		cout << "The heap is full." << endl;
	}
	//heap not full, do this
	else
	{
		//increment used
		//Then insert value into next available spot in array
		//call BuubbleUp function
		++used;
		data[used] = value;
		BubbleUp(used, value);
	}
}
void Heap::BubbleUp(int index, int v)
{
	int value = v;
	int childIndx = index;
	int parentIndx = childIndx / 2;
	int parentValue = data[parentIndx];
	//compare the inserted value with the parent value
	//if the parents value is less than the value or if the values index is less than or equal to root
	if (parentValue <= value || childIndx <= root)
	{
		return;
	}
	//if the parents value is greater than the inserted value then swap places
	else
	{
		//int childTemp = data[childIndx];
		//data[childIndx] = data[parentIndx];
		//data[parentIndx] = childTemp;
		swap(data[parentIndx], data[childIndx]);
		BubbleUp(parentIndx, value);
	}
}
void Heap::swap(int& p, int& c)
{
	int temp = c;
	c = p;
	p = temp;
}
int Heap::RemoveFront()
{
	if (used == 0)
	{
		return -2;
	}
	else if (used > 0)
	{//remove first item in array at index 1
		int removed = data[1];
		data[1] = data[used];
		--used;
		BubbleDown(root);
		return removed;
	}
}
void Heap::BubbleDown(int p)
{
	int parentIndx = p;
	int leftChildIndx = 2 * parentIndx;
	int rightChildIndx = (2 * parentIndx) + 1;
	//if parent node has no children/ if its the root or leaf
	if (rightChildIndx > used && leftChildIndx > used)
	{
		return;
	}
	//if parent has only one child
	else if (rightChildIndx > used)
	{
		//compare parent value with left child value
		if (data[leftChildIndx] > data[parentIndx])
		{
			return;
		}
		else
		{
			swap(data[parentIndx], data[leftChildIndx]);
			BubbleDown(leftChildIndx);
		}
	}
	//if parent has two children
	else
	{
		if (data[leftChildIndx] < data[rightChildIndx])
		{
			swap(data[parentIndx], data[leftChildIndx]);
			BubbleDown(leftChildIndx);
		}
		else
		{
			swap(data[parentIndx], data[rightChildIndx]);
			BubbleDown(rightChildIndx);
		}
	}
}
////just print the array
void Heap::Print()
{
	if (used == 0)
	{
		cout << "Heap is empty! \n" << endl;
	}
	else
	{
		cout << "Heap array:" << endl;
		for (int i = 1; i <= used; i++)
		{
			cout << data[i] << " ";
		}
		cout << endl;
	}
	
}
//print tree in tabbed form
void Heap::PrintTree()
{
	if (used == 0)
	{
		cout << "[empty tree]" << endl;
	}
	else
	{
		PrintHelp(root, 0);
	}
}
void Heap::PrintHelp(int index, int depth)
{
	int leftChild = 2 * index;
	int rightChild = (2 * index) + 1;
	cout << setw(2 * depth) << "";
	if (index > used) //if there is no child node
	{
		cout << "[empty]" << endl;
	}
	else if (rightChild >= used)//if the node is a leaf
	{
		if (leftChild > used)
		{
			cout << data[index];
			cout << "-[leaf]" << endl;
		}
		else
		{
			cout << data[index];
			depth += 1;
			PrintHelp(leftChild, depth);
			PrintHelp(rightChild, depth);
		}
	}
	else
	{
		cout << data[index] << endl;
		depth += 1;
		PrintHelp(leftChild, depth);
		PrintHelp(rightChild, depth);
	}
}

int Heap::GetSize()
{
	return size;
}
int Heap::GetUsed()
{
	return used;
}
