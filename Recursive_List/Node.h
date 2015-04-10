// Aaron Merrill
// Course: CS 2420 section: 001
// I Aaron Merrill have not used any code other than my own (or that in the textbook) for this project.
// I also have not used any function or data-structure from the Standard-Template Library. 
// I understand that any violation of this disclaimer will result in a 0 for the project.



#pragma once

namespace list_2
{
	struct Node
	{
		int data;
		Node* next;

		//Postcondition: Node data is initialized
		Node(int d);
	};
}