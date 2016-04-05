// Aaron Merrill
// Course: CS 2420 section: 001

#include<iostream>
#include<cassert>
#include"Graph.h"
using namespace std;

myGraph::myGraph()
{
	numOfVertices = 0;
	edges[MAX][MAX];
	vertices[MAX];
}

sequence myGraph::neighbors(int vertex) const
{
	sequence answer;
	assert(vertex < size());

	for (int i = 0; i < size(); i++)
	{
		if (edges[vertex][i])
		{
			answer.insert(i);
		}
	}
	return answer;
}

void myGraph::addEdge(int source, int target)
{
	assert(source < size());
	assert(target < size());
	edges[source][target] = true;
}

void myGraph::addVertex(const int label)
{
	int newVertexNum;
	int otherVertexNum;
	assert(size() < MAX);
	//let added vertex number be set to the number of vertices
	//increment the last vertex number by one
	newVertexNum = numOfVertices;
	++numOfVertices;
	//make all edges from other vertices to new vertex false
	//make all edges from new vertex to other vertices false
	for (otherVertexNum = 0; otherVertexNum < numOfVertices; otherVertexNum++)
	{
		edges[otherVertexNum][newVertexNum] = false;
		edges[newVertexNum][otherVertexNum] = false;
	}
	//add new vertex to array to store in
	vertices[newVertexNum] = label;
}

bool myGraph::isEdge(int source, int target) const
{
	assert(source < size());
	assert(target < size());
	return (edges[source][target]);
}

int myGraph::size() const
{
	return numOfVertices;
}

//helper functions for depth & breath first search
void myGraph::fill(bool marked[]) const
{
	for (int i = 0; i < size(); i++)
	{
		marked[i] = false;
	}
}
template<class Item>
void myGraph::processVertex(int vertex, bool marked[], Item& myStructure) const
{
	marked[vertex] = true;	//add vertex to marked array
	myStructure.push(vertex);	//add vertex to stack
	cout << "V" << vertex << " ";	//print out vertex to console
}

void myGraph::depthFirstSearch(const int start) const
{
	int vertex = start;
	stack<int> myStack;
	//is start vertex number valid
	assert(vertex < size());
	//local array for marked vertices
	bool marked[MAX];
	//set components of marked array to false
	fill(marked);
	//loop while there are still unmarked neighbors of vertex
	do
	{
		//process one incoming vertex
		processVertex(vertex, marked, myStack);
		do
		{
			if (marked[vertex])
			{
				sequence connectors = neighbors(vertex);
				// this looks for any unmarked neighbors in the set neighbors
				connectors.start();
				int used = connectors.size();
				int neighbor = -1;
				do	//loop until an unmarked neighbor is found and is valid item in set
				{
					if (used != 0)	//only if vertex has any neighbors
					{
						neighbor = connectors.current();
						if (!marked[neighbor] && connectors.is_item())	//neighbor is unmarked and a valid item in the set
						{
							vertex = neighbor;
						}
						else if (connectors.is_item())	//neighbor is marked and valid item in set
						{
							connectors.advance();		//go to next neighbor in the set
						}
					}
					//cout << "this is the mark" << endl;
				} while (marked[neighbor] && connectors.is_item());

				if (marked[vertex] || used == 0)
				{
					myStack.pop();
					if (!myStack.empty())
					{
						int previousV = myStack.top();
						vertex = previousV;
					}
				}
			}
		} while (marked[vertex] && !myStack.empty());
	} while (!marked[vertex]);
}
void myGraph::breadthFirstSearch(const int start) const
{
	int vertex = start;
	queue<int> myQueue;
	//is start vertex number valid
	assert(vertex < size());
	//local array for marked vertices
	bool marked[MAX];
	//set components of marked array to false
	fill(marked);
	int neighbor = -1;
	//loop while there are still unmarked neighbors of vertex
	processVertex(vertex, marked, myQueue);
	do
	{
		sequence connectors = neighbors(myQueue.top());
		connectors.start();
		myQueue.pop();
		int used = connectors.size();
		do	//loop and process all neighbor vertices
		{
			if (used != 0)	//only if vertex has any neighbors
			{
				neighbor = connectors.current();
				if (!marked[neighbor] && connectors.is_item())	//neighbor is unmarked and a valid item in the set
				{
					processVertex(neighbor, marked, myQueue);
					connectors.advance();
				}
				else
				{
					connectors.advance();
				}
			}
		} while (connectors.is_item());

	} while (!myQueue.empty());
}