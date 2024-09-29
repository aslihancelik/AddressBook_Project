#pragma once
#include <iostream>
using namespace std;

class personType
{
private:
	string firstName;
	string lastName;

public:
	//Constructor
	personType(string = "", string = "");

	//Setters

	void setFirstName(string first_name);
	void setLastName(string last_name);

	//Getters

	string getFirstName() { return firstName; }
	string getLastName() { return lastName; }

	//Print function

	void print();
};

