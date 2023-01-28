#include <iostream>


using namespace std;

int main() {
	int n;

	cout << "Enter a possitive integer: ";
	cin >> n;
	cout << endl;

	if (n < 0){ 
		cout << "Invalid number entered, try again" << endl; 
		return -1;
	}

	int oddCount, evenCount;

	for (int i = 1; i <= n; i++){
		oddCount = 0; evenCount = 0;

		int holder = i;
		int digit;
		while (holder > 0) {
			digit = holder % 10;

			if (digit % 2 == 0) evenCount++;
			else oddCount++;

			holder /= 10;
		}

		if (evenCount > oddCount) cout << i << endl; 

	}

	return 0;
}
