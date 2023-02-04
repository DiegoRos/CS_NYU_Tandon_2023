#include <iostream>

using namespace std;

double eApprox(int n);

int main(){
	cout.precision(30);

	for (int n = 1; n <= 15; n++) {
		cout<<"n = "<<n<<'\t'<<eApprox(n)<<endl;
	}

	return 0;
}

double eApprox(int n){
	double e = 1;
	double factorial = 1;

	for (int i = 0; i < n; i++) {
		factorial *= (i + 1);
		e += 1.0 / factorial;
	}

	return e;
}