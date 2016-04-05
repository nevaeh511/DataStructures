// Aaron Merrill
// Course: CS 2420 section: 001

#include<cstdlib>
#include<string>
using namespace std;

#pragma once
struct Node
{
	int key;		//the key value
	string name;
	double data;	//the elements weight
	Node* next;		//pointer to null or next node
	Node()
	{
		key = 0;
		name = "null";
		data = 0.00;
		next = nullptr;
	}
	Node(int k, string n, double d)
	{
		this->key = k;
		this->name = n;
		this->data = d;
		next = nullptr;
	}
};