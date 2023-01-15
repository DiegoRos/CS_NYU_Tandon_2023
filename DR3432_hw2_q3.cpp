#include <iostream>
using namespace std;

int main() {
	int johnDays, johnHours, johnMinutes;
	int billDays, billHours, billMinutes;

	cout << "Please enter the number of days John has worked: ";
	cin >> johnDays;
	cout << "Please enter the number of hours John has worked: ";
	cin >> johnHours;
	cout << "Please enter the number of minutes John has worked: ";
	cin >> johnMinutes;

	cout << endl;
	cout << "Please enter the number of days Bill has worked: ";
	cin >> billDays;
	cout << "Please enter the number of hours Bill has worked: ";
	cin >> billHours;
	cout << "Please enter the number of minutes Bill has worked: ";
	cin >> billMinutes;
	cout << endl;

	int totalDays, totalHours, totalMinutes;
	int extra = 0;

	totalMinutes = johnMinutes + billMinutes;
	extra = totalMinutes / 60;
	totalMinutes = totalMinutes % 60;

	totalHours = johnHours + billHours + extra;
	extra = totalHours / 24;
	totalHours = totalHours % 24;

	totalDays = johnDays + billDays + extra;
	
	cout << "\nThe total time both of them worked together is: " 
			<< totalDays << " days, " 
			<< totalHours << " hours, and " 
			<< totalMinutes << " minutes." << endl; 
	
	return 0;
}
