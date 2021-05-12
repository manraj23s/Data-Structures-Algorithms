#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstring>
#include "Text.h"
using namespace std;

//--------------------------------------------------------------------
///Preconditions: The sequence must be a char with a numerical value over 0, 
///and the operator must not fail to allocate the requested storage space.
///Postconditions: The created string will be copied from the charseq, based on the memory allocated buffer.
///Input: Checks the bufferSize first for buffer creation's memory allocation ability.
///Output: A copied string is created from a char sequence memory allocator.
Text::Text(const char* charSeq)
{
	bufferSize = strlen(charSeq) + 1; //accounts for null value 
	try {
		buffer = new char[bufferSize];	//try checks the buffer's assignment to bufferSize memory allocator
	}
	catch (bad_alloc & e) { //catch throws exception if operator fails to allocate memory for buffer.
		cerr << "Text::Text(const char): bad_alloc: buffer == 0\n";
		throw bad_alloc();
	}

	strcpy(buffer, charSeq); //string copier
}

//--------------------------------------------------------------------
///Preconditions: Array operator must not fail to allocate requested storage space to allow string to be copied.
///Postconditions: Copy constructor, creates a copy of valueText after memory allocated. 
///Called whenever: 1) a string is passed to a function using call by value,
///2) a function returns a string, or 3) a string is initialized using another string.
///Input: Starts with the bufferSize, and assigns it buffer object's memory allocation. 
///Output: A copied constructor and valueText.
Text::Text(const Text& valueText)
{
	bufferSize = valueText.bufferSize;  //bufferSize is equated to valueText's bufferSize
	buffer = new char[bufferSize];  //buffer is given memory allocation of a bufferSize of char
	strcpy(buffer, valueText.buffer); //string is copied of valueText buffer's memory allocation.
}

//--------------------------------------------------------------------
///Preconditions: If the length will not fit in the buffer, a new buffer array operator is created to assign to buffer.
///Postconditions: Assigns other to a text object and copies string from other.
///Input: Input is integer length of bufferSize, which is needed to check for memory allocation validation.
///Output: A copied string from the verified buffer with length.
void Text::operator = (const Text& other)
{
	int len = other.bufferSize; //length is equal to the bufferSize of other object.
	if (len > bufferSize)  //validates that length is less than bufferSize. If not, deletes buffer's memory and assigns it to other's bufferSize.
	{
		delete[] buffer;
		bufferSize = other.bufferSize;
		buffer = new char[bufferSize];
	}
	strcpy(buffer, other.buffer);
}

//--------------------------------------------------------------------
///Preconditions: Destructor must be given memory to be able to free from the Text object buffer.
///Postconditions: The buffer Text object has its memory freed.
///Input: No input, just a buffer array object that had memory allocated will be passed through.
///Output: A deleted memory allocation for buffer object, so it can be reassigned bufferSize.
Text::~Text()
{
	delete[] buffer; //delete memory allocation of buffer.
}

//--------------------------------------------------------------------
///Preconditions: The string length must be greater than or equal to 0, and not NULL.
///Postconditions: The number of characters in the buffer object are returned.
///Input: Buffer text object gets passed through.
///Output: Returns the number of characters in the Text object buffer besides NULL.
int Text::getLength() const
{
	return strlen(buffer); //return length of buffer
}

//--------------------------------------------------------------------
///Preconditions: Requested number for index must be greater than or equal to 0, and must be less than the length of the buffer's string.
///Postconditions: The index of the buffer object character will be returned as requested.
///Input: From the allocated buffer object, input an integer that is 0 or greater, and less than the length of the string object.
///Output: Returns the nth character in Text object, where the characters are numbered by index.
char Text::operator [] (int n) const
{
	// check if n is out of range of the buffer object's stored memory.
	if (n >= 0 && n < getLength()) {
		return buffer[n];
	}
	return 0;
}

//--------------------------------------------------------------------
///Preconditions: Buffer must have valid data stored to be able to clear.
///Postconditions: The buffer's contents are cleared, but the size remains the same.
///Input: buffer array object is the input.
///Output: Text object buffer is cleared and emptied, but size unchanged.
void Text::clear()
{
	buffer[0] = '\0'; //buffer object cleared by being equal to null termination character, marking end of string.
}

//--------------------------------------------------------------------
///Preconditions: The buffer must have valid memory allocated to be able to analyze.
///Postconditions: The object's contents are displayed, with an index value given to each split character.
///Input: The buffer object array with stored and allocated memory is the input.
///Output: Outputs the characters in a string.This is done to debug and validate the operations.
void Text::showStructure() const
{
	int j; // Loop counter
	for (j = 0; buffer[j] != '\0'; j++) //for every index of the for loop, output the index and the character associated
		cout << buffer[j];
	cout << endl;
}

