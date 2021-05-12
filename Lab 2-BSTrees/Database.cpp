//--------------------------------------------------------------------
//
//  Laboratory 9, In-lab Exercise 1                     database.cpp
//  Version #: 1
//  Date Originally Written: 02/10/2021
//  Date Last Modified: 02/28/2021
//  Authors: Manraj Singh  (Development & Documentation) 
//           Corey Shimshock (Development & Documentation)
//  Indexed accounts database program - reads a .dat file of bank accounts
//  with lists of information and allows user to search for existing bank accounts
//  and outputs information for valid accounts.
//
//--------------------------------------------------------------------

// Builds aBST index for the account records in the
// text file accounts.dat.
/*
#include <iostream>
#include <fstream>
#include "BSTree.cpp"
using namespace std;

//--------------------------------------------------------------------
// Declarations specifying the accounts database
//

const int lengthOfName = 11;     // Maximum number of characters in name
const long recordedBytes = 37;   // Number of bytes used to store records in .dat

struct AccountRecord
{
	int accountID;                     // Account identifier
	char firstName[lengthOfName],   // Name of account holder
		lastName[lengthOfName];
	double balanceAccount;          // Account balance
};

//--------------------------------------------------------------------
// Declaration specifying the database index
//

struct IndexEntry
{
	int accountID;              // (Key) Account ID
	long recordNumber;          // Record number

	int getKey() const
	{
		return accountID;
	}   // Return key field
};

//--------------------------------------------------------------------
void main()
{
    ifstream acctFile("accounts.dat");   // Accounts database file
    AccountRecord acctRec;               // Account record
    BSTree<IndexEntry, int> index;       // Database index
    IndexEntry entry;                    // Index entry
    int userInputID;                        // User input account ID
    long recNum = 0;                     // Record number
    string temporary;                    // Temporary placeholder name

    // Iterate through the database records. For each record, read the
    // account ID and add the (account ID, record number) pair to the
    // index.
    acctFile >> entry.accountID;
    while (acctFile.good())
    {
        //go through record numbers and ID
        acctFile >> temporary >> temporary >> temporary;
        entry.recordNumber = recNum;
        recNum++;
        index.insert(entry);
        acctFile >> entry.accountID;
    }

    // Output the account IDs in ascending order.
    cout << endl << "Account IDs: " << endl;
    index.writeKeys();

    // Clear the status flags for the database file.
    acctFile.clear();
    acctFile.close();
    acctFile.open("accounts.dat");

    // Read an account ID from the keyboard and output the
    // corresponding record.
    cout << endl << "Enter account ID: ";
    //while the user inputs account numbers, continue looping
    while (cin >> userInputID)
    {
        if (index.retrieve(userInputID, entry))
        {
            for (int i = 0; i <= entry.recordNumber; i++)
            {
                acctFile >> acctRec.accountID;
                acctFile >> acctRec.firstName >> acctRec.lastName;
                acctFile >> acctRec.balanceAccount;
            }
            //output record number
            cout << "Record #: " << entry.recordNumber << endl;
            //output account ID
            cout << "Account ID: " << acctRec.accountID << endl;
            //output name
            cout << "Name: " << acctRec.firstName << " ";
            cout << acctRec.lastName << " " << endl;
            //output account balance
            cout << "Account Balance: $" << acctRec.balanceAccount << endl;
        }
        //if wrong ID, tell user
        else
            cout << "No record with given account ID!";

        //renew loop to enter ID or quit with file
        acctFile.clear();
        acctFile.close();
        acctFile.open("accounts.dat");
        cout << endl << "Enter account ID (EOF to quit): ";
    }

}
*/