#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.14; 

int main(){
	double radius, area;

	cout << "Enter radius" << endl;
	cin >> radius;

	area = radius * M_PI;
	
	cout << "The area of the circle with radius of" << radius << "is: " << area<< endl;
	return 0;
}
