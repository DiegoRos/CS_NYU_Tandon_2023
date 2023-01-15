#include <iostream>
using namespace std;

int main() {
	int dolars, cents;
	cout << "Please enter your amount in the format of dollars and cents separated by a space:"	<< endl;
	cin >> dolars >> cents;

	int total = (dolars * 100) + cents;
	
	int quarters, dimes, nickels, pennies;
	
	quarters = total / 25;
	total %= 25;
	
	dimes = total / 10;
	total %= 10;

	nickels = total / 5;
	total %= 5;

	pennies = total;

	cout << quarters << " quarters, " << dimes << " dimes, " << nickels << " nickels, and " << pennies << " pennies"; 
		
	return 0;
}
