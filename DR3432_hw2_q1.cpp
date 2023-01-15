#include <iostream>
using namespace std;

int main() {
	int quarters, dimes, nickels, pennies;

	cout << "Please enter number of coins:" << endl;
	cout << "# of quarters: ";
	cin >> quarters; 
	cout << "# of dimes: ";
	cin >> dimes; 
	cout << "# of nickels: ";
	cin >> nickels; 
	cout << "# of pennies: ";
	cin >> pennies;
		
	int dolars = ((quarters * 25) + (dimes * 10) + (nickels * 5) + (pennies)) / 100;
	int cents = ((quarters * 25) + (dimes * 10) + (nickels * 5) + (pennies)) % 100;
	
	cout << "The total is " << dolars << " dolars and " << cents << " cents" << endl; 
	
	return 0;
}
