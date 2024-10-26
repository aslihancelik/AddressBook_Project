//
// Programmer: Aslihan Celik
// 
// addressBookType.h :
// addressBookType Implementation
// This file implements the functions of the addressBookType class, which manages a linked list of 
// extPersonType objects. It provides functionality for reading entries from a file, adding entries 
// to the address book, sorting them by "last_name first_name", and searching by first_name last_name,
// birth month, or relationship. It also prints all entries in the address book.  
// 
//
// Key Features:
// - Initialize address book from a file.
// - Add new entries 
// - Search and filter entries by full name, birth month, or relationship.
// - Sort entries alphabetically by "last name first name".
// - Print all stored entries.
//


#include "addressBookType.h"

// Constructor to initialize the address book
addressBookType::addressBookType() {

} 
// Initializes entries from a file
void addressBookType::initEntry(string dataFile) {     

    ifstream infile(dataFile);  // Open the file for reading

    // check if the file opened successfully to avoid runtime errors.
    if (!infile) {
        cerr << "Error opening file" << endl;  
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
        addEntry(newPerson);  // Call the insert function from orderedLinkedList
    }

    // Close the file after reading
    infile.close();
}


void addressBookType::addEntry(extPersonType dataEntry) {

 // Call the insert function from orderedLinkedList class

    this->insert(dataEntry);
}

//Accessor Functions


// Finds a person by first and last name and prints their details
void addressBookType::findPerson(string first_name, string last_name) {

    extPersonType searchPerson(first_name, last_name);
    nodeType<extPersonType>* current = this->first;

    while (current != nullptr) {
        if (current->info == searchPerson) {
            current->info.print();
            cout << endl;
            return;
        }
        current = current->link;
    }
    cout << "Person not found." << endl;
}

// Finds and prints all persons' first and last names with birthdays in 
// the given month
void addressBookType::findBirthdays(int month) {
 
    nodeType<extPersonType>* current = this->first;

    while (current != nullptr) {
        if (current->info.getBirthMonth() == month) {
            current->info.personType::print();
            cout << endl;
        }
        current = current->link;
    }
}  


// Finds and prints all persons with a specific relationship
void addressBookType::findRelations(string _relationship) {

    nodeType<extPersonType>* current = this->first;

    while (current != nullptr) {
        if (current->info.getRelationship() == _relationship) {
            current->info.personType::print();
            cout << endl;
        }
        current = current->link;
    }
} 


// prints all the entries in the addressList  
void addressBookType::print() {

    nodeType<extPersonType>* current = this->first;

    while (current != nullptr) {
        current->info.print();
        current = current->link;
    }
    cout << endl;
}
