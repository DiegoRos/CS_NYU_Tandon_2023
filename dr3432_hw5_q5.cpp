#include <iostream>
#include <cmath>

using namespace std;

void analyzeDivisors(int n, int &outCountDivs, int &outSumDivs);
bool isPerfect(int num, int sumDivs);
bool isAmicable(int num1, int sumDivs1, int num2, int sumDivs2);

int main(){
	int countDivs1, sumDivs1, countDivs2, sumDivs2;
	int m;

	cout << "Please enter a positive integer >= 2: ";
	cin >> m;
	cout << endl;
	for (int i = 2; i <= m; i++) {
		analyzeDivisors(i, countDivs1, sumDivs1);
		if (isPerfect(i, sumDivs1)) cout << "The number " << i << " is perfect.\n";

	}
	cout << endl << endl;

	cout << "Amicable pairs fround between 2 and " << m << ":" << endl;
	for (int i = 2; i <= m; i++) {
		analyzeDivisors(i, countDivs1, sumDivs1);
		int count = 0;
		for (int j = 2; j <= m; j++){
			analyzeDivisors(j, countDivs2, sumDivs2);
			if (isAmicable(i, sumDivs1, j, sumDivs2)) {
				cout << "( " << i << ", " << j << " ) ";
				count++;
			}
		}

	}
	cout << endl << endl;

	return 0;
}


void analyzeDivisors(int n, int &outCountDivs, int &outSumDivs) {
	int i;
	outCountDivs = 0;
	outSumDivs = 0;
	for (i = 1; i <= sqrt(n); i++) {
		if (n % i == 0) {
			outCountDivs++;
			outSumDivs += i;
			if (i != 1) {
				outCountDivs++;
				outSumDivs += n / i;
			}	
		}
	}
}

bool isPerfect(int num, int sumDivs){
	return num == sumDivs;
}

bool isAmicable(int num1, int sumDivs1, int num2, int sumDivs2){
	return (num1 == sumDivs2 && num2 == sumDivs1 && num1 != num2);
}