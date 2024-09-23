#include "dateType.h"
#include <iostream>
using namespace std;

//Constructor definition

dateType::dateType(int month, int day, int year) {
	setDate(month, day, year);
}

void dateType::setDate(int month, int day, int year) {
	//bool isMonthValid, isYearValid;

	//Setting the month
	if (month >= 1 && month <= 12) {
		dMonth = month;
		//isMonthValid = true;
	}
	else {
		//cout << "Invalid month provided.Default 1 assigned." << endl;
		cout << "Date invalid, setting to 1 - 1 - 1900 "<< endl;
		dMonth = 1;
		dDay = 1;
		dYear = 1900;
		//isMonthValid = false;     //maybe remove
		return;
	}


	//Setting the year
	if (year >= 1900) {
		dYear = year;
		//isYearValid = true;
	}
	else {
		//cout << "Invalid year provided.Default 1900 assigned." << endl;
		cout << "Date invalid, setting to 1 - 1 - 1900 " << endl;
		//dYear = 1900;
		dMonth = 1;
		dDay = 1;
		dYear = 1900;
		//isYearValid = false;  //may remove
		return;
	}

	//need to add if days in a month is valid
	//if (isMonthValid == true && isYearValid == true) {
		if (day >= 1 && day <= getDaysInMonth(month, year)) {
			dDay = day;
		}
		else {
			//cout << "Invalid day provided. Default 1 assigned." << endl;
			cout << "Date invalid, setting to 1 - 1 - 1900 " << endl;
			//dDay = 1;
			dMonth = 1;
			dDay = 1;
			dYear = 1900;
			//isYearValid = false;  //may remove
			return;
		}
	//}
	//else {
	//	cout << "Either invalid month or year provided. Therefore, default of 1 is assigned for day." << endl;
	//	dDay = 1;
	//}
		
}


int dateType::getDaysInMonth(int month, int year) { 
	
	if (isLeapYear(year) == false) {
		if (month <= 7) {
			if (month == 2) {
				return 28   ;
			}
			else {
				if (month % 2 == 0) {
					return 30;
				}
				else {
					return 31;
				}
			}
		}
		else {
			if (month % 2 == 0) {
				return 31;
			}
			else {
				return 30;
			}

		}
	}
	else {
		if (month == 2) {
			return 29;
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