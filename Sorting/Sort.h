// Aaron Merrill
// Course: CS 2420 section: 001

#pragma once

#include<iostream>
#include<fstream>
#include<random>
#include<ctime>
using namespace std;



class Sort
{
private:
	//data members
	int* myArray;
	int size;

	//helper functions
	void mergeSortHelp(int* data, int s);
	void merge(int* data, int s1, int s2);
	void quickSortHelp(int* data, int s);
	void partition(int* data, int s, int& pivotIndex);

public:
	//constructor
	Sort(int arraySize, int seed);
	//destructure
	~Sort();

	friend ostream& operator<< (ostream& out, const Sort& in)
	{
		for (int i = 0; i < in.size; i++)
		{
			out << in.myArray[i] << " ";
		}
		return out;
	}

	void insertionSort();
	void selectionSort();
	void mergeSort();
	void quickSort();
	
	void swap(int& index1, int& index2);
	void addToArray();
	void set_Seed(int seed);
	int getSize();
};

