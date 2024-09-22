/*
* Programmer: Aslihan Celik
*
* The addressType class is designed to store and manage the details of a physical address,
*including the street address, city, state, and ZIP code. It provides functionality for setting
*and retrieving these details, as well as printing the complete address in a standard format.
*/

#pragma once
#include<iostream>
using namespace std;

class addressType
{

private:
	string address;  
	string city;
	string state;
	int zipcode;

public:

	// Constructor for the addressType class with default parameters.
	// Precondition: Accepts four parameters: 
	//               - A string for the street address (default: "(Your address)")
	//               - A string for the city (default: "(Your city)")
	//               - A string for the state (must be 2 characters, default: "XX")
	//               - An integer for the ZIP code (must be between 11111 and 99999, default: 10000).
	// Postcondition: Initializes the addressType object with the provided values or defaults if no arguments are passed.

	addressType(string = "(Your address)", string = "(Your city)", string = "XX", int = 10000);

	//Setters
	void setAddress(string addr); // Sets the street address
	void setCity(string cty);     // Sets the city

	//Precondition: States must use postal abbreviations limited to two characters.
	//Postcondition: Assigns the state value if its valid; otherwise, assigns the default value "XX".
	void setState(string st);

	// Precondition: ZIP code must be an integer between 11111 and 99999.
    // Postcondition: Assigns the ZIP code if valid; otherwise, assigns the default value 10000.
	void setZipcode(int zip);

	//Getters

	// Returns the street address
	string getAddress() {
		return address;
	}
	// Returns the city
	string getCity() {
		return city;
	}
	// Returns the state
	string getState() {
		return state;
	}
	// Returns the ZIP code
	int getZipcode() {
		return zipcode;
	}

	//Function to print the address
	void print();

};

