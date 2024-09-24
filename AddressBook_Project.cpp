// 
// Programmer: Aslihan Celik
// 
// AdressBook_Project.cpp : 
// This program tests the functionality of the dateType class by creating a date using the default constructor,
// initializing dates with a parameterized constructor, validating invalid dates.
//  
// Additionally: 
//     Tests edge cases: 
//       - Minimum date (January 1, 1900)
//       - End of year (December 31, 1999)
//       - Leap year (February 29, 2020)
//       - Non-leap year (February 29, 2019)
//

#include "dateType.h"
#include <iostream>
using namespace std;

int main()
{
    cout << "Testing default constructor ... " << endl;
    dateType defDate;
    defDate.print();
    cout << endl;

    cout << "Testing constructor with parameters ... " << endl;
    dateType date(2, 29, 2016);
    date.print();
    cout << endl;

    cout << "Setting date with invalid year (1000) ... " << endl;
    date.setDate(2, 29, 1000);
    date.print();
    cout << endl;

    cout << "Setting date with invalid month (13) ... " << endl;
    date.setDate(13, 29, 2016);
    date.print();
    cout << endl;

    cout << "Setting date with invalid day (4, 31) ... " << endl;
    date.setDate(4, 31, 2016);
    date.print();
    cout << endl;

    cout << "Setting invalid date: Feb 29, 2015 ... " << endl;
    date.setDate(2, 29, 2015);
    date.print();
    cout << endl;

    cout << "Setting valid date: Feb 28, 2015 ... " << endl;
    date.setDate(2, 28, 2015);
    date.print();
    cout << endl;

    cout << "Setting valid date (August 15, 2016) ... " << endl;
    date.setDate(8, 15, 2016);
    date.print();
    cout << endl;

    //The test cases I added

    // Edge Cases
    cout << "Edge Cases" << endl;
    cout << "Testing minimum valid date: January 1, 1900 ... " << endl;
    date.setDate(1, 1, 1900);
    date.print();
    cout << endl;

    cout << "Testing end of the year: December 31, 1999 ... " << endl;
    date.setDate(12, 31, 1999);
    date.print();
    cout << endl;

    cout << "Testing leap year: February 29, 2020 ... " << endl;
    date.setDate(2, 29, 2020);
    date.print();
    cout << endl;

    cout << "Testing non-leap year: February 29, 2019 ... " << endl;
    date.setDate(2, 29, 2019); // Should trigger default values
    date.print();
    cout << endl;


    return 0;

}
