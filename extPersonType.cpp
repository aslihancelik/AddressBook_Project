// extPersonType.cpp
// This file implements the extPersonType class, which inherits from the personType class
// and composes addressType and dateType objects. It provides functionality to store
// and manage personal details including name, address, birth date, phone number,
// and relationship status. The class includes methods for setting and getting values,
// as well as a print function to display all relevant information.
//
// Programmer: Aslihan Celik

#include "extPersonType.h"
#include <iostream>
#include <string>
using namespace std;


//Constructor implementation
// Initializes the extPersonType object by calling the base class constructor (personType)
// and initializing the composed objects (dateType and addressType).
extPersonType::extPersonType(string first_name, string last_name, int month, int day, 
	                         int year, string addr, string cty, string st, int zip,
	                         string phone_number, string _relationship)
	:personType(first_name, last_name),    // Initialize the personType base class (first and last name)
	 birthDate(month, day, year),          // Initialize birthDate (dateType object) 
	 address(addr, cty, st, zip)           // Initialize address (addressType object)
{
	phoneNumber = phone_number;            // Initialize phone number
	setRelationship(_relationship);        // Use the setter to ensure valid relationship
}


//Setters

// Setter for phone number
void extPersonType::setPhoneNumber(string phone_number) {
	phoneNumber = phone_number;  // Assign the phone number to the member variable
}

// Setter for relationship with validation
// Only accepts valid relationships: "Family", "Friend", or "Business".
void extPersonType::setRelationship(string _relationship) {
	if (_relationship == "Family" || _relationship == "Friend" || _relationship == "Business") {
		relationship = _relationship;  // Set the valid relationship
	}
	else {
		relationship = "None";  // Default to "None" if invalid
	}
}


//Getters

//Get the phone number
string extPersonType::getPhoneNumber() {
	return phoneNumber;              // Return the stored phone number
}

//Get the relationship
string extPersonType::getRelationship() {
	return relationship;             // Return the stored relationship
}

// Getter for birth month (from birthDate)
int extPersonType::getBirthMonth() {
	return birthDate.getMonth();     // Return the value from birthdate object
}



// Print function to display the data
void extPersonType::print() {
	
	personType::print();          // Print name from personType
	birthDate.print();            // Print birthday from dateType
	address.print();              // Print address from addressType
	cout << phoneNumber << endl;
	cout << relationship << endl;
}

// Overload the == operator
bool extPersonType::operator ==(const extPersonType& other) const {
	string key1 = last_name + " " + first_name;
	string key2 = other.lastName + " " + other.firstName;
	return key1 == key2;
}

// Overload the != operator
bool extPersonType::operator!=(const extPersonType& other) const {
	return !(*this == other);
}

// Overload the >= operator
bool extPersonType::operator>=(const extPersonType& other) const {
	string key1 = lastName + " " + firstName; 
	string key2 = other.lastName + " " + other.firstName;
	return key1 >= key2;
}