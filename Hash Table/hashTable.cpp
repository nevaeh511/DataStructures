// Aaron Merrill
// Course: CS 2420 section: 001

#include"hashTable.h"
#include<iostream>

Table::Table()
{
	//data = new Node*[TABLE_SIZE];
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		data[i] = nullptr;
	}
}

Table::~Table()
{
	deleteHelper();
}

double Table::operator[](string insertKey)
{
	 
	int key = 0;
	int index = 0;
	//convert to ascii decimal value
	for (int i = 0; i < insertKey.length(); i++)
	{
		key += insertKey[i];
	}
	index = Hash(key);
	Node* curr = data[index];
	
	if (curr != nullptr)
	{
		//if records key matches
		if (curr->name == insertKey)
		{
			//return the records weight
			return curr->data;
		}
		//if records key does not match, search through list
		else
		{
			while (curr->name != insertKey)
			{
				if (curr->next == nullptr)
				{
					cout << "there was an error" << endl;
				}
				curr = curr->next;
			}
			//if the key was found, return the weight data member
			if (curr->name == insertKey)
			{
				return curr->data;
			}
			else
			{
				return -2;
			}
		}
	}
	else
	{
		return -2;
	}
}

void Table::Clear()
{
	deleteHelper();
}

void Table::Insert(int key, string name, double weight)
{
	int index;
	//the key is hashed using the name of the element
	index = Hash(key);

	//first check to see if the entered key already exists
	//if there is already a record with the entered key then return a message
	//saying that the record is already in the table
	

	/*data[index] = new Node(key, name, weight);
	cout << data[index]->name << endl;
	cout << data[index]->data << endl;*/

	//if the spot at index is empty
	if (data[index] == nullptr)
	{
		data[index] = new Node(key, name, weight);
	}
	//if the spot at index is already occupied then add record at the end of the list
	else
	{
		//place record at end of the linked list by
		//looping through the list until a nullptr is found
		Node* lastRecord = data[index];
		while (lastRecord->next != nullptr)
		{
			//go to the next record
			lastRecord = lastRecord->next;
		}
		//when the last record is found, attach the new record to the end
		lastRecord->next = new Node(key, name, weight);
	}	
}


int Table::Hash(int key) const
{
	//int programmersAge = 29;
	return key % TABLE_SIZE;
}

double Table::Retrieve(string nameIsKey)
{
	int key = 0;
	int index = 0;
	//convert to ascii decimal value
	for (int i = 0; i < nameIsKey.length(); i++)
	{
		key += nameIsKey[i];
	}
	//get index
	index = Hash(key);
	Node* curr = data[index];
	//i need to find the matching key and return the weight
	//if at index there is a record
	if (curr != nullptr)
	{
		//if records key matches
		if (curr->name == nameIsKey)
		{
			//return the records weight
			return curr->data;
		}
		//if records key does not match, search through list
		else
		{
			//Node* found = curr;
			while (curr->name != nameIsKey)
			{
				if (curr->next == nullptr)
				{
					cout << "there was an error" << endl;
				}
				curr = curr->next;
			}
			//if the key was found, return the weight data member
			if (curr->name == nameIsKey)
			{
				return curr->data;
			}
			else
			{
				return -2;
			}
		}
	}	
	else
	{
		return -2;
	}
}

void Table::deleteHelper()
{
	//iterate through each index
	//if index is null or has only one record, delete
	//if index has a list of records
	//if records next pointer is not nullptr
	//loop through deleting each record
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		if (data[i] != nullptr)
		{
			while (data[i] != nullptr)
			{
				Node* deleteThis = data[i];
				data[i] = data[i]->next;
				delete deleteThis;
			}
		}
		
		data[i] = nullptr;
	}
}