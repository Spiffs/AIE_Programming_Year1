#include <iostream>
#include <windows.h>
#include "Stack.h"

// std statements
using std::cout;
using std::endl;
using std::cin;

// values
Stack _stack;

// menu value
int menuselection = 0;
bool run = true;

// menu function
void menu()
{
	// while run loop
	while (run)
	{
		system("cls");

		cout << "MENU: " << endl
			<< "    1. Size" << endl
			<< "    2. Push" << endl
			<< "    3. Pop" << endl
			<< "    4. Top" << endl
			<< "    5. Exit" << endl;

		// menu input
		cin >> menuselection;

		// cin fail check
		if (cin.fail())
		{
			cout << "Please enter a menu item :)" << endl;
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			cin.get();
			menu();
		}

		system("cls");

		// menu selection processor
		switch (menuselection) {
		case 1:
		{

			cout << "The size of the stack is: " << _stack.size();
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			cin.get();
			menu();
		}

		case 2:
		{
			int newvalue;
			cout << "Value you would like to add: ";
			cin >> newvalue;

			if (cin.fail())
			{
				cout << endl << "Please enter a number :)" << endl;
				cin.clear();
				cin.ignore(cin.rdbuf()->in_avail());
				cin.get();
				menu();
			}

			_stack.push(newvalue);
	
			cout << endl << "Successfully added :)" << endl;
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			cin.get();
			menu();
		}

		case 3:
		{
			_stack.pop();
			cout << "The size of the stack has gone to " << _stack.size() << endl;
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			cin.get();
			menu();
		}

		case 4:
		{
			cout << "The top value of the stack is " << _stack.top() << endl;
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			cin.get();
			menu();
		}

		case 5:
		{
			run = false;
			break;
		}

		}
	}
}

// main function
int main()
{
	menu();

	return 0;
}

