//
// Programmer: Aslihan Celik
// 
// addressBookType.h :
// Manages an address book with personal information, storing up to 500 entries
// of extPersonType objects. Provides functionality to add, search, sort, and
// print entries. Can initialize entries from a file and sort them by last name.
//
// Key Features:
// - Add entries.
// - Search by last name, birth month, or relationship.
// - Print all entries.
// - Sort entries alphabetically by last name.


#pragma once
#include "extPersonType.h"
#include <iostream>
#include <fstream>
#include <string>
#include "orderedLinkedList.h"

using namespace std;

class addressBookType : public orderedLinkedList<extPersonType>
{
	
private:
	/*
	extPersonType addressList[500];  // Array to hold the entries
	int length;                      // Current number of entries
	int maxLength = 500;             // Maximum allowed entries     
	*/

	nodeType<extPersonType>* first;  // Pointer to the first node
	nodeType<extPersonType>* last;   // Pointer to the last node
	int count;                       // Number of nodes in the list

public:

	// Constructor to initialize the address book
	addressBookType();

	// reads the address book data from a file, creates an extPersonType 
	// object from this data, and calls the addEntry() function to add it 
	// to the addressList.
	void initEntry(string dataFile);

	// Modifier function
	// function to add data to the addressList
	// verifies that there is still room in the array and prevents additions 
	// if the array is full,stores the extPersonType object in the array 
	// and increments the length variable.
	void addEntry(extPersonType dataEntry);

	//Accessor Functions

	// function takes the last name of a person as an input and prints the 
	// entry for that person if found in the addressList array.
	void findPerson(string last_name);

	//takes a month number as input and prints the names of all the 
	//persons in the addressList array who have birthdays in that month.
	void findBirthdays(int month);

	//takes a relationship string and prints the names of all the entries that 
	// are tagged with that relationship.
	void findRelations(string _relationship);


	// prints all the entries in the addressList by iterating through the list 
	// and call the print function of each extPersonType object.  
	void print();

	// Sorting function
    // sort the list using lastName field as the sort key so that the list will 
    // be printed in alphabetical order by last name.
	void sortEntries();
};

