// Aaron Merrill
// Course: CS 2420 section: 001

#include"BST.h"
#include<iostream>
#include<iomanip>
using namespace std;

BST::BST()
{
	root = nullptr;
}

BST::~BST()
{
	//delete all pointers in the tree
	BSTdelete(root);
}
void BST::BSTdelete(node* n)
{
	if (n != nullptr)
	{
		BSTdelete(n->left);
		BSTdelete(n->right);
		delete n;
	}
}

int BST::Size()
{
	return sizeHelper(root);
}
int BST::sizeHelper(node* n)
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

void BST::Print()
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
void BST::PrintHelp(node* n_ptr, int depth)
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

bool BST::isLeaf(node*& n)
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

void BST::Erase(int item)
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
void BST::deleteItem(node*& n_ptr)
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
node*& BST::findRightMost(node*& n_ptr)
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
node*& BST::findItem(node*& n_ptr, int item)
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

void BST::Insert(int item)
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

void BST::Insert(node* n, int item)
{
	//is the item less than the parent item
	if (item < n->data)
	{
		if (n->left == nullptr)
		{
			n->left = new node(item);
		}
		else
		{
			Insert(n->left, item);
		}
	}
	else
	{
		if (n->right == nullptr)
		{
			//insert the node here
			n->right = new node(item);
		}
		else
		{
			Insert(n->right, item);
		}
	}
}


void BST::Traversals()
{
	cout << "Pre-order:" << "\n" << endl;
	preOrder(root);
	cout << "\n" << "In-order:" << "\n" << endl;
	inOrder(root);
	cout << "\n" <<  "Post-order:" << "\n" << endl;
	postOrder(root);
}
void BST::preOrder(const node* n_ptr)
{
	if (n_ptr != nullptr)
	{
		cout << n_ptr->data << endl;
		preOrder(n_ptr->left);
		preOrder(n_ptr->right);
	}
}
void BST::inOrder(const node* n_ptr)
{
	if (n_ptr != nullptr)
	{
		inOrder(n_ptr->left);
		cout << n_ptr->data << endl;
		inOrder(n_ptr->right);
	}
}
void BST::postOrder(const node* n_ptr)
{
	if (n_ptr != nullptr)
	{
		postOrder(n_ptr->left);
		postOrder(n_ptr->right);
		cout << n_ptr->data << endl;
	}
}
