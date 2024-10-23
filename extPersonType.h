// extPersonType.h
// The extPersonType class inherits from personType and composes addressType and dateType objects.
// It represents an extended person with additional details like address, phone number, birthdate, and relationship.
//
// Programmer: Aslihan Celik
//

#pragma once
#include "personType.h"
#include "addressType.h"
#include "dateType.h"

using namespace std;

class extPersonType : public personType
{
private:

	addressType address;   // Stores the address of the person (composed from addressType class)
	dateType birthDate;    // Stores the birthdate of the person (composed from dateType class)
	string phoneNumber;    // Stores the phone number
	string relationship;   // Stores the relationship (e.g., Family, Friend, Business)

public:
	
	// Constructor that initializes an extPersonType object with default values or user-provided values.
	// Default values for name, birthdate, address, phone number, and relationship are provided.
	extPersonType(string = "", string = "", int = 1, int = 1, int = 1900, string = "", 
		          string = "", string = "XX", int = 10000, string = "None", string = "None");

	//Setter
	// Setter function to set the phone number of the person.
	void setPhoneNumber(string phone_number);
	// Setter function to set the relationship (only accepts Family, Friend, or Business).
	void setRelationship(string _relationship);

	//Getters

	// Getter function to retrieve the phone number.
	string getPhoneNumber();
	// Getter function to retrieve the relationship status.
	string getRelationship();
	// Getter function to retrieve the birth month (from the birthDate object).
	int getBirthMonth();

	// Function to print all the details of the person, including name, address, phone number, birthdate, and relationship.
	void print();

	
	// Operator overloads
	bool operator==(extPersonType& other);
	bool operator!=(extPersonType& other);
	bool operator>=(extPersonType& other);
	
};

