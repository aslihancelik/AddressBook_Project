//
// Programmer: Aslihan Celik
// 
// addressBookType.h :
// addressBookType Implementation
// This file implements the functions of the addressBookType class, which manages an array of 
// extPersonType objects. It provides functionality for reading entries from a file, adding entries 
// to the address book, sorting them by last name, and searching by last name, birth month, or 
// relationship. It also prints all entries in the address book. This implementation ensures the 
// address book does not exceed the maximum size (500 entries).
//
// Key Features:
// - Initialize address book from a file.
// - Add new entries with boundary checks.
// - Search and filter entries by name, birth month, or relationship.
// - Sort entries alphabetically by last name.
// - Print all stored entries.
//


#include "addressBookType.h"

//constructor??????????
// Constructor to initialize the address book
addressBookType::addressBookType() : length(0) {}

// Initializes entries from a file
void addressBookType::initEntry(string dataFile) {     
    ifstream infile(dataFile);  // Open the file for reading

    // check if the file opened successfully to avoid runtime errors.
    if (!infile) {
        cerr << "Error opening file" << endl;   //////////////////////////////////////
        return; // Exit if the file cannot be opened
    }

    string firstName, lastName, address, city, state, phone, relationship;
    int month, day, year, zipcode;

    while (true) {
        //Reading first and last name
        if (!(infile >> firstName >> lastName))
            break; // End of file or error

        // Read month, day, year
        infile >> month >> day >> year;

        //Read address, city, state, zipcode, phone number and relationship
        infile.ignore();               // Ignore the newline after year
        getline(infile, address);      // Read address
        getline(infile, city);         // Read city
        getline(infile, state);        // Read state
        infile >> zipcode;             // Read zip code
        infile.ignore();               // Ignore the newline after zip code
        getline(infile, phone);        // Read phone number
        getline(infile, relationship); // Read relationship

        // Create an extPersonType object and call addEntry function to 
        // add it to the addressList
        extPersonType newPerson(firstName, lastName, month, day, year,
            address, city, state, zipcode, phone, relationship);

        // Add the person to the address list
        addEntry(newPerson);  
    }

    // Close the file after reading
    infile.close();
}

//SORT BEFORE OR AFTER ADD??????????
void addressBookType::addEntry(extPersonType dataEntry) {
    if (length < maxLength) {
        addressList[length] = dataEntry; //Store the entry
        length++;                        //Increment the count of entries
        sortEntries();                   // Sort the list after adding the entry////////////////////////////////////////////////////////////////////////////////
    }
    else {
        cout << "The adress book is full. It is not possible to add more entries." << endl;
    }
}

//Accessor Functions

// Finds a person by last name and prints their details
void addressBookType::findPerson(string last_name) {
    for (int i = 0; i < length; i++) {
        if (addressList[i].getLastName() == last_name) {
            addressList[i].print();     // Print the person's details
            cout << endl;
            return;                     // Exit once the person is found
        }      
    }
    cout << "Person not found." << endl;
}

// Finds and prints all persons' first and last names with birthdays in 
// the given month
void addressBookType::findBirthdays(int month) {
    for (int i = 0; i < length; i++) {
        if (addressList[i].getBirthMonth() == month) {
            addressList[i].personType::print();     // Print only first and last names
            cout << endl;
            
        }
    }
}


// Finds and prints all persons with a specific relationship
void addressBookType::findRelations(string _relationship) {
    for (int i = 0; i < length; i++) {
        if (addressList[i].getRelationship() == _relationship) {
            addressList[i].personType::print();     // Print only first and last names
            cout << endl;

        }
    }
}


// prints all the entries in the addressList  
void addressBookType::print() {
    for (int i = 0; i < length; i++) {
        addressList[i].print();   // Print full details of each person
    }
    cout << endl;                               //////////////////////////////////////////////////////////
}


// Sorting function
// sort the list using lastName field as the sort key 
// Sorts the addressList alphabetically by last name ///////////////////////////////////////////

void addressBookType::sortEntries() {
    int current = 1; // Start from the second element
    int index;
    bool placeFound;
    extPersonType temp;

    // Outer loop to iterate through the addressList
    while (current < length) {
        index = current;    // Set index to the current position
        placeFound = false; // Flag to indicate if the correct place is found

        // Inner loop to compare and sort elements
        while (index > 0 && !placeFound) {
            // Compare last names for sorting
            if (addressList[index].getLastName() < addressList[index - 1].getLastName()) {
                // Swap if the current last name is less than the previous one
                temp = addressList[index];
                addressList[index] = addressList[index-1];
                addressList[index - 1] = temp;
                index = index - 1;  // Move back to continue checking
            }
            else {
                placeFound = true; // Found the correct place
            }
        }

        current = current + 1; // Move to the next element
    }
}
