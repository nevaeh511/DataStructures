// Aaron Merrill
// Course: CS 2420 section: 001
// I Aaron Merrill have not used any code other than my own (or that in the textbook) for this project.
// I also have not used any function or data-structure from the Standard-Template Library. 
// I understand that any violation of this disclaimer will result in a 0 for the project.

#include"AVL_BST.h"
#include<iostream>
#include<cstdlib>
using namespace std;


void print_menu();
int insertValue();

int main()
{
	AVL_BST avl = AVL_BST();
	char choice;
	int value;

	do
	{
		print_menu();
		cout << "Enter choice: ";
		cin >> choice;
		choice = toupper(choice);
		cout << "\n";

		switch (choice)
		{
		case 'I': avl.Insert(insertValue());
			break;
		case 'P': avl.Print();
			break;
		case 'Q': cout << "See Ya Later!" << "\n" << endl;
			break;
		default: cout << "That is not a valid choice!" << "\n" << endl;
			break;
		}
	} while (choice != 'Q');

	system("PAUSE");
	EXIT_SUCCESS;
}

void print_menu()
// Library facilities used: iostream.h
{
	cout << endl; // Print blank line before the menu
	cout << "The following choices are available: " << endl;
	cout << " I   To Insert" << endl;
	cout << " P   Print indented tree" << endl;
	cout << " Q   Quit this test program" << endl;
}

int insertValue()
{
	int value;
	cout << "Insert value: ";
	cin >> value;
	return value;
}