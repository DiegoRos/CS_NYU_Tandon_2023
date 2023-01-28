#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int count, temp;
	double gemoetricMean = 1;

	cout << endl << "Starting section a)" << endl;
	cout << "Please enter the length of the sequence: ";
	cin >> count;

	int i = 0;

	// a)
	cout << "Please enter your sequence of positive integers." << endl;
	while (i < count) {
		cin >> temp;
		if (temp <= 0) {
			cout << "Entry not valid count still at: " << i << endl;
		}
		else {
			gemoetricMean *= (double) temp;
			i++;
		}
	}

	cout << "The geometric mean is: " << pow(gemoetricMean, 1.0 / count) << endl;


	cout << endl << "Starting section b)" << endl;
	gemoetricMean = 1, i = 0;
	cout << "Please enter your sequence of positive integers." << endl;
	while (true) {
		cin >> temp;
		if (temp == -1) break;

		else if (temp <= 0) {
			cout << "Entry not valid count still at: " << i << endl;
		}
		else {
			gemoetricMean *= (double) temp;
			i++;
		}
	}
	cout << "The geometric mean is: " << pow(gemoetricMean, 1.0 / i) << endl;

	return 0;
}
