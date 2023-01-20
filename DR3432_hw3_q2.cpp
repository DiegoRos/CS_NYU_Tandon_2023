#include <iostream>
#include <string>
using namespace std;

int main() {
	string name;
	int graduationYear, currentYear;

	cout << "Please enter your name: ";
	cin >> name;
	
	cout << "Please enter your graduation year: ";
	cin >> graduationYear;
	
	cout << "Please enter current year: ";
	cin >> currentYear;

	if (graduationYear - currentYear > 4) cout << name << ", you are not in college yet.\n";
	else if (graduationYear - currentYear == 4) cout << name << ", you are a Freshman.\n";
	else if (graduationYear - currentYear == 3) cout << name << ", you are a Sophomore.\n";
	else if (graduationYear - currentYear == 2) cout << name << ", you are a Junior.\n";
	else if (graduationYear - currentYear == 1) cout << name << ", you are a Senior.\n";
	else cout << name << ", you are a Graduated.\n";


	return 0;
}

