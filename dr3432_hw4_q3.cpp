#include <iostream>
#include <string>

using namespace std;

int main() {
	int inputNum, holder;
    string binString;

    cout << "Enter a decimal number: ";
    cin >> inputNum;

	if (inputNum < 0){ 
		cout << "Negative number entered, try again" << endl; 
		return -1;
	}

	if (inputNum == 0) {
		cout << "The binary represetnation of 0 is 0" << endl; 
		return 0;
	}

	holder = inputNum;
    int temp;
    while (inputNum > 0) {
        temp = inputNum % 2;
        binString = to_string(temp) + binString;

        inputNum /= 2;

    }

    cout << "The binary represetnation of " << holder << " is " << binString << endl;

	return 0;
}
