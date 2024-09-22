#include "addressType.h"
#include <iostream>

using namespace std;


//Constructor with parameters


addressType::addressType(string addr, string cty, string st, int zip) {
	address = addr;
	city = cty;
	setState(st);
	setZipcode(zip);
}



void addressType:: setState(string st) {
	if (st.length() == 2) {
		state = st;
	}
	else {
		state = "XX"; // Default value
		cout << "State is invalid" << endl;
	}
}

void addressType:: setZipcode(int zip) {
	if (zip >= 11111 && zip <= 99999) {
		zipcode = zip;
	}
	else {
		zipcode = 10000; // Default value
		cout << "Zipcode is invalid" << endl;
	}
}

void addressType:: print() {
	cout << address << endl
		<< city << ", " << state << " " << zipcode << endl;
}
