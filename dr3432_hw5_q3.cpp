#include <iostream>
#include <string>

using namespace std;

int monthCalendar(int numOfDays, int startigDay);
bool isLeapYear(int year);
void printCalendarYear(int year, int startingDay);

const int NUM_DAYS_OF_WEEK = 7;
string WEEK_DAYS_STR = "Mon\tTue\tWed\tThr\tFri\tSat\tSun";

const int DAYS_IN_JAN = 31;

const int DAYS_IN_FEB_NOT_LEAP = 28;
const int DAYS_IN_FEB_LEAP = 29;

const int DAYS_IN_MAR = 31;
const int DAYS_IN_APR = 30;
const int DAYS_IN_MAY = 31;
const int DAYS_IN_JUN = 30;
const int DAYS_IN_JUL = 31;
const int DAYS_IN_AUG = 31;
const int DAYS_IN_SEP = 30;
const int DAYS_IN_OCT = 31;
const int DAYS_IN_NOV = 30;
const int DAYS_IN_DEC = 31;



int main(){
	int year, numWeek;

	cout << "Enter the year to print: ";
	cin >> year;

	cout << "Enter integer for week day: \n 1 = Mon  2 = Tue  3 = Wed  4 = Thr  5 = Fri  6 = Sat  7 = Sun" << endl;
	cin >> numWeek;

	if (year < 0 || numWeek < 1 || numWeek > 7) {
		cout << "Year or weekday is invalid, try again." << endl;
		return -1;
	}

	printCalendarYear(year, numWeek);

	return 0;
}


int monthCalendar(int numOfDays, int startigDay){
	cout << WEEK_DAYS_STR << endl;
	for (int i = 1; i <= startigDay - 1; i++) cout << "\t";
	for (int i = 1; i <= (NUM_DAYS_OF_WEEK - startigDay + 1); i++) cout << i << "\t";
	cout << endl;

	int counter = 1;
	for (int i = NUM_DAYS_OF_WEEK - startigDay + 2; i <= numOfDays; i++) {
		cout << i << "\t";

		if (counter % NUM_DAYS_OF_WEEK == 0) cout << endl;
		counter++;
	}
	cout << endl;
	return (counter % NUM_DAYS_OF_WEEK == 0) ? 7  : counter % NUM_DAYS_OF_WEEK;
}


bool isLeapYear(int year){
	if (year % 4 == 0 && year % 100 == 0 && year % 400 == 0) return true;
	else if (year % 100 == 0) return false;
	else if (year % 4 == 0) return true;
	else return false;
}


void printCalendarYear(int year, int startingDay){
	cout << "January "<< year << endl;
	startingDay = monthCalendar(DAYS_IN_JAN, startingDay);

	cout<< endl;
	cout << "February "<< year << endl;
	if (isLeapYear(year)) startingDay = monthCalendar(DAYS_IN_FEB_LEAP, startingDay);
	else startingDay = monthCalendar(DAYS_IN_FEB_NOT_LEAP, startingDay);

	cout<< endl;
	cout << "March "<< year << endl;
	startingDay = monthCalendar(DAYS_IN_MAR, startingDay);

	cout<< endl;
	cout << "April "<< year << endl;
	startingDay = monthCalendar(DAYS_IN_APR, startingDay);

	cout<< endl;
	cout << "May "<< year << endl;
	startingDay = monthCalendar(DAYS_IN_MAY, startingDay);

	cout<< endl;
	cout << "June "<< year << endl;
	startingDay = monthCalendar(DAYS_IN_JUN, startingDay);

	cout<< endl;
	cout << "July "<< year << endl;
	startingDay = monthCalendar(DAYS_IN_JUL, startingDay);

	cout<< endl;
	cout << "August "<< year << endl;
	startingDay = monthCalendar(DAYS_IN_AUG, startingDay);

	cout<< endl;
	cout << "September "<< year << endl;
	startingDay = monthCalendar(DAYS_IN_SEP, startingDay);

	cout<< endl;
	cout << "October "<< year << endl;
	startingDay = monthCalendar(DAYS_IN_OCT, startingDay);

	cout<< endl;
	cout << "November "<< year << endl;
	startingDay = monthCalendar(DAYS_IN_NOV, startingDay);

	cout<< endl;
	cout << "December "<< year << endl;
	startingDay = monthCalendar(DAYS_IN_DEC, startingDay);
	cout << endl;
}

