#include <iostream>

using namespace std;

int factorial(int n);

int main() {
	int n, k;
	cout << "Please enter n and k (n >= k): " << endl;
	cin >> n >> k;

	cout << n << " choose " << k << " is " << factorial(n) / (factorial(k) * factorial(n - k)) << endl;
	
	return 0;
}

int factorial(int n) {
	if (n ==  0) return 1;
	int res = 1;

	for (int i = 1; i <= n; i++) res *= i;

	return res;
}
