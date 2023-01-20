#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
	int startHour, startMin;
	char SEPARATOR;
	string weekDay;
	int minutes;

	cout << "Enter the time the call started in 24-hour format, e.g. hh:mm " << endl;
	cin >> startHour >> SEPARATOR >> startMin;

	cout << "Enter day of the week the call was placed, \n"
			<< "Mo = Monday, Tu = Tuedsay, We = Wednesday, Th = Thusday, "
			<< "Fr = Friday, Sa = Saturday, and Su = Sunday:\n";

	cin >> weekDay;
	//Convert string to upper case
	/*
		Explanation of code so you do not think I am cheating.
		
		This is an enhanced for loop which will loop over all of the iterables of the variable weekDay.
		In this case the iterable will give a pointer variable that will reference a character in weekDay. 

		auto = C++ keyword that automatically detects which type it should be assigned to.
			Cannot be used function declaration

		& after auto and before c = This states that the variable 'c' will be an reference to a poniter.
			In this case variable c will reference a specific character in the string weekDay. 

		If this is not sufficient explanation please contact me at dr3432@nyu.edu.
	*/
	for (auto &c : weekDay) c = toupper(c);

	cout << "Enter length of the call in minutes: ";
	cin >> minutes;

	cout << endl;

	if ((weekDay.compare("SA") == 0) || (weekDay.compare("SU") == 0)) 
		cout << "Cost of long distance call is: " << (double) minutes * 0.15 << endl;

	else if ((startHour >= 8) && (startHour < 18))
		cout << "Cost of long distance call is: " << (double) minutes * 0.4 << endl;

	else if ((startHour == 18) && (startMin == 0))
		cout << "Cost of long distance call is: " << (double) minutes * 0.4 << endl;
	
	else 
		cout << "Cost of long distance call is: " << (double) minutes * 0.25 << endl;
	
	cout << endl;
	return 0;
}

