#include "dateType.h"
#include <iostream>
using namespace std;

//Constructor definition

dateType::dateType(int month, int day, int year) {
	setDate(month, day, year);
}

void dateType::setDate(int month, int day, int year) {

	//Setting the month
	if (month >= 1 && month <= 12) {
		dMonth = month;
	}
	else {
		cout << "Date invalid, setting to 1 - 1 - 1900 "<< endl;
		dMonth = 1;
		dDay = 1;
		dYear = 1900;
		return;
	}

	//Setting the year
	if (year >= 1900) {
		dYear = year;
	}
	else {
		cout << "Date invalid, setting to 1 - 1 - 1900 " << endl;
		dMonth = 1;
		dDay = 1;
		dYear = 1900;
		return;
	}

	//need to add if days in a month is valid
	if (day >= 1 && day <= getDaysInMonth(month, year)) {
		dDay = day;
	}
	else {
		cout << "Date invalid, setting to 1 - 1 - 1900 " << endl;
		dMonth = 1;
		dDay = 1;
		dYear = 1900;
		return;
	}
}

int dateType::getDaysInMonth(int month, int year) 
{

	if (month != 2) 
	{
		if (month <= 7) 
		{

			if (month % 2 == 0)
			{
				return 30;
			}
			else 
			{
				return 31;
			}
		}
		else 
		{
			if (month % 2 == 0)
			{
				return 31;
			}
			else 
			{
				return 30;
			}

		}
	}
	else 
	{
		if (isLeapYear(year)) 
		{
			return 29;
		}
		else 
		{
			return 28;
		}
	}


}

void dateType::print() {

	cout << dMonth << "-" << dDay << "-" << dYear << endl;

}

bool dateType::isLeapYear(int year) {
	//All years which are perfectly divisible by 4 are leap years except for century years (years ending with 00), 
	//which are leap years only if they are perfectly divisible by 400.

	//leap year is divisble by 400
	if (year % 400 == 0) {
			cout << " You entered a leap year." << endl;
			return true;
		}
	//if divisble by 100 but not 400, it is not a leap year
	else if (year % 100 == 0) {
		cout << " Year entered is not a leap year." << endl;
		return false;
	}
	//if not divisble by 100 but divisble bu 4, it is a leap year
	else if (year % 4 == 0) {
		cout << " You entered a leap year." << endl;
		return true;
	}
	//all the remaining years are not leap year
	else {
		cout << " Year entered is not a leap year." << endl;
		return false;

    //alternative
    /*
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
		cout << year << " is a leap year.";
	}
	else {
		cout << year << " is not a leap year.";
	}

	return 0;
    */


	}
	
}