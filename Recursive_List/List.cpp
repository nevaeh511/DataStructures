// Aaron Merrill
// Course: CS 2420 section: 001
// I Aaron Merrill have not used any code other than my own (or that in the textbook) for this project.
// I also have not used any function or data-structure from the Standard-Template Library. 
// I understand that any violation of this disclaimer will result in a 0 for the project.

#include "List.h"
#include <iostream>
#include <cstdlib>
using namespace std;

namespace list_2
{
	List::~List()
	{
		destroy(head);
	}

	void List::destroy(Node* n)
	{
		if (n->next != nullptr)
		{
			Node* temp = n->next;
			delete n;
			//cout << "node deleted" << endl;
			destroy(temp);
		}
		else
		{
			delete n;
			//cout << "last node deleted" << endl;
		}
	}

	// postcondition: add element d at the end of the list
	//                using recursion
	void List::addEnd(int d)
	{
		if (head == NULL)
		{
			head = new Node(d);
		}
		else
		{
			addEndRecurrsive(head, d);
		}
	}

	void List::addEndRecurrsive(Node* n, int num)
	{
		if (n->next == nullptr)
		{
			Node* temp = new Node(num);
			n->next = temp;
		}
		else
		{
			addEndRecurrsive(n->next, num);
		}
	}

	int List::size()
	{
		Node* temp = head;
		if (temp != NULL)
		{
			return size(temp);
		}
		else
		{
			return 0;
		}
	}//end size()

	//size() helper function
	int List::size(Node* n)
	{
		if (n->next == nullptr)
		{
			return 1;
		}
		else
		{
			return size(n->next) +1;
		}
	}//end size() helper

	void List::insert(int num)
	{
		Node* temp = new Node(num);
		if (head == NULL)
		{
			temp = new Node(num);
			head = temp;
		}
		else if (head->data > temp->data)
		{
			//insert before current head
			temp->next = head;
			head = temp;
		}
		else
		{
			Node* tempHead = head;
			insertHelp(temp, tempHead);
		}
	

	}//end insert

	void List::insertHelp(Node* insertNode, Node* node2)
	{
		//case 1: Gets to the end of the list
		if (node2->next == nullptr)
		{
			//compare existing data with inserting data
			if (insertNode->data < node2->data)
			{
				//insert new node before last node
				insertNode->next = node2->next; //try also insertNode->next = node2
				node2->next = insertNode;
			}
			else
			{
				//insert new node after last noe
				node2->next = insertNode;
			}
		}
		else
		{
			if (insertNode->data < node2->next->data)
			{
				//insert new node before
				insertNode->next = node2->next;
				node2->next = insertNode;
			}
			else
			{
				Node* traverse = node2->next;
				insertHelp(insertNode, traverse);
			}
		}
	}
	bool List::find(int d)
	{
		if (head == NULL)
		{
			return false;
		}
		else if (head->data == d)
		{
			return true;
		}
		else
		{
			if (find(head, d) == d)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}//end find

	int List::find(Node* node, int num)
	{
		if (node->next != nullptr)
		{
			if (node->data == num)
			{
				return node->data;
			}
			else
			{
				find(node->next, num);
			}
		}
		else
		{
			return node->data;
		}
	}//end find helper
	
	// postcondition: print the list ussing recursion
	void List::print()
	{
		if (head == NULL)
		{
			cout << "There is no list to print" << endl;
		}
		else
		{
			printHelper(head);
		}
	}
	void List::printHelper(Node* n)
	{
		if (n->next != nullptr)
		{
			cout << n->data << endl;
			printHelper(n->next);
		}
		else
		{
			cout << n->data << endl;
		}
	}
}//end namespace