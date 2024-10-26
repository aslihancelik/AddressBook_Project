//
// Programmer: Aslihan Celik
// 
// addressBookType.h :
// Manages an address book with personal information, storing 
// extPersonType objects. Provides functionality to add, search, sort, and
// print entries. Can initialize entries from a file and sort them by "last name first name".
//
// Key Features:
// - Add entries.
// - Search by last name, birth month, or relationship.
// - Print all entries.
// - Sort entries alphabetically by "last name first name".


#pragma once
#include "extPersonType.h"
#include <iostream>
#include <fstream>
#include <string>
#include "orderedLinkedList.h"

using namespace std;

class addressBookType : public orderedLinkedList<extPersonType>
{

public:

	//orderedLinkedList<extPersonType> addressList;

	// Constructor to initialize the address book
	addressBookType();

	// reads the address book data from a file, creates an extPersonType 
	// object from this data, and calls the addEntry() function to add it 
	// to the addressList.
	void initEntry(string dataFile);

	// Modifier function
	// function to add data to the addressList by calling insert from
	// orderedLinkedList class
	
	void addEntry(extPersonType dataEntry);

	//Add entry provided from the user

	void addEntryUser();

	//Delete an enty based on the full name (last and first)

	void deleteEntry(string first_name, string last_name);

	//Accessor Functions

	// function takes the first and last name of a person as an input and prints the 
	// entry for that person if found in the linkedlist.
	void findPerson(string first_name, string last_name);

	//takes a month number as input and prints the names of all the 
	//persons in the linked list who have birthdays in that month.
	void findBirthdays(int month);

	//takes a relationship string and prints the names of all the entries that 
	// are tagged with that relationship.
	void findRelations(string _relationship);


	// prints all the entries in the addressList by iterating through the list 
	// and call the print function of each extPersonType object.  
	void print();

	//saves the new dat ato the file

	void saveToFile(string filename);

};

