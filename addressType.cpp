/* 
* Programmer: Aslihan Celik
* 
* This source file implements the methods of the addressType class defined in addressType.h.
* It includes the constructor, setter and getter methods for managing address details,
* and a print function to display the address in a standard format.The implementation
* ensures proper validation for the state abbreviation and ZIP code.
*/

#include "addressType.h"
#include <iostream>

using namespace std;


//Constructor definition
addressType::addressType(string addr, string cty, string st, int zip) {
	address = addr;
	city = cty;
	setState(st);      //Validate and assign state
	setZipcode(zip);   //Validate and assign ZIP code
}

//Setters

void addressType::setAddress(string addr) {
	address = addr;
}

void addressType::setCity(string cty) {
	city = cty;
}

void addressType:: setState(string st) {
	if (st.length() == 2) {
		state = st;
	}
	//Invalid state provided.Default 'XX' assigned.
	else {
		state = "XX"; // Default value
	}
}

void addressType:: setZipcode(int zip) {
	if (zip >= 11111 && zip <= 99999) {
		zipcode = zip;
	}
	//Invalid ZIP code provided. Default '10000' assigned.
	else {
		zipcode = 10000; // Default value
	}
}

void addressType:: print() {
	cout << address << endl
		<< city << " " << state << ", " << zipcode << endl;
}
