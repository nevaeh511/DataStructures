// Aaron Merrill
// Course: CS 2420 section: 001
// I Aaron Merrill have not used any code other than my own (or that in the textbook) for this project.
// I also have not used any function or data-structure from the Standard-Template Library. 
// I understand that any violation of this disclaimer will result in a 0 for the project.

#include "List.h"
#include "Node.h"
#include <cstdlib>
using namespace std;

namespace list_2
{
	Node::Node(int d)
	{
		data = d;
		next = nullptr;
	}
}//end namespace