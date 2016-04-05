// Aaron Merrill
// Course: CS 2420 section: 001

#include"Node.h"
#include<iostream>
using namespace std;


class BST
{
public:
	//constructor
	BST();

	//destructor
	~BST();
	void BSTdelete(node* n);

	//Pre condition:
	//Post condition: An integer will be returned
	int Size();
	//Pre condition: A valid node pointer is passed
	//Post condition: returns an integer to the size() function
	int sizeHelper(node* n);

	//Pre condition:
	//Post condition: calls the PrintHelp function
	void Print();
	//Pre condition: a valid node pointer is passed and an integer value is passed
	//Post condition: Prints out the binary search tree in indented form
	void PrintHelp(node* n_ptr, int depth);
	//Pre condition: a reference to a node pointer is passed
	//Post condition: returns a true or false value
	bool isLeaf(node*& n);

	//Pre condition: an integer is passed as an argument
	//Post condition: calls the deleteItem function
	void Erase(int item);
	//Pre condition: a reference to a node pointer is passed
	//Post condition: the item passed will be deleted from the BST
	void deleteItem(node*& n);
	//Pre condition: a reference to a node pointer is passed and an integer value is passed
	//Post condition: this will return a node pointer reference
	node*& findItem(node*& n, int item);
	//Pre condition: a reference to a node pointer is passed
	//Post condition: This traverses left by one of the node passed then traverse all the way right to return a reference pointer
	node*& findRightMost(node*& n);

	//Pre condition: an integer is passed as an argument
	//Post condition: calls the Insert helper function
	void Insert(int item);
	//Pre condition: a valid node pointer is passed and an integer value is passed
	//Post condition: the item that was passed is inserted into the tree
	void Insert(node* n, int item);

	//Pre condition: there is something in the BST
	//Post condition: will print out the Pre, In, & Post order traversals
	void Traversals();
	//Pre condition: a node pointer is passed
	//Post condition: Prints out a pre order traversal
	void preOrder(const node* n_ptr);
	//Pre condition a node pointer is passed
	//Post condition: Prints out an in order traversal
	void inOrder(const node* n_ptr);
	//Pre condition: a node pointer is passed
	//Post condition: Prints out a post order traversal
	void postOrder(const node* n_ptr);

private:
	node* root;
};
