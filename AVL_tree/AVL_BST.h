// Aaron Merrill
// Course: CS 2420 section: 001
// I Aaron Merrill have not used any code other than my own (or that in the textbook) for this project.
// I also have not used any function or data-structure from the Standard-Template Library. 
// I understand that any violation of this disclaimer will result in a 0 for the project.


#include"Node.h"
#include<iostream>
using namespace std;


class AVL_BST
{
public:
	//constructor
	AVL_BST();

	//destructor
	~AVL_BST();
	
	//Pre condition:
	//Post condition: calls the PrintHelp function
	void Print();
	//Pre condition: a valid node pointer is passed and an integer value is passed
	//Post condition: Prints out the binary search tree in indented form
	void PrintHelp(node* n_ptr, int depth);
	//Pre condition: an integer is passed as an argument
	//Post condition: calls the Insert helper function
	void Insert(int item);
	//Pre condition: a valid node pointer is passed and an integer value is passed
	//Post condition: the item that was passed is inserted into the tree
	void Insert(node*& n, int item);
	//Pre condition:
	//Post condition: balances the right subtree thats heavy on outside
	void RotateRight(node*& nodeN);
	//Pre condition:
	//Post condition: balances the left subtree thats heavy on outside
	void RotateLeft(node*& nodeN);
	//Pre condition:
	//Post condition: balances the left subtree thats heavy on inside
	void LeftRightRotate(node*& nodeN);
	//Pre condition: 
	//Post condition: balances the right subtree thats heavy on inside
	void RightLeftRotate(node*& nodeN);
	//Pre condition: a valid node pointer is passed
	//Post condition: the tree is balanced
	void Rebalance(node*& nodeN);
	//Pre condition: a valid node pointer is passed
	//Post condition:returns an integer to update the nodes height
	int UpdateHeight(node*& nodeN);
	//Pre condition:
	//Post condition: determines if the tree needs to be balanced
	void checkBalance(node*& nodeN);

private:
	node* root;

	void preOrder(node*& n_ptr);
	//Pre condition: given valid node pointers with height values
	//Post condition: returns the difference of left and right nodes
	int getHeightDiff(node* nodeN);
	//Pre condition: given a valid node pointer with height value
	//Post condition: returns a nodes height value
	int getHeight(node* nodeN);
	//Pre condition:
	//Post condition: reallocates memory
	void BSTdelete(node* n);
	//Pre condition:
	//Post condition: An integer will be returned
	int Size();
	//Pre condition: A valid node pointer is passed
	//Post condition: returns an integer to the size() function
	int sizeHelper(node* n);
	//Pre condition: a reference to a node pointer is passed and an integer value is passed
	//Post condition: this will return a node pointer reference
	node*& findItem(node*& n, int item);
	//Pre condition: a reference to a node pointer is passed
	//Post condition: This traverses left by one of the node passed then traverse all the way right to return a reference pointer
	node*& findRightMost(node*& n);
	//Pre condition: a reference to a node pointer is passed
	//Post condition: returns a true or false value
	bool isLeaf(node*& n);
	//Pre condition: an integer is passed as an argument
	//Post condition: calls the deleteItem function
	void Erase(int item);
	//Pre condition: a reference to a node pointer is passed
	//Post condition: the item passed will be deleted from the BST
	void deleteItem(node*& n);
};
