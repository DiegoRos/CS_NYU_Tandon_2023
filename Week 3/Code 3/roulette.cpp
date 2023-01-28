#include <iostream>
using namespace std;

int main() {
	int pocketNum;

	cout << "Enter a number between 0 and 36: ";
	cin >> pocketNum;

	if (pocketNum > 36 || pocketNum < 0) {
		cout << "Incorrect number entered, try again." << endl;
		return -1;
	}

	if (pocketNum == 0) cout << "The pocket is GREEN" << endl;
	else if (pocketNum <= 10 && pocketNum % 2 == 0) cout << "The pocket is BLACK" << endl;
	else if (pocketNum <= 10 && pocketNum % 2 == 1) cout << "The pocket is RED" << endl;
	else if (pocketNum <= 18 && pocketNum % 2 == 1) cout << "The pocket is BLACK" << endl;
	else if (pocketNum <= 18 && pocketNum % 2 == 0) cout << "The pocket is RED" << endl;
	else if (pocketNum <= 28 && pocketNum % 2 == 0) cout << "The pocket is BLACK" << endl;
	else if (pocketNum <= 28 && pocketNum % 2 == 1) cout << "The pocket is RED" << endl;
	else if (pocketNum <= 36 && pocketNum % 2 == 1) cout << "The pocket is BLACK" << endl;
	else  cout << "The pocket is RED" << endl;

	return 0;
}
