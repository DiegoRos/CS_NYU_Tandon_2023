#include <iostream>


using namespace std;

int main() {
	int n;

	cout << endl << "Starting section a)" << endl;
	cout << "Please enter a positive integer: ";
	cin >> n;

	// While Loop version.
	int i = 1, temp = n;
	while (temp--) {
		cout << 2 * i << endl;
		i++;
	}
	
	cout << endl;

	cout << endl << "Starting section b)" << endl;
	// For Loop versoin.
	for (int i = 1; i <= n; i++)
		cout << 2 * i << endl;

	return 0;
}
