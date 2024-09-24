/*
 * Programmer: Aslihan Celik
 *
 * dateType.h : Declaration of a class to represent and manage a date.
 *
 * This header file declares the member functions and variables for the dateType class.
 * It includes methods to set a date, validate the month, day, and year, calculate the
 * number of days in a month, and determine if a year is a leap year. It also defines
 * constructor suitable for default and parameterized initialization.
 */

#pragma once
#include <iostream>
using namespace std;

class dateType
{
private:
	int dMonth;  // Month of the date (1-12)
	int dDay;    // Day of the date (based on the month and year)
	int dYear;   // Year of the date (minimum 1900)

public:

	//Constructor
	//Precondition: Must check to ensure that the date is valid before storing the data in the member variables.
	//              - year >= 1900
	//              - 1<= month <= 12
	//              - day must be between 1 and the last day of the month. If year is 
	//                a leap year and month is 2 (February), the last day of the month is 29 rather than 28.
	// 
	//Postcondition:Use the supplied data if valid. 
	//              If the data is not valid, a default value is set as follows:
	//              - month : 1 as default value
	//              - day :   1 as the default value
	//              - year :  1900 as the default value

	dateType(int = 1, int = 1, int = 1900);


	//Setter
	//  
	// Sets the date by validating the month, day, and year
	//Precondition: Must check to ensure that the date is valid before storing the data in the member variables.
	//              - year >= 1900
	//              - 1<= month <= 12
	//              - day must be between 1 and the last day of the month. If year is 
	//                a leap year and month is 2 (February), the last day of the month is 29 rather than 28.
	// 
	//Postcondition:Use the supplied data if valid. 
	//              If the data is not valid, a default value is set as follows:
	//              - month : 1 as default value
	//              - day :   1 as the default value
	//              - year :  1900 as the default value
	//                
	void setDate(int month, int day, int year);

	//Getters

	int getDay() { return dDay; }
	int getMonth() { return dMonth; }
	int getYear() { return dYear; }

	//Calculates the number of days in a specified month of a given year
	int getDaysInMonth(int month, int year);


	// Prints the date in MM-DD-YYYY format
	void print();

	//Function to determine if the year is leap year
	bool isLeapYear(int year);

};

