// Aaron Merrill
// Course: CS 2420 section: 001

#include<fstream>
#include<iostream>
#include"Stack.h"
using namespace std;
using namespace main_savitch_7A;

//FUNCTION PROTOTYPES
//post condition: the inserted charactor will be matched with a number,
//							then that number will be returned
int precedence(char c);


int main()
{
	//read in infix notation from a file
	ifstream fileInput;
	fileInput.open("tests.txt");  //

	//test if file opened successfully
	if (fileInput.fail())
	{
		cerr << "Could not open input file." << endl;
		exit(1);
	}

	//1. Initialize a stack of charactors to hold the operation symbols and parentheses.
	stack<char> operation;
	//gets first character in the file

	//read until the end of the file
	do
	{
		fileInput.get();

		if (fileInput && fileInput.peek() != EOF)
		{
			do
			{
				//if next input is left parenthesis
				if (fileInput.peek() == '(')
				{
					//read the left parenthesis and push it onto the stack
					char input = fileInput.get();
					operation.push(input);
				}
				else if (isdigit(fileInput.peek()))//the next input is a number or other operand
				{
					//read the operand and write it to the output
					char input = fileInput.get();
					cout << input;
				}
				//if the next input is one of the operation  symbols)
				else if (fileInput.peek() == '+' || fileInput.peek() == '-' || fileInput.peek() == '*' || fileInput.peek() == '/')
				{
					if (!operation.empty())
					{
						while (!operation.empty() && operation.top() != '(' && precedence(operation.top()) > precedence(fileInput.peek()))//none of these three conditions are true)
						{
							if (!operation.empty())
							{
								//Print the top operation and pop it
								char print = operation.top();
								cout << print;
								operation.pop();
							}
						}
					}
				

					//(1)The stack becomes empty, or
					//(2)The next symbol on the stack is a left parenthesis, or
					//(3)The next symbol on the stack is an operation with lower
					//precedence than the next input symbol

					//Read the next input symbol, and push this symbol onto the stack
					char input = fileInput.get();
					operation.push(input);
				}
				else
				{
					//Read and discard the next input symbol (which should be a right parenthesis).
					if (fileInput.peek() == ')')
					{
						fileInput.ignore();
					}

					//Print the top operation and pop it: keep printing and popping until the next
					//symbol on the stack is a left parenthesis.
					if (!operation.empty())
					{
						while (operation.top() != '(' && !operation.empty())
						{
							if (!operation.empty() && operation.top() != '(')
							{
								cout << operation.top();
								operation.pop();
							}
						}
					}
					
					//Finally, pop the left parenthesis.
					operation.pop();
				}
			} while (fileInput && fileInput.peek() != '\n');  //while(there is more of the expression to read);

			//	Print and pop any remaining operations on the stack.
			
			while (!operation.empty())
			{
				cout << operation.top();
				operation.pop();
			}
			cout << endl;
		}
	} while (fileInput && fileInput.peek() != EOF); 

	//close file
	fileInput.close();
	system("PAUSE");
}

int precedence(char c)
{
	//operator has low precedence
	int low = 0;
	//operator has high precedence
	int high = 1;
	if (c == '-' || c == '+')
	{
		return low;
	}
	else if (c == '*' || c == '/')
	{
		return high;
	}
}
