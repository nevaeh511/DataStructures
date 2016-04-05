// Aaron Merrill
// Course: CS 2420 section: 001

#include<string>
#include<cstdlib>
#include"Node.h"
#pragma once

class Table
{
public:
	static const int TABLE_SIZE = 10;

	Table();
	~Table();
	void Clear();
	
	double Retrieve(string key);
	void Insert(int key, string name, double weight);
	double operator[](string key);

private:
	int Hash(int key) const;
	Node* data[TABLE_SIZE];
	void deleteHelper();
};