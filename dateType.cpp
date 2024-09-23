#include "dateType.h"
#include <iostream>
using namespace std;

//Constructor definition
dateType::dateType(int month, int day, int year) {
	setDate(month, day, year);
}

void dateType::setDate(int month, int day, int year) {

	//Default values
	dMonth = 1;
	dDay = 1;
	dYear = 1900;

	//Setting the month
	if (month >= 1 && month <= 12) {
		dMonth = month;
	}
	else {
		cout << "Date invalid, setting to 1 - 1 - 1900 "<< endl;
		return;
	}

	//Validate and Set the year
	if (year >= 1900) {
		dYear = year;
	}
	else {
		cout << "Date invalid, setting to 1 - 1 - 1900 " << endl;
		return;
	}

	//Validate and set the day
	if (day >= 1 && day <= getDaysInMonth(month, year)) {
		dDay = day;
	}
	else {
		cout << "Date invalid, setting to 1 - 1 - 1900 " << endl;
		return;
	}
}


/**
 * Calculates the number of days in a specified month of a given year as follows:
 *
 * This function checks if the month is February to account for leap years, returning
 * 29 days for leap years and 28 days otherwise. For other months, it uses their 
 * position in the calendar (1-12) along with odd/even criteria to determine whether 
 * the month has 30 or 31 days, following established patterns in the calendar.
 */
int dateType::getDaysInMonth(int month, int year) 
{
	// Check if the month is February (2)
	if (month == 2) {
		// If it's February, return 29 if it's a leap year, otherwise return 28
		return isLeapYear(year) ? 29 : 28;
	}
	// For months January to July (1 to 7)
	else if (month <= 7) 
	{   
		// Return 30 days for even months (4, 6) and 31 days for odd months (1, 3, 5, 7)
		return month % 2 == 0 ? 30 : 31;
	}
	// For months August to December (8 to 12)
	else 
	{
		// Return 31 days for even months (8, 10, 12) and 30 days for odd months (9, 11)
		return month % 2 == 0 ? 31 : 30;

	}

}

// Print function
void dateType::print() {

	cout << dMonth << "-" << dDay << "-" << dYear << endl;

}

bool dateType::isLeapYear(int year) {

	// All years which are perfectly divisible by 4 are leap years except for 
	// century years (years ending with 00), which are leap years only if they
	// are perfectly divisible by 400.

           //if true is a leap year , if false not a leap year
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	
}
	
