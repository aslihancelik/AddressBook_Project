// Programmer: Aslihan Celik
// 
// AdressBook_Project.cpp : 
// 
// This program tests the functionality of the addressType class by :
// 1. Creating and printing an address using the default constructor.
// 2. Creating and printing an address with provided parameters.
// 3. Testing the validation of an invalid state and invalid ZIP code.
// 4. Setting and printing a valid address.
//
#include "dateType.h"
#include <iostream>
using namespace std;

int main()
{
    cout << "Testing default constructor ... ";
    dateType defDate;
    defDate.print();
    cout << endl;
    cout << "Testing constructor with parameters ... ";
    dateType date(2, 29, 2016);
    date.print();
    cout << endl;
    cout << "Setting date with invalid year (1000) ... ";
    date.setDate(2, 29, 1000);
    date.print();
    cout << endl;
    cout << "Setting date with invalid month (13) ... ";
    date.setDate(13, 29, 2016);
    date.print();
    cout << endl;
    cout << "Setting date with invalid day (4, 31) ... ";
    date.setDate(4, 31, 2016);
    date.print();
    cout << endl;
    cout << "Setting invalid date: Feb 29, 2015 ... ";
    date.setDate(2, 29, 2015);
    date.print();
    cout << endl;
    cout << "Setting valid date: Feb 28, 2015 ... ";
    date.setDate(2, 28, 2015);
    date.print();
    cout << endl;
    cout << "Setting valid date (August 15, 2016) ... ";
    date.setDate(8, 15, 2016);
    date.print();
    cout << endl;

    return 0;

}
