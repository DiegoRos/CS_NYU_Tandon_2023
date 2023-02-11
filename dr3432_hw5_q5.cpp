#include <iostream>
#include <string>

using namespace std;

bool checkValidInput(string str);

int main(){
	string name, middle, last;
	cout << "Please enter your name: ";
	cin >> name >> middle >> last;

	if (!checkValidInput(name) && !checkValidInput(name) && !checkValidInput(last)){
		cout << "Invalid string input, please try again." << endl;
		return 1;
	}

	cout << last << " " << middle[0] << ". " << last; 

	return 0;
}

bool checkValidInput(string str) {
	if (str.length() == 0) return false;
	if (!isalpha(str[0])) return false;

	return true;
}