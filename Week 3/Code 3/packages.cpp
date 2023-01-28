#include <iostream>
using namespace std;

double const PRICE = 99.0;

int main() {
	int packages;
	double discount;
	cout << "Enter the number of packages purchased: ";
	cin >> packages;

	if (packages < 10){
		cout << "0% discount" << endl;
		discount = 0;
	}
	else if (packages <= 19) {
		cout << "10% discount" << endl;
		discount = 0.1;
	}
	else if (packages <= 49) {
		cout << "20% discount" << endl;
		discount = 0.2;
	}
	else if (packages <= 99){
		cout << "30% discount" << endl;
		discount = 0.3;
	}
	else {
		cout << "40% discount" << endl;
		discount = 0.4;
	}

	double total = (double)(PRICE * packages) * (1-discount);
	cout << "After the discount the total is: $" << total << endl;

	return 0;
}
