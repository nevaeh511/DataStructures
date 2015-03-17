// Aaron Merrill
// Course: CS 2420 section: 001
// I Aaron Merrill have not used any code other than my own (or that in the textbook) for this project.
// I also have not used any function or data-structure from the Standard-Template Library. 
// I understand that any violation of this disclaimer will result in a 0 for the project.

#include"AVL_BST.h"
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

AVL_BST::AVL_BST()
{
	root = nullptr;
}

AVL_BST::~AVL_BST()
{
	//delete all pointers in the tree
	BSTdelete(root);
}
void AVL_BST::BSTdelete(node* n)
{
	if (n != nullptr)
	{
		BSTdelete(n->left);
		BSTdelete(n->right);
		delete n;
	}
}

int AVL_BST::Size()
{
	return sizeHelper(root);
}
int AVL_BST::sizeHelper(node* n)
{
	int count = 1;
	//base case
	if (n == nullptr)
	{
		return 0;
	}
	else
	{
		count += sizeHelper(n->left);
		count += sizeHelper(n->right);
		return count;
	}
}

void AVL_BST::Print()
{
	if (root == nullptr)
	{
		cout << "[empty tree]" << endl;
	}
	else
	{
		PrintHelp(root, 0);
	}
}
void AVL_BST::PrintHelp(node* n_ptr, int depth)
{
	//preorder traversal
	cout << setw(4 * depth) << "";
	if (n_ptr == nullptr) //if there is no child node
	{
		cout << "[empty]" << endl;
	}
	else if (isLeaf(n_ptr))//if the node is a leaf
	{
		cout << n_ptr->data;
		cout << "-[leaf]" << endl;
	}
	else
	{
		cout << n_ptr->data << endl;
		depth += 1;
		PrintHelp(n_ptr->left, depth);
		PrintHelp(n_ptr->right, depth);
	}
}

bool AVL_BST::isLeaf(node*& n)
{
	if (n->left == nullptr && n->right == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void AVL_BST::Erase(int item)
{
	if (root == nullptr)
	{
		return;
	}
	else
	{
		node*& found = findItem(root, item);
		if (found == nullptr)
		{
			cout << "Item not in tree!" << endl;
		}
		else
		{
			deleteItem(found);
		}
	}
}
void AVL_BST::deleteItem(node*& n_ptr)
{
	//if node has no children. It's a leaf
	if (n_ptr->left == nullptr && n_ptr->right == nullptr)
	{
		delete n_ptr;
		//node* temp = n_ptr;
		n_ptr = nullptr;
	}
	//if the nodes left child is null
	else if (n_ptr->left == nullptr)
	{
		node* temp = n_ptr;
		n_ptr = n_ptr->right;
		delete temp;
	}
	//if the nodes right child is null
	else if (n_ptr->right == nullptr)
	{
		node* temp = n_ptr;
		n_ptr = n_ptr->left;
		delete temp;
	}
	//if the node has two children
	else
	{
		//traverse left by one then traverse to rightmost node
		node*& rightMost = findRightMost(n_ptr->left);
		//make n_ptr value = returned node value
		n_ptr->data = rightMost->data;
		deleteItem(rightMost);
	}
}
node*& AVL_BST::findRightMost(node*& n_ptr)
{
	//traverse all the way to the rightmost node
	if (n_ptr->right == nullptr)
	{
		//node*& found = n_ptr;
		//deleteItem(n_ptr);
		//return found;
		return n_ptr;
	}
	else
	{
		return findRightMost(n_ptr->right);
	}
}
node*& AVL_BST::findItem(node*& n_ptr, int item)
{
	if (n_ptr == nullptr || n_ptr->data == item)
	{
		return n_ptr;
	}
	else
	{
		if (item < n_ptr->data)
		{
			return findItem(n_ptr->left, item);
		}
		else
		{
			return findItem(n_ptr->right, item);
		}
	}
}

void AVL_BST::Insert(int item)
{
	if (root == nullptr)
	{
		//create root node
		root = new node(item);
	}
	else
	{
		Insert(root, item);
	}
}

void AVL_BST::Insert(node*& n, int item)
{
	if (n == nullptr)
	{
		n = new node(item);
	}
	else
	{
		if (item < n->data)
		{
			Insert(n->left, item);
			n->height = UpdateHeight(n);
		}
		else
		{
			Insert(n->right, item);
			n->height = UpdateHeight(n);
		}
	}
	checkBalance(n);
}

int AVL_BST::UpdateHeight(node*& nodeN)
{
	//get greatest height between left and right child and add 1
	//return new updated height for current node
	return max(getHeight(nodeN->left), getHeight(nodeN->right)) + 1;
}

void AVL_BST::checkBalance(node*& nodeN)
{
	//if childrens height difference is greater than 1
	//call rebalance
	if (getHeightDiff(nodeN) == 2 || getHeightDiff(nodeN) == -2)
	{
		Rebalance(nodeN);
	}
	else
	{
		return;
	}
}
void AVL_BST::Rebalance(node*& nodeN)
{
	node* lchild = nodeN->left;
	node* rchild = nodeN->right;
	//if the unbalance is on left side
	if (getHeightDiff(nodeN) == 2)
	{
		//case a: single right rotation
		//if left grand child minus right grandchild equals 1
		if (getHeightDiff(nodeN->left) == 1)
		{
			RotateRight(nodeN);
		}
		//case b: left right rotation
		//if left grandchild minus right grandchild equals -1
		else
		{
			LeftRightRotate(nodeN);
		}
	}
	else // difference is -2  then unbalanced on right subtree of current node
	{
		//if right grandchilds height is greater than left
		//rotate left
		if (getHeightDiff(nodeN->right) == -1)
		{
			RotateLeft(nodeN);
		}
		//if current nodes right grandchilds height is greater than the right then rotate right then left
		else
		{
			RightLeftRotate(nodeN);
		}
	}
	//nodeN->height = UpdateHeight(nodeN);
}
void AVL_BST::RotateRight(node*& nodeN)
{
	node* nodeC = nodeN->left;
	nodeN->left = nodeC->right;
	nodeC->right = nodeN;
	nodeN = nodeC;
	preOrder(nodeN);
}
void AVL_BST::RotateLeft(node*& nodeN)
{
	node* nodeC = nodeN->right;
	nodeN->right = nodeC->left;
	nodeC->left = nodeN;
	nodeN = nodeC;
	preOrder(nodeN);
}
void AVL_BST::LeftRightRotate(node*& nodeN)
{
	node* nodeC2 = nodeN->left;
	RotateLeft(nodeC2);
	nodeN->left = nodeC2;
	RotateRight(nodeN);
	nodeN->height = UpdateHeight(nodeN);
}
void AVL_BST::RightLeftRotate(node*& nodeN)
{
	node* nodeC = nodeN->right;
	RotateRight(nodeC);
	nodeN->right = nodeC;
	RotateLeft(nodeN);
	nodeN->height = UpdateHeight(nodeN);
}

int AVL_BST::getHeightDiff(node* nodeN)
{
	int difference = (getHeight(nodeN->left) - getHeight(nodeN->right));
	return difference;
}
int AVL_BST::getHeight(node* nodeN)
{
	if (nodeN == nullptr)
	{
		return 0;
	}
	else
	{
		int height = nodeN->height;
		return height;
	}
}

void AVL_BST::preOrder(node*& n_ptr)
{
	if (n_ptr != nullptr)
	{
		preOrder(n_ptr->left);
		n_ptr->height = UpdateHeight(n_ptr);
		preOrder(n_ptr->right);
		n_ptr->height = UpdateHeight(n_ptr);
	}
}