#include <iostream>

using namespace std;

void digitCounterSum(int n, int &digits, int &digitSum);

int main() {
	int n;
	cout << "Please enter a possitve integer n: ";
	cin >> n;
	
	int digits, digitSum;
	digitCounterSum(n, digits, digitSum);

	cout << n << " has " << digits << " digits, and their sum is " << digitSum << endl << endl;
	return 0;
}


void digitCounterSum(int n, int &digits, int &digitSum) {
	digits = 0;
	digitSum = 0;	
	while (n > 0) {
		digitSum += n % 10;
		digits++;
		
		n /= 10;
	}	

	return;
}
