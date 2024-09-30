// personType.cpp
// This source file implements the member functions of the personType class 
// defined in personType.h. It includes the constructor to initialize the 
// names, setters to update them, and a print function to output the full 
// name of the person.
//
// Programmer: Aslihan Celik
//

#include "personType.h"
#include <iostream>
using namespace std;

// Constructor definition
// Initializes firstName and lastName using the provided parameters.
// If no parameters are provided, the names will be empty strings.

personType::personType(string first_name, string last_name) {
	setFirstName(first_name);   // Set first name using setter
	setLastName(last_name);     // Set last name using setter
}

//Setters

// Sets the first name of the person
void personType::setFirstName(string first_name) {
	firstName = first_name;  // Directly assign the first name
}


// Sets the last name of the person
void personType::setLastName(string last_name) {
	lastName = last_name;    // Directly assign the last name
}

//Print function
// Outputs the full name (first and last) of the person to the console
void personType::print() {
	cout << firstName << " " << lastName << endl;
}