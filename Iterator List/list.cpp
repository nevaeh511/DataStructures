// Aaron Merrill
// Course: CS 2420 section: 001

#include"Iterator.h"
#include"list.h"
#include <cstdlib>
#include <iostream>
using namespace std;

namespace list_1
{
	// CONSTRUCTOR
	list::list()
	{
		head = NULL;
	}
	// postcondition: all nodes in the list are destroyed.
	list::~list()
	{
		//iterate through linked list and delete each node
		Node* temp = head;
		Node* moveRight;

		while (head != NULL)
		{
			if (temp->next != nullptr)
			{
				moveRight = temp->next;
				delete temp;
				temp = moveRight;
			}
			else
			{
				delete temp;
				head = NULL;
			}
		}
	}
	// MODIFICATION MEMBER FUNCTIONS
	//postcondition: entry is added to the front of the list
	void list::insert_front(const int& entry)
	{
		if (head == NULL)
		{
			//add first node
			head = new Node(entry);
		}
		else
		{
			Node* temp = new Node(entry);
			temp->next = head;
			head = temp;
		}
	}
	//postcondition: entry is added to the back of the list
	void list::add_back(const int& entry)
	{
		if (head == NULL)
		{
			Node* insert = new Node(entry);
			head = insert;
		}
		else
		{
			Node* temp = head;
			//iterate until it sees the next node to be a nullptr
			if (temp->next == nullptr)
			{
				Node* insert = new Node(entry);
				temp->next = insert;
			}
			else //if it is not equal to null
			{
				while (temp->next != nullptr)
				{
					temp = temp->next;
				}
				Node* insert = new Node(entry);
				temp->next = insert;
			}
		}
	}

	// postcondition: all nodes with data == entry are removed from the list
	void list::remove_all(const int& entry)
	{
		Node* temp = head;
		if (temp->data == entry)
		{
			if (temp->next == nullptr)
			{
				head = NULL;
				delete temp;
			}
			else
			{
				while (head != NULL && head->data == entry)
				{
					if (head->next != nullptr)
					{
						Node* temp2 = temp;
						head = temp2->next;
						delete temp2;
						temp = head;
					}
					else
					{
						if (temp->data == entry)
						{
							head = NULL;
							delete temp;
						}
					}
				}
			}
		}
	
		else
		{
			while (temp->next->next != nullptr)//check for nullptr
			{
				if (temp->next->data != entry)
				{
					temp = temp->next;
				}
				else//if the data == entry
				{
					Node* temp2 = temp->next;
					temp->next = temp2->next;
					delete temp2;
				}
			}

			if (temp->next->next == nullptr)
			{
				if (temp->next->data == entry)
				{
					Node* temp2 = temp->next;
					temp->next = nullptr;
					delete temp2;
				}
				else
				{
					return;
				}
			}
		}
	}
	// postcondition: an iterator is created pointing to the head of the list
	Iterator list::begin(void)
	{
		Node* tempHead = head;
		Iterator temp = Iterator(tempHead);
		return temp;
	}

	// CONSTANT MEMBER FUNCTIONS
	// postcondition: the size of the list is returned
	int list::size() const
	{
		int count = 0;
		Node* temp = head;
		if (head == NULL)
		{
			return count;
		}
		else
		{
			while (head != NULL)
			{
				if (temp->next != nullptr)
				{
					++count;
					temp = temp->next;
				}
				else
				{
					return count + 1;
				}
			}
		}
		
	}
}