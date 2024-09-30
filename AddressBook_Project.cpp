// 
// Programmer: Aslihan Celik
// 
// AddressBook_Project.cpp
// This program tests the functionality of the extPersonType class, which represents 
// a person with associated details such as birthdate, address, phone number, 
// and relationship. It includes tests for the default constructor, a 
// parameterized constructor, setting invalid and valid relationships, 
// and printing the person's details.

#include <iostream>
#include "extPersonType.h"

using namespace std;

int main()
{
    cout << "Testing default constructor ... " << endl;
    extPersonType defPerson;
    defPerson.print();
    cout << endl;

    cout << "Testing constructor with parameters ... " << endl;
    extPersonType person("George", "Smith", 4, 30, 1994, "145 South Street, Apt. 5", "Hampton", "VA", 23554, "757-444-5555", "Friend");
    person.print();
    cout << endl;

    cout << "Testing invalid relationship (Spouse) ... " << endl;
    person.setRelationship("Spouse");
    person.print();
    cout << endl;

    cout << "Testing valid relationship (Business) ... " << endl;
    person.setRelationship("Business");
    person.print();
    cout << endl;

    return 0;

}

