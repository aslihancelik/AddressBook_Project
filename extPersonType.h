#pragma once
#include "personType.h"
#include "addressType.h"
#include "dateType.h"

using namespace std;

class extPersonType : public personType
{
private:

	addressType address;
	dateType birthDate;
	string phoneNumber;
	string relationship;

public:
	//Constructor
	extPersonType(string = "", string = "", int = 1, int = 1, int = 1900, string = "", string = "", string = "XX", int = 10000, string = "None", string = "None");

	//Setter
	void setPhoneNumber(string phone_number);
	void setRelationship(string _relationship);

	//Getters

	string getPhoneNumber() { return phoneNumber;}
	string getRelationship() { return relationship; }
	int getBirthMonth();

	void print();
};

