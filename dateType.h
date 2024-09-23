#pragma once
#include <iostream>
using namespace std;

class dateType
{
private:
	int dMonth;
	int dDay;
	int dYear;

public:

	//Constructor
	//Setter
	//Precondition: Must check to ensure that the date is valid before storing the data in the member variables.
	//              - year >= 1900
	//              - 1<= month <= 12
	//              - day must be between 1 and the last day of the month. If year is 
	//                a leap year and month is 2 (February), the last day of the month is 29 rather than 28.
	// 
	//Postcondition: If the data is not valid, a default value is set as follows:
	//              - month : 1 as default value
	//              - day :   1 as the default value
	//              - year :  1900 as the default value

	dateType(int = 1, int = 1, int = 1900);


	//Setter
	//Precondition: Must check to ensure that the date is valid before storing the data in the member variables.
	//              - year >= 1900
	//              - 1<= month <= 12
	//              - day must be between 1 and the last day of the month. If year is 
	//                a leap year and month is 2 (February), the last day of the month is 29 rather than 28.
	// 
	//Postcondition: If the data is not valid, a default value is set as follows:
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


	//Print function
	void print();

	//Function to determine if the year is leap year
	bool isLeapYear(int year);

};

