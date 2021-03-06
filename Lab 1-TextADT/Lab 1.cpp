//--------------------------------------------------------------------
//
// Laboratory 1 test1.cpp
//
// Description: Test program for the operations in the Text ADT
//
// Version #
// Date originally written: 01/12/2021
// Date last modified: 02/08/2021
// Author?s Name: Manraj Singh & Corey Shimshock
//
//--------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <string>
#include "Text.h"



//--------------------------------------------------------------------
// Function prototype
void copyTester(Text copyText); // copyText is passed by value
void print_help();

//--------------------------------------------------------------------
int main()
{
   Text a("a"), // Predefined test text objects
		alp("alp"),
		alpha("alpha"),
		epsilon("epsilon"),
		empty,
		assignText, // Destination for assignment
		inputText; // Input text object
		int n; // Input subscript
		char ch, // Character specified by subscript
		selection; // Input test selection

		// Get user test selection.
	print_help();

	cout << "\nPlease enter a selection: ";

	// Execute the selected test.
	cin >> selection;

	cout << endl;
	switch (selection)
	{
	case '1':
		// Test 1 : Tests the constructors.
		cout << "Structure of various text objects: " << endl;
		cout << "text object: alpha" << endl;
		alpha.showStructure();
		cout << "text object: epsilon" << endl;
		epsilon.showStructure();
		cout << "text object: a" << endl;
		a.showStructure();
		cout << "empty text object" << endl;
		empty.showStructure();
		break;
	case '2':
		// Test 2 : Tests the length operation.
		cout << "Lengths of various text object:" << endl;
		cout << " alpha   : " << alpha.getLength() << endl;
		cout << " epsilon : " << epsilon.getLength() << endl;
		cout << " a       : " << a.getLength() << endl;
		cout << " empty   : " << empty.getLength() << endl;
		break;

	case '3':
		// Test 3 : Tests the subscript operation.
		cout << "Enter a subscript : ";
		cin >> n;
		ch = alpha[n];
		cout << " alpha[" << n << "] : ";
		if (ch == '\0')
			cout << "\\0" << endl;
		else
			cout << ch << endl;
		break;

	case '4':
		// Test 4 : Tests the assignment and clear operations.
		cout << "Assignments:" << endl;
		cout << "assignText = alpha" << endl;
		assignText = alpha;
		assignText.showStructure();

		cout << "assignText = a" << endl;
		assignText = a;
		assignText.showStructure();

		cout << "assignText = empty" << endl;
		assignText = empty;
		assignText.showStructure();

		cout << "assignText = epsilon" << endl;
		assignText = epsilon;
		assignText.showStructure();

		cout << "assignText = assignText" << endl;
		assignText = assignText;
		assignText.showStructure();

		cout << "assignText = alpha" << endl;
		assignText = alpha;
		assignText.showStructure();

		cout << "Clear assignText" << endl;
		assignText.clear();
		assignText.showStructure();

		cout << "Confirm that alpha has not been cleared" << endl;
		alpha.showStructure();
		break;

	case '5':
		// Test 5 : Tests the copy constructor and operator= operations.

		cout << "Calls by value:" << endl;
		cout << "alpha before call: " << endl;
		alpha.showStructure();

		copyTester(alpha);
		cout << "alpha after call: " << endl;
		alpha.showStructure();

		cout << "a before call: " << endl;
		a.showStructure();

		a = epsilon;
		cout << "a after call: " << endl;
		a.showStructure();

		cout << "epsilon after call: " << endl;
		epsilon.showStructure();
		break;
	}
	system("pause");
	return 0;
}

//--------------------------------------------------------------------
void copyTester(Text copyText)
// Dummy routine that is passed a text object using call by value. Outputs
// copyText and clears it.
{
	cout << "Copy of text object: " << endl;
	copyText.showStructure();
	cout << "Clear copy..." << endl;
	copyText.clear();
	copyText.showStructure();
}

//--------------------------------------------------------------------
void print_help()
{
	cout << endl << "Tests:" << endl;
	cout << " 1: Tests the constructors" << endl;
	cout << " 2: Tests the length operation" << endl;
	cout << " 3: Tests the subscript operation" << endl;
	cout << " 4: Tests the assignment and clear operations" << endl;
	cout << " 5: Tests the copy constructor and operator= operations" << endl;
}
