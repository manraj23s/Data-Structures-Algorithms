//--------------------------------------------------------------------
//
//  Laboratory 9, In-lab Exercise 2                     test9.cpp
//  Version #: 1
//  Date Originally Written: 02/10/2021
//  Date Last Modified: 02/28/2021
//  Authors: Manraj Singh  (Development & Documentation) 
//           Corey Shimshock (Development & Documentation)
//  Purpose: Test program for the operations in the Binary Search Tree ADT.
//           Collaborates with BSTree to create a binary tree from user input
//           and modify it to the user's desires.
//
//--------------------------------------------------------------------

#include <iostream>
#include "config.h"
#include "BSTree.cpp"
using namespace std;

void print_help();

//BST data item class declaration
class TestData
{
public:
    void setKey(int keyNew)           // Set the key
    {
        keyDataField = keyNew;
    }   
    int getKey() const
    {
        return keyDataField;         // Returns the key
    }                                
private:
    int keyDataField;                // Key for the data item
};

int main()
{
    BSTree<TestData, int> testTree;  // Test BST
    TestData dataForTest;            // BST data item
    int keyforInput;                 // User input, known as key
    char command;                    // Command input

    print_help();
    do
    {
        testTree.showStructure();                     // Output tree

        cout << endl << "Command: ";                  // Read command
        cin >> command;
        if (command == '+' || command == '?' ||
            command == '-' || command == '<')
        {
            cout << "Enter a desired integer: ";
            cin >> keyforInput;
        }
        switch (command)
        {
        case 'P': case 'p':
            print_help();
            break;

        case '+':                                  // Insert key
            dataForTest.setKey(keyforInput);
            cout << "Insert: key = " << dataForTest.getKey() << endl;
            testTree.insert(dataForTest);
            break;
            
        case '?':                                  // Retrieve key
            if (testTree.retrieve(keyforInput, dataForTest))
                cout << "Retrieved: getKey = "
                << dataForTest.getKey() << endl;
            else
                cout << "Not found!" << endl;
            break;

        case '-':                                  // Remove key
            if (testTree.remove(keyforInput))
                cout << "Removed data item!" << endl;
            else
                cout << "Not found!" << endl;
            break;

        case 'K': case 'k':                       // Write keys
            cout << "Keys: " << endl;
            testTree.writeKeys();
            break;

        case 'C': case 'c':                       // Clear tree
            cout << "Clear the tree..." << endl;
            testTree.clear();
            break;

        case 'E': case 'e':                       // Check for empty tree
            if (testTree.isEmpty())
                cout << "Tree is empty!" << endl;
            else
                cout << "Tree is NOT empty!" << endl;
            break;

#if   LAB9_TEST1
        case 'G': case 'g':                   // Programming Exercise 2
            cout << "Tree nodes count: " << testTree.getCount() << endl;
            break;
#endif	// LAB9_TEST1

#if   LAB9_TEST2
        case 'H': case 'h':                   // Programming Exercise 2
            cout << "Tree height = " << testTree.getHeight() << endl;
            break;
#endif	// LAB9_TEST2

//#if   LAB9_TEST3
//        case '<':                              // Programming Exercise 3
//            cout << "Keys < " << inputKey << " : " << endl;
//            testTree.writeLessThan(inputKey);
//            cout << endl;
//            break;
//#endif	// LAB9_TEST3 


        case 'Q': case 'q':                    // Quit test prog
            break;

        default:                               // Invalid command
            cout << "Inactive or invalid command! 'P' prints help." << endl;
        }
    } while (cin && (command != 'Q') && (command != 'q'));

    if (!cin) {
        cerr << "Error in console input! Exiting." << endl;
    }
    return 0;
}

//--------------------------------------------------------------------
//outputs menu to allow user to understand what to input.
void print_help() {
    cout << endl << "Commands:" << endl;
    cout << endl << "Commands:" << endl;
    cout << "  P    : [P]rint Help (displays this message)" << endl;
    cout << "  +key : Insert (or update) data item (use integers)" << endl;
    cout << "  ?key : Retrieve data item" << endl;
    cout << "  -key : Remove data item" << endl;
    cout << "  K    : Write keys in ascending order" << endl;
    cout << "  C    : Clear the tree" << endl;
    cout << "  E    : Empty tree?" << endl;
    cout << "  G    : Get count of nodes          "
#if LAB9_TEST1
        << "(Active   : "
#else
        << "(Inactive : "
#endif
        << "In-lab Exercise 2)" << endl;

    cout << "  H    : Height                      "
#if LAB9_TEST2
        << "(Active   : "
#else
        << "(Inactive : "
#endif
        << "In-lab Exercise 2)" << endl;
    
//    cout << "  <key : Write keys that are < key   "

//#if LAB9_TEST3
//        << "(Active   : "
//#else
//        << "(Inactive : "
//#endif
//       << "In-lab Exercise 3)" << endl; 
    cout << "  Q    : Quit the test program" << endl;
    cout << endl;
}
