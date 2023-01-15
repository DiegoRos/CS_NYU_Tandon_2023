#include <iostream>
using namespace std;

const int DAYS_IN_A_WEEK = 7; 

int main(){
	int daysTraveled;

	cout << "Enter number of days traveled" << endl;
	cin >> daysTraveled;

	cout << daysTraveled << " days are" << daysTraveled / DAYS_IN_A_WEEK  << " weeks and " << daysTraveled % DAYS_IN_A_WEEK << " days." << endl;
	return 0;
}
