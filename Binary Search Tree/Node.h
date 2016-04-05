// Aaron Merrill
// Course: CS 2420 section: 001

#include<cstdlib>
using namespace std;

struct node
{
	//nodes data value
	int data;
	//pointer to the left child node
	node* left;
	//pointer to the right child node
	node* right;

	node(int val)
	{
		data = val;
		left = nullptr;
		right = nullptr;
	}
};