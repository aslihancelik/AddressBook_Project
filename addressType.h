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

	//constructor edit
	// 
	//edit!!!!!!!!!!!!!!!!
	/*
	//preconditions - 
	// postcondition -
	*/



	addressType(string = "(Your address)", string = "(Your city)", string = "XX", int = 10000);

	/*
	//Default Constructor
	addressType() : address(""), city(""), state("XX"), zipcode(10000) {}

	
	//Constructor with parameters

	addressType(string addr, string cty, string st, int zip) {
		address = addr;
		city = cty;
		setState(st);
		setZipcode(zip);
	}
    */

	void setAddress(string addr) {
		address = addr;
	}

	void setCity(string cty) {
		city = cty;
	}
	//Precondition: States use postal abbreviations limited to two characters
	//postcondtion: assigns the state value if its valid otherwise assigns the default value
	void setState(string st);

	/*
	//preconditions -
	// postcondition -
	*/
	void setZipcode(int zip);

	//Getters


	string getAddress() {
		return address;
	}
	string getCity() {
		return city;
	}
	string getState() {
		return state;
	}
	int getZipcode() {
		return zipcode;
	}
	void print();

};

