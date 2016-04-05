
#include "sequence2.h"
#include<cassert>
#include <iostream>
using namespace std;

namespace main_savitch_3
{
	// CONSTRUCTORS and DESTRUCTOR
	sequence::sequence(int initial_capacity)
	{
		data = new value_type[initial_capacity];
		used = 0;
		current_index = -1;
		capacity = initial_capacity;
	}

//	//copy constructor
	sequence::sequence(const sequence& source)
	{
		copy(source);
	}

	sequence::~sequence()
	{
		delete[] data;
	}

	// MODIFICATION MEMBER FUNCTIONS
	void sequence::resize(int new_capacity)
	{
		cout << "resize triggered!" << endl;
		//then create a new capacity for the data array
		//create new array and set its new capacity
		if (new_capacity == capacity)
		{
			return;
		}
		if (new_capacity < used)
		{
			new_capacity = used;
		}
		value_type* tempData;
		tempData = new value_type[new_capacity];

		//loop through the old array then copy all the items to new array
		for (int i = 0; i < used; ++i)
		{
			tempData[i] = data[i];
		}
		delete[] data;
		data = tempData;
		capacity = new_capacity;
	}

	void sequence::start()
	{
		cout << "start triggered" << endl;
		//if there are no items in the sequence keep current_index invalid(no current item)
		if (is_item())
		{
			//remove curren_index
			//make first item the current_intex
			current_index = 0;
		}
		//if there is no current item or if the sequence is empty
		else
		{
			current_index = -1;
		}
		
	}
//     Postcondition: The first item on the sequence becomes the current item
//     (but if the sequence is empty, then there is no current item).


	void sequence:: advance()
	{
		cout << "advance triggered" << endl;

		assert(is_item());
		//if current item is the last item in sequence, then
		//then current item is out of sequence range
		if (current_index == used -1)
		{
			current_index = -1;
		}
		else
		{
			//else move current index to the right
			current_index = current_index + 1;
		}
	}

	void sequence::insert(const value_type& entry)
	{
		cout << "insert triggered" << endl;

		//check if the size of the array is less than the capacity
		//before inserting entry
		if (used == capacity)
		{
			cout << "insert/resize triggered" << endl;
			resize(used * TIMES_TWO);
		}
		
		if (! is_item())
		{
			current_index = 0;
		}

		for (int i = used; i > current_index; --i)
		{
			data[i] = data[i - 1];
		}
		data[current_index] = entry;
		++used;
	}

	void sequence::attach(const value_type& entry)
	{
		cout << "attach triggered" << endl;

		//check if the size is less than the capacity of the sequence
		if (used == capacity)
		{
			resize(capacity * TIMES_TWO);
		}
		//if no current item exists then place the entry at the end of sequence
		//make entry the current item
		if (! is_item())
		{
			current_index = used;
		}
		else
		{
			for (int i = used; i > current_index; --i)
			{
				data[i] = data[i - 1];
			}
			current_index = current_index + 1;
			
		}
		data[current_index] = entry;
		++used;
	}

	void sequence::remove_current()
	{
		cout << "removed triggered" << endl;

		//check is there is valid item in sequence
		//if item is valid current item,  then enter loop
		//if not then throw exception.
		//if current item is equal to the size -1, then set current item to invalid
		//else move to the current item index
		//if index is is less than used 
		//then copy the item that is next to current item (current_index + 1) to current item position (current_index)
		assert(is_item());
		if (current_index == used -1)
		{
			current_index = -1;
		}
		else
		{
			for (int i = current_index; i < used; ++i)
			{
				data[i] = data[i + 1];
			}
		}
		--used;
	}

	void sequence::copy(const sequence& source)
	{
		value_type* tempData = new value_type[source.capacity];

		for (int i = 0; i < source.size(); ++i)
		{
			tempData[i] = source.data[i];
		}
		used = source.used;
		current_index = source.current_index;
		capacity = source.capacity;
		data = tempData;
	}

	void sequence::operator = (const sequence& source)
	{
		cout << "operator triggered" << endl;

		//check if the source object is the same as old object
		if (this == &source)
		{
			return;
		}

		delete[] data;
		copy(source);
	}

	// CONSTANT MEMBER FUNCTIONS
	size_type sequence::size() const
	{
		return used;
	}

	bool sequence::is_item() const
	{
		return(current_index >= 0 && current_index <= used-1);
	}

	value_type sequence::current() const
	{
		assert(is_item());
		return data[current_index];
	}
}