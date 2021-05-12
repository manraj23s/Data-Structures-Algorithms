#include <fstream>
#include <string>
#include <iostream>
#include "Text.h"
using namespace std;

///Preconditions: The text .dat file must be readable from istream. 
///Postconditions: The individual delimited strings (tokens) are extracted and outputted as a count from ostream.
///Input: progsamp.dat text file is opened and read
///Output: The tokens are outputted one-by-one in a line and counted.
int main() {
	//set counter to start at 1
	int counter = 1;

	//text token to read each delimited string
	Text token;
	
	//open text file
	ifstream progFile;
	progFile.open("progsampdat.txt");
	
	//if statement to validate if file is open
	if (progFile.is_open()) {

		while (!progFile.eof()) {
			//takes in tokens
			progFile >> token;
			//if the file does not end, continue extracting tokens
			if (progFile.eof()) break;
			//counter counts each token and increments
			cout << counter << ": [" << token << "]" << endl;
			counter += 1;
		}
		//close text file
		progFile.close();
	}
	//if file not opened, then throw error message
	else {
		cout << "Error: Couldn't read 'progsamp dat.txt'" << endl;

	}
}
