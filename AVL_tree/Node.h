// Aaron Merrill
// Course: CS 2420 section: 001
// I Aaron Merrill have not used any code other than my own (or that in the textbook) for this project.
// I also have not used any function or data-structure from the Standard-Template Library. 
// I understand that any violation of this disclaimer will result in a 0 for the project.


#include<cstdlib>
#include<algorithm>
using namespace std;

struct node
{
	//nodes data value
	int data;
	//pointer to the left child node
	node* left;
	//pointer to the right child node
	node* right;
	int height;

	node::node(int val)
	{
		data = val;
		left = nullptr;
		right = nullptr;
		height = 1;
	}

};