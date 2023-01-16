#include <iostream>
#include<string>
using namespace std;

int main() {
	int hour24, minutes24;
	
	int hour12, minutes12;
	string period;
	
	char temp = 'y';

	cout << "Time format to convert (h = 24 hour, p = 12 hour): ";
	cin >> temp;

	if (temp == 'h') {
		cout << "Enter 24 hour time in format: hh mm\n";
		cin >> hour24 >> minutes24;

		minutes12 = minutes24;
		if (hour24 >= 0 && hour24 <= 11){
			period = "am";
			if (hour24 == 0) hour12 = 12;
			else hour12 = hour24;
		}
		else {
			period = "pm";
			if (hour24 == 12) hour12 = 12;
			else hour12 = hour24 - 12;

		}

		cout << hour24 << ":" << minutes24 << " is " << hour12 << ":" << minutes12 << period << " in 12 hour format\n";
	}
	else if (temp == 'p') {
		cout << "Enter 12 hour time in format: hh mm am/pm\n";
		cin >> hour12 >> minutes12 >> period;
				
		minutes24 = minutes12;
		if (period.compare("am") == 0) {
			if(hour12 == 12) hour24 = 0;
			else hour24 = hour12;
		}
		else {
			if (hour12 == 12) hour24 = hour12;
			else hour24 = hour12 + 12;
		}
		cout << hour12 << ":" << minutes12 << period <<" is " << hour24 << ":" << minutes24 << " in 24 hour format\n";
	}
	else {
		cout << "Invalid input try again... Goodbye" << endl;
	}

	return 0;
}
