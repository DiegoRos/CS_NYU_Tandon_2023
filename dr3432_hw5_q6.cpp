#include <iostream>

using namespace std;

double eApprox(int n);

int main(){
	cout.precision(30);
	int n;

	cout << "Enter a positive integer to indicate precision desired: ";
	cin >> n;
	if (n <= 0) {
		cout << "Incorrect entry, please try again." << endl;
		return -1;
	}

	cout<<"For precision: n = " << n << "\te = " << eApprox(n)<<endl;

	return 0;
}

double eApprox(int n){
	double e = 1;
	double factorial = 1;

	for (int i = 1; i <= n; i++) {
		factorial *= i;
		e += 1.0 / factorial;
	}

	return e;
}