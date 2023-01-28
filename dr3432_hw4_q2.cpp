#include <iostream>
#include <string>

using namespace std;

int main() {

	string simplifiedRoman;
	int n;

	cout << "Enter a decimal number: ";
	cin >> n;
	cout << endl;

	if (n < 0){ 
		cout << "Negative number entered, try again" << endl; 
		return -1;
	}

	if (n == 0) {
		cout << "0 is 0" << endl; 
		return 0;
	}
	
	int holder = n, digit;
	int position = 1;
	while (holder) {
		digit = holder % 10;
		string temp;
		if (position == 1) {
			if (digit < 5) {
				for (int i = 0; i < digit; i++) temp += "I";
			}
			else {
				temp += "V";
				for (int i = 0; i < digit - 5; i++) temp += "I";
			}

		}
		else if (position == 2) {
			if (digit < 5) {
				for (int i = 0; i < digit; i++) temp += "X";
			}
			else {
				temp += "L";
				for (int i = 0; i < digit - 5; i++) temp += "X";
			}
		}
		else if (position == 3) {
			if (digit < 5) {
				for (int i = 0; i < digit; i++) temp += "C";
			}
			else {
				temp += "D";
				for (int i = 0; i < digit - 5; i++) temp += "C";
			}
		}
		else {
			for (int i = 0; i < holder; i++) temp += "M";

			holder = 0;
		}

		simplifiedRoman = temp + simplifiedRoman;
		holder /= 10;
		position++;
	}

	cout << n << " is " << simplifiedRoman << endl;

	return 0;
}
