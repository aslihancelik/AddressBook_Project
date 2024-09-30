// personType.h
// This header file defines the personType class, which represents a person 
// with a first name and a last name. It includes member variables for the 
// names, along with setter and getter functions to access and modify 
// those names, and a print function to display the full name.
//
// Programmer: Aslihan Celik
//

#pragma once
#include <string>
using namespace std;

// personType class definition
// This class represents a person with a first name and a last name.
class personType
{
private:
	string firstName;   // Stores the first name of the person
	string lastName;    // Stores the last name of the person

public:

	// Constructor with default parameters
    // Initializes firstName and lastName to empty strings if no values are provided.
	personType(string = "", string = "");

	//Setters

	// Sets the first name of the person
	void setFirstName(string first_name);

	// Sets the last name of the person
	void setLastName(string last_name);

	//Getters

	// Returns the first name of the person
	string getFirstName() { return firstName; }

	// Returns the last name of the person
	string getLastName() { return lastName; }

	//Print function

	// Outputs the full name (first and last) of the person
	void print();
};

