#include <iostream>

using namespace std;

const int FLOOR_ROUND = 1;
const int CEILING_ROUND = 2;
const int ROUND = 3;

int main() {
	double num;
	int rouded;
	int option;

	cout << "Please enter a Real number: "<< endl;
	cin >> num;

	cout <<"\nChoose your rounding method: " 
		<< "\n1. Floor round\n2. Celing round\n3. Round to nearest whole number" << endl;

	cin >> option;
	cout << endl;
	switch (option) {
	case FLOOR_ROUND:
		cout << (int) num << endl;
		break;

	case CEILING_ROUND:
		cout << (int) (num + 1) << endl;
		break;

	case ROUND:
		if (num - (int) num < 0.5) cout << (int) num << endl;
		else cout << (int) (num + 1) << endl;
		break;
	
	default:
		cout << "\nOption selected not valid, try again.\n\n";
		break;
	}
	

	return 0;
}

