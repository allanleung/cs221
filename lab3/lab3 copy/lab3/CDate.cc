// ..................................................  
// CDate class definitions
// Adapted from Hagit Schechter, Jan 2007 for 2014W2 
// ..................................................

#include <iostream>
#include <string>
#include "CDate.h"

CDate::CDate(void){
	m_year = m_month = m_day = 0;
}

CDate::CDate(int year, int month, int day){
	setDate( year, month, day );        
}

CDate::CDate(int year, std::string month, int day){
	// TODO you need to fill in the code here        ********
	// HINT use monthStr2Num to get the month_num 
	if (isValidDate(year,month,day)) { //there is a function to test validity of date w/ month in string
		int monthInt = monthStr2Num(month);
		setDate(year,monthInt, day);
	}
	else setDate(0,0,0);
}

bool CDate::isValidDate(int year, int month, int day){
	// TODO you need to fill in the code here        ********
	// comment out the "return false" below 
	// then check the validity of a year, month, and day
	if (isValidDay(year,month,day))
		return true;
	return false;
}

bool CDate::isValidDate(int year, std::string month, int day){
	// TODO you need to fill in the code here        ********
	// comment out "return false" below
	// HINT use monthStr2Num to get the month_num 
	// and then reuse another function
	int monthInt = monthStr2Num(month);
	return isValidDate(year,monthInt,day);
}

int CDate::monthStr2Num(std::string month) {
	// TODO you need to fill in the code here        ********
	char firstLetterOfMonth;
	firstLetterOfMonth = month.at(0);
	char secondLetterOfMonth = month.at(1);
	switch (firstLetterOfMonth)	{
		case 'A':
			if (secondLetterOfMonth == 'p') 
				return 4;
			else if (secondLetterOfMonth == 'u')
				return 8;
			break;
		case 'D':
			if (secondLetterOfMonth == 'e')
				return 12;
			break;
		case 'F':
		
			if (secondLetterOfMonth == 'e')
				return 2;
			break;
		case 'J':
			if (secondLetterOfMonth == 'a')
				return 1;
			else if (month[3] == 'l')
				return 7;
			else if (month[3] == 'n')
				return 6;
			break;
		case 'M':
			if (month[3] == 'r')
				return 3;
			else if (month[3] == 'y')
				return 5;
			break;
		case 'N':
			if (secondLetterOfMonth == 'o')
				return 11;
			break;
		case 'O':
			if (secondLetterOfMonth == 't')
				return 10;
			break;
		case 'S':
			if (secondLetterOfMonth == 'e')
				return 9;
			break;
		default: 
			std::cout << "that is not a valid month entry" << std::endl;
			//break;	
			
	}
	return -1;
}

bool CDate::isValidDay(int year, int month, int day){
	if ((day < 1) || (day > 31)) return false;

	bool valid = false;
	switch (month) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			// TODO you need to fill in the code here        ********
			valid = true;
			return valid;
			break;
		case 2:
			// Don't worry about this code too much.
			// It handles all the leap year rules for February.
			if ((year % 4) != 0) {
				valid = (day <=28);
			} else if ((year % 400) == 0) {
				valid = (day <= 29);
			} else if ((year % 100) == 0) {
				valid = (day <= 28);
			} else {
				valid = (day <= 29);
			}
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			// TODO you need to fill in the code here        ********
			if (day != 31)
				valid = true;
			return valid;
			break;
		default:
			// TODO you need to fill in the code here        ********
			std::cout << "Not a valid month number" << std::endl;
			//break; 
	}
	return valid;
}

void CDate::setDate(int year, int month, int day){
	if(isValidDate(year, month, day)){    
		m_year = year;
		m_month = month;
		m_day = day;
	}
	else {
		m_year = m_month = m_day = 0;
	}
}


void CDate::setDate(int year, std::string month, int day){
	// TODO you need to fill in the code here        ********
	// HINT use monthStr2Num to get the month_num 
	// and then reuse another function
	int monthInt = monthStr2Num(month);
	setDate(year, monthInt, day);
}

void CDate::print(void){
	std::cout << m_year << "/" << m_month << "/" << m_day << std::endl;
}

int CDate::getDate(void){
	return (m_year * 10000) + (m_month * 100) + m_day;
}

