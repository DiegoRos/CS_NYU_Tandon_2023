#include <iostream>
#include <cctype>

using namespace std;

int main() {
	double price1, price2;
	char clubCardTemp;
	bool clubCard;
	double taxRate;
	double priceBeforeTax;

	cout << "Enter price of first item: ";
	cin >> price1;

	cout << "Enter price of second item: ";
	cin >> price2;
	
	cout << "Does the customer have a club card? (Y/N): ";
	cin >> clubCardTemp;
	clubCard = (toupper(clubCardTemp) == 'Y');
	
	cout << "Enter tax rate, e.g. 5.5 for 5.5% tax: ";
	cin >> taxRate;

	cout << "\nBase price: " << price1 + price2 << endl;
	if (price1 < price2) {
		priceBeforeTax = ((price1 * 0.5) + price2) * (1 - (clubCard * 0.1));
		cout << "Price after discounts: " << priceBeforeTax << endl;
	}
	else {
		priceBeforeTax = ((price2 * 0.5) + price1) * (1 - (clubCard * 0.1));
		cout << "Price after discounts: " << priceBeforeTax << endl;
	}

	cout << "Total Price: " << priceBeforeTax * (1 + (taxRate/100)) << endl;

	return 0;
}

