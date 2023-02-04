#include <iostream>

using namespace std;

int fib(int n);

int main(){
	int n;

	cout << "Please enter a positive integer: ";
	cin >> n;

	cout << fib(n) << endl;

	return 0;
}


int fib (int n){
	if (n <= 1) return 1;

	int prev = 1, temp;
	int ans = 1;

	for (int i = 2; i < n; i++) {
		temp = ans;
		ans = ans + prev;

		prev = temp;
	}

	return ans;
}