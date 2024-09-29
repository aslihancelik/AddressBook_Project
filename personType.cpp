#include "personType.h"
#include <iostream>
using namespace std;

///////////////////////////////////////////////!!!!!!!!!!!!
// maybe set directly
//Constructor definition
personType::personType(string first_name, string last_name) {
	setFirstName(first_name);
	setLastName(last_name);

	// firstName = first_name;
	// lastName = last_name;
}

//Setters

void personType::setFirstName(string first_name) {
	firstName = first_name;
}

void personType::setLastName(string last_name) {
	lastName = last_name;
}

//Print function

void personType::print() {
	cout << firstName << " " << lastName << endl;
}