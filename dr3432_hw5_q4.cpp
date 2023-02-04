#include <iostream>
#include <cmath>

using namespace std;

void printDivisors(int n);

int main(){
	int n;
	cout << "Enter a positive integer >= 2: ";
	cin >> n;
	
	printDivisors(n);
	return 0;
}


void printDivisors(int n) {
	int i;
	for (i = 1; i <= sqrt(n); i++) {
		if (n % i == 0) cout << i << " ";
	}
	
	if (i - (n / i) == 1) i--;

	for (; i >= 1; i--) {
		if (n % i == 0) cout << n / i << " ";
	}
	cout << endl;
}