// Aaron Merrill
// Course: CS 2420 section: 001

#include<iostream>
#include<random>
#include"Sort.h"

Sort::Sort(int arraySize, int seed)
{
	size = arraySize;
	myArray = new int[size];
	set_Seed(seed);
}
Sort::~Sort()
{
	//int i = 0;
	delete [] myArray;
}
void Sort::insertionSort()
{
	int savedNum = 0;
	int i;
	int j;
	int emptySpot;
	//unsorted side of the array
	//this increment to the right
	for (i = 1; i < size; i++)
	{
		savedNum = myArray[i];
		//sorted side the array
		//this decrements to the left comparing if i (saved number) is less than j
		for (j = i; j > 0; j--)
		{
			if (savedNum < myArray[j - 1])
			{
				//move j-1 to the right at j
				myArray[j] = myArray[j-1];
			}
			else
			{
				break;
			}
		}
		emptySpot = j;
		myArray[emptySpot] = savedNum;
	}
}
void Sort::selectionSort()
{
	int indexOfLargest;
	int largest;

	for (int i = size-1; i > 0; --i)
	{
		indexOfLargest = 0;
		largest = myArray[0];
		for (int j = 1; j <= i; ++j)
		{
			if (myArray[j] > largest)
			{
				largest = myArray[j];
				indexOfLargest = j;
			}
		}
		swap(myArray[i], myArray[indexOfLargest]);
	}
}

void Sort::mergeSort()
{
	mergeSortHelp(myArray, size);
}

void Sort::merge(int* data, int s1, int s2)
{
	int* temp;
	int copied = 0;
	int copied1 = 0;
	int copied2 = 0;

	temp = new int[s1 + s2];
	
	while ((copied1 < s1) && (copied2 < s2))
	{
		if (data[copied1] < (data + s1)[copied2])
		{
			temp[copied++] = data[copied1++];
		}
		else
		{
			temp[copied++] = (data + s1)[copied2++];
		}
	}

	while (copied1 < s1)
	{
		temp[copied++] = data[copied1++];
	}
	while (copied2 < s2)
	{
		temp[copied++] = (data + s1)[copied2++];
	}

	for (int i = 0; i < s1+s2; i++)
	{
		data[i] = temp[i];
	}

	delete[] temp;
}

void Sort::mergeSortHelp(int* data, int s)
{
	int size1; // size of left sub-array
	int size2; //size of right sub-array

	if (s > 1)
	{
		size1 = s / 2;
		size2 = s - size1;

		mergeSortHelp(data, size1);
		mergeSortHelp((data + size1), size2);

		merge(data, size1, size2);
	}
}

void Sort::quickSort()
{
	quickSortHelp(myArray, size);
}

void Sort::quickSortHelp(int* data, int s)
{
	int pivotIndex = 0;
	int size1 = 0;
	int size2 = 0;

	if (s > 1)
	{
		partition(data, s, pivotIndex);
		size1 = pivotIndex;
		size2 = s - size1 - 1;

		quickSortHelp(data, size1);
		quickSortHelp((data + pivotIndex + 1), size2);
	}
}
void Sort::partition(int* data, int s, int& pivotIndex)
{
	
	int pivot = data[0];
	int biggerThanIndex = 1;
	int lessThanIndex = s - 1;

	while (biggerThanIndex <= lessThanIndex)
	{
		while (biggerThanIndex < s && data[biggerThanIndex] <= pivot)
		{
			biggerThanIndex++;
		}
		while (data[lessThanIndex] > pivot)
		{
			lessThanIndex--;
		}
		if (biggerThanIndex < lessThanIndex)
		{
			swap(data[biggerThanIndex], data[lessThanIndex]);
		}
	}
	pivotIndex = lessThanIndex;
	data[0] = data[pivotIndex];
	data[pivotIndex] = pivot;
}//end of partition

void Sort::swap(int& index1, int& index2)
{
	int temp = index1;
	index1 = index2;
	index2 = temp;
}
void Sort::addToArray()
{
	for (int i = 0; i < size; i++)
	{
		int r = rand();
		myArray[i] = r % size;
	}
}

void Sort::set_Seed(int seed)
{
	srand(seed);
}
int Sort::getSize()
{
	return size;
}