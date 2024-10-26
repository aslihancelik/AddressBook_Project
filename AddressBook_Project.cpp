// Client Program for Address Book Management
//
// Summary:
// This client program interacts with the user to manage an online address book through a menu-driven interface. 
// It allows users to view all entries, search by name, filter by birth month or relationship, and add or display 
// entries. The program reads data from a file to initialize the address book and sorts it by last name upon each 
// entry. The menu will continue to display until the user selects the option to quit.
//
// Key Features:
// - Display all entries in the address book.
// - Search for an entry by last name.
// - Filter entries by birth month or relationship tag (e.g., Business, Friend, Family).
// - Menu-driven navigation for user-friendly interaction.
// - Exits when the user selects the quit option.
//
// Programmer: Aslihan Celik



#include <iostream>
#include "addressBookType.h"

using namespace std;
// Function to display the menu and return the user's choice
// postcondition: returns the user’s selection
int showMenu() {
	int choice;
	cout << "Online Address Book" << endl;
	cout << "Select an option (enter the number):" << endl;
	cout << "1. Display all entries in the address Book." << endl;
	cout << "2. Display an entry by a person’s name." << endl;
	cout << "3. Display all entries with a given birth month." << endl;
	cout << "4. Display all entries with a given relationship tag (Business, Friend, Family)." << endl;
	cout << "5. Add a new entry to the adress book." << endl;
	cout << "6. Quit" << endl;
	cin >> choice; 
	return choice;
}

int main() {

	int choice, month, day, year, zipcode;
	string firstName, lastName, relationship, address, city, state, phone;

	addressBookType addressBook;
	addressBook.initEntry("AddressBookData.txt");

	do {
		choice = showMenu();
		switch (choice) {
		case 1:
			addressBook.print(); // Display all entries
			break;
		case 2:
			cout << "Please enter the first name of the person." << endl;
			cin >> firstName;
			cout << "Please enter the last name of the person." << endl;
			cin >> lastName;
			addressBook.findPerson(firstName, lastName); // Display entry by person's name
			break;
		case 3:
			cout << "Please enter the number of the birth month. (1-12)" << endl;
			cin >> month;
			addressBook.findBirthdays(month); // Display entries with a given birth month
			break;
		case 4:
			cout << "Please enter the relationship tag as one of the following: Business, Friend, Family" << endl;
			cin >> relationship;
			addressBook.findRelations(relationship); // Display entries with a given relationship
			break;
		case 5:

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
			cout << "Please enter the address (ex: Disney Road):" << endl; 
			getline(cin, address);
			cout << "Please enter the city:" << endl; 
			getline(cin, city);
			cout << "Please enter the year state in (ex: FL , CA ):" << endl; 
			getline(cin, state);
			cout << "Please enter the zipcode in 5 digit format:" << endl; 
			cin >> zipcode;
			cout << "Please enter the phone number in XXX-XXX-XXXX format:" << endl; 
			getline(cin, phone);
			cout << "Please enter the relationship of this person to you as one of the following: Business, Friend, Family:" << endl;
			getline(cin, relationship);
			break;

		case 6:
			cout << "Exiting program." << endl; // Quit the program
			break;
		default: 
			cout << "Invalid choice. Please try again." << endl; // Handle invalid choices
			break;
		}
		
	} while (choice != 6); // Continue until user chooses to quit

	return 0;
}
