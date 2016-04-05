// Aaron Merrill
// Course: CS 2420 section: 001

#include"Queue.h"
#include"Stack.h"
#include"Sequence.h"
#include<string>
using namespace main_savitch_7A;
using namespace main_savitch_3;
using namespace std;
#pragma once


class myGraph
{
public:
	//constant members
	static const int MAX = 20;
	//constructors
	myGraph();
	//~myGraph();
	//modifying functions
	void addVertex(const int label);
	void addEdge(int source, int target);
	//non modifying functions
	sequence neighbors(int vertex) const;
	bool isEdge(int source, int target) const;
	void breadthFirstSearch(const int start) const;	//i think this will take a function as an arguement
	void depthFirstSearch(const int start) const;	//i think this will take a function as an arguement
	void print(int vertex) const;
	int size() const;
	
private:
	//two dimension array
	int edges[MAX][MAX];
	//array to store the vertices
	int vertices[MAX];
	int numOfVertices;

	//Helper functions
	void fill(bool marked[]) const;
	template<class Item>
	void processVertex(int vertex, bool marked[], Item& item) const;
	//int searchNeighbors(sequence& neighbors, bool marked[]) const;
};