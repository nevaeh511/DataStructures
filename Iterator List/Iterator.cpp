#include"list.h"
#include"Iterator.h"
#include <cstdlib>
using namespace std;

namespace list_1
{
	// Constructor
	Iterator::Iterator(Node *np)
	{
		n = np;
	}
	// precondition: is_item is true
	// post condition n points to the next item in the list
	void Iterator::operator++()
	{
		n = n->next;
	}
	// precondition: 
	// postcondition: returns true if there is a valid item
	bool Iterator::is_item()
	{
		return (n->next != nullptr);
	}
	// precondition: is_item == true
	// postcondition returns data that n is pointing at
	int Iterator::operator* ()
	{
		if (is_item())
		{
			return (n->data);
		}
	}

}