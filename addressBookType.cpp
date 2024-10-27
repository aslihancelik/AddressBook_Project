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

void addressBookType::addEntryUser() {

    string firstName, lastName, address, city, state, phone, relationship;
    int month, day, year, zipcode;

    cout << "Please enter the first name:" << endl;
    cin >> firstName;
    cout << "Please enter the last name:" << endl;
    cin >> lastName;
    cout << "Please enter their birthday month (1-12):" << endl;
    cin >> month;
    cout << "Please enter the day for their bitthday(1-31):" << endl;
    cin >> day;
    cout << "Please enter the year of their birthday(xxxx):" << endl;
    cin >> year;
    cin.ignore();
    cout << "Please enter the address (ex: Disney Road):" << endl;
    getline(cin, address);
    cout << "Please enter the city:" << endl;
    getline(cin, city);
    cout << "Please enter the year state in (ex: FL , CA ):" << endl;
    getline(cin, state);
    cout << "Please enter the zipcode in 5 digit format:" << endl;
    cin >> zipcode;
    cin.ignore();
    cout << "Please enter the phone number in XXX-XXX-XXXX format:" << endl;
    getline(cin, phone);
    cout << "Please enter the relationship of this person to you as one of the following: Business, Friend, Family:" << endl;
    getline(cin, relationship);

    extPersonType newPerson(firstName, lastName, month, day, year,
        address, city, state, zipcode, phone, relationship);

    addEntry(newPerson);
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


// Finds a person by first and last name and prints their details
void addressBookType::deleteEntry(string first_name, string last_name) {

    // Create a search person object for the given first and last name
    extPersonType searchPerson(first_name, last_name);

    // Use the deleteNode function from orderedLinkedList
    // This assumes you are calling it on the ordered linked list that this class contains
    deleteNode(searchPerson); // Call deleteNode directly

    // Provide feedback to the user
    //if (searchPerson.getStatus() == "Deleted") { // You need to implement getStatus method in extPersonType
    //    cout << "Entry deleted: " << first_name << " " << last_name << endl;
    //}
    //else {
    //    cout << "Person not found." << endl;
    //}
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

//saves the new dat ato the file

void addressBookType::saveToFile(string filename) {

    //Backup the original file
    ifstream source(filename);
    ofstream destination(filename + ".bac");

    if (source.is_open() && destination.is_open()) {
        // Copy the existing content to backup file
        destination << source.rdbuf();
    }

    //close files
    source.close();
    destination.close();

    // Open the file for writing
    ofstream outFile(filename);
    if (!outFile) {
        cerr << "Error opening file for writing!" << std::endl;
        return;
    }

    // Redirect cout to outFile temporarily
    streambuf* originalCoutStreamBuffer = cout.rdbuf();
    cout.rdbuf(outFile.rdbuf());

    //traverse list
    nodeType<extPersonType>* current = this->first; 
    while (current != nullptr) {
        // This will now output to outFile instead of the console
        current->info.print(); 
        current = current->link;
    }
    // Restore cout to its original state
    cout.rdbuf(originalCoutStreamBuffer);
    outFile.close();

}