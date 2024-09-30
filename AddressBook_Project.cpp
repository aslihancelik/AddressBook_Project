#include <iostream>
#include "addressBookType.h"

using namespace std;

int main() {
    addressBookType addressBook; // Create an instance of addressBookType

    // Initialize the address book with data from a sample file
    string filename = "addressBookData.txt"; // Sample filename; ensure this file exists
    addressBook.initEntry(filename); // Populate the address book

    cout << "Address Book Entries Before Sorting:" << endl;
    addressBook.print(); // Print unsorted entries

    // Sort the entries by last name
    addressBook.sortEntries();

    cout << "\nAddress Book Entries After Sorting:" << endl;
    addressBook.print(); // Print sorted entries

    // Test finding a person
    string lastNameToFind = "Malik"; // Replace with a last name from your data file
    cout << "\nFinding person with last name: " << lastNameToFind << endl;
    addressBook.findPerson(lastNameToFind);

    // Test finding birthdays
    int monthToFind = 6; // Replace with a month number to test
    cout << "\nFinding birthdays in month: " << monthToFind << endl;
    addressBook.findBirthdays(monthToFind);

    // Test finding relations
    string relationshipToFind = "Friend"; // Replace with a relationship to test
    cout << "\nFinding persons with relationship: " << relationshipToFind << endl;
    addressBook.findRelations(relationshipToFind);

    return 0;
}
