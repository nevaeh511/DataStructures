// FILE: sequence_test.cxx
// An interactive test program for the new sequence class
#include <cctype>       // Provides toupper
#include <iostream>     // Provides cout and cin
#include <cstdlib>      // Provides EXIT_SUCCESS
#include "list.h"  // With value_type defined as int
#include "Iterator.h"
using namespace std;
using namespace list_1;

// PROTOTYPES for functions used by this test program:
void print_menu();
// Postcondition: A menu of choices for this program has been written to cout.

char get_user_command();
// Postcondition: The user has been prompted to enter a one character command.
// The next character has been read (skipping blanks and newline characters), 
// and this character has been returned.

void show_list(list& display);
// Postcondition: The items on display have been printed to cout (one per line).

int get_number();
// Postcondition: The user has been prompted to enter a real number. The
// number has been read, echoed to the screen, and returned by the function.

void print_iterator_menu();

//template <typename T>
void test_iterator(list& L)
{
	Iterator I = L.begin();

	char choice;

	do
	{
		print_iterator_menu();
		choice = toupper(get_user_command());
		switch (choice)
		{


		case '*':if (I.is_item())
			cout << "The current item is: " << *I << endl;
				 else
					 cout << "There is no current item." << endl;
			break;
		case '+': ++I;
			break;
		case '?': if (I.is_item())
			cout << "There is an item." << endl;
				  else
					  cout << "There is no current item." << endl;
			break;
		case 'Q': cout << "End test iterator" << endl;
			break;

		default:  cout << choice << " is invalid." << endl;
			break;
		}

	} while (choice != 'Q');
}

void print_iterator_menu()
// Library facilities used: iostream.h
{
	cout << endl; // Print blank line before the menu
	cout << "Iterator menu" << endl;
	cout << "The following choices are available: " << endl;
	cout << " +   Activate the ++ operator" << endl;
	cout << " ?   Print the result from the is_item( ) function" << endl;
	cout << " *   Print the result * operator" << endl;
	cout << " Q   Quit the iterator test menu" << endl;
}


int main()
{
	list test; // A sequence that we’ll perform tests on
	char choice;   // A command character entered by the user

	cout << "I have initialized an empty sequence of real numbers." << endl;

	do
	{
		print_menu();
		choice = toupper(get_user_command());
		switch (choice)
		{

			//  case 'P': show_sequence(test);
			//          break;
		case 'S': cout << "Size is " << test.size() << '.' << endl;
			break;
		case 'I': test.insert_front(get_number());
			break;
		case 'A': test.add_back(get_number());
			break;
		case 'R': test.remove_all(get_number());
			break;
		case 'T': test_iterator(test);
			break;
		case 'P': show_list(test);
			break;
		case 'Q': cout << "Ridicule is the best test of truth." << endl;
			break;
		default:  cout << choice << " is invalid." << endl;
		}
	} while ((choice != 'Q'));

	return EXIT_SUCCESS;
}

void print_menu()
// Library facilities used: iostream.h
{
	cout << endl; // Print blank line before the menu
	cout << "The following choices are available: " << endl;
	cout << " P   Print a copy of the entire sequence" << endl;
	cout << " S   Print the result from the size( ) function" << endl;
	cout << " I   Insert a new number with the insert_front(...)" << endl;
	cout << " A   Add a new number with the add_back(...) function" << endl;
	cout << " R   Activate the remove_all(...) function" << endl;
	cout << " T   Switch to test iterator menu" << endl;
	cout << " Q   Quit this test program" << endl;
}

char get_user_command()
// Library facilities used: iostream
{
	char command;

	cout << "Enter choice: ";
	cin >> command; // Input of characters skips blanks and newline character

	return command;
}

void show_list(list& display)
// Library facilities used: iostream
{
	Iterator I = display.begin();
	for (; I.is_item(); ++I)
		cout << *I << endl;
}



int get_number()
// Library facilities used: iostream
{
	int result;

	cout << "Please enter an integer: ";
	cin >> result;
	cout << result << " has been read." << endl;
	return result;
}
