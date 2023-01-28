#include <iostream>


using namespace std;

int main() {
	int n;

	cout << "Please enter a positive integer: " << endl;
	cin >> n;
	cout << endl;

	if (n <= 0) cout << "Entry not a positive integer, please try again.\n\n";

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) cout << i * j << "\t";
		cout << endl;
	}

	return 0;
}
