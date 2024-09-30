#pragma once
#include "extPersonType.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class addressBookType
{
private:

	extPersonType addressList[500];  // Array to hold the entries
	int length;                      // Current number of entries
	int maxLength = 500;                   // Maximum allowed entries        /////add max length value

public:

	//NO CONSTRUCTOR?
	// Constructor to initialize the address book
	addressBookType();

	// reads the address book data from a file, creates an extPersonType 
	// object from this data, and calls the addEntry() function to add it 
	// to the addressList.
	void initEntry(string data);

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

