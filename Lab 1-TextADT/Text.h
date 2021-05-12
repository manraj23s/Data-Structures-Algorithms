#pragma once
//--------------------------------------------------------------------
//
// Laboratory 1 Text.h
// Class declaration for the array implementation of the Text ADT
//
//--------------------------------------------------------------------
#include <stdexcept>
#include <iostream>
using namespace std;

///Preconditions: Function templates must be without error, and be referenced in the .cpp file.
///Postconditions: The functions are utilized in text.cpp to perform operations with the Text objects.
///Input: No input
///Output: The functions must output their desired criteria as mentioned below in the comments
class Text
{
public:
	//Constructors and operator=
	Text(const char* charSeq = ""); //Initialize using char*
	Text(const Text& other); //Copies constructor
	void operator = (const Text& other); //operator assignment

	//Destructor
	~Text();

	//Text operations
	int getLength() const; //gives number of characters
	char operator[] (int n) const; //Subscript
	void clear(); // Clear string

	// Output the string structure -- used in testing/debugging
	void showStructure() const;

private:
	// Data members
	int bufferSize; // Size of the string buffer
	char* buffer; // Text buffer containing a null-terminated sequence of characters

	// Friends
	// Text input/output operations (In-lab Exercise 1)
	friend istream& operator >> (istream& input, Text& inputText);
	friend ostream& operator << (ostream& output, const Text& outputText);
};