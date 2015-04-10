// Aaron Merrill
// Course: CS 2420 section: 001
// I Aaron Merrill have not used any code other than my own (or that in the textbook) for this project.
// I also have not used any function or data-structure from the Standard-Template Library. 
// I understand that any violation of this disclaimer will result in a 0 for the project.


// CONSTRUCTOR for the stack<Item> template class:
//   stack( )
//     Postcondition: The stack has been initialized as an empty stack.
//
// MODIFICATION MEMBER FUNCTIONS for the stack<Item> class:
//   void push(const Item& entry)
//     Precondition: size( ) < CAPACITY.
//     Postcondition: A new copy of entry has been pushed onto the stack.
//
//   void pop( )
//     Precondition: size( ) > 0.
//     Postcondition: The top item of the stack has been removed.
//
// CONSTANT MEMBER FUNCTIONS for the stack<Item> class:
//   bool empty( ) const
//     Postcondition: Return value is true if the stack is empty.
//
//   size_type size( ) const
//     Postcondition: Return value is the total number of items in the stack.
//
//   Item top( ) const
//     Precondition: size( ) > 0.
//     Postcondition: The return value is the top item of the stack (but the
//     stack is unchanged. This differs slightly from the STL stack (where
//     the top function returns a reference to the item on top of the stack).
//
//  VALUE SEMANTICS for the stack<Item> class:
//     Assignments and the copy constructor may be used with stack<Item> 
//     objects.

#pragma once
#include <cstdlib>
#include<cassert>


namespace main_savitch_7A
{
	template <class Item>
	class stack
	{
	public:
		typedef int size_type;
		typedef Item value_size;
		static const size_type CAPACITY = 30;
		//Constructor
		stack(){ used = 0; }
		void push(const Item& entry);
		void pop();
		Item top() const;
		size_type size()const { return used; }
		bool empty() const{ return (used == 0); }

		//Constant Member Functions
		Item data[CAPACITY];
		size_type used;
	};

	template <class Item>
	const typename stack<Item>::size_type stack<Item>::CAPACITY;

	template <class Item>
	void stack<Item>::push(const Item& entry)
	{
		assert(size() < CAPACITY);
		data[used] = entry;
		++used;
	}

	template <class Item>
	void stack<Item>::pop()
	{
		assert(!empty());
		--used;
	}

	template <class Item>
	Item stack<Item>::top() const
	{
		assert(!empty());
		return data[used - 1];
	}
}