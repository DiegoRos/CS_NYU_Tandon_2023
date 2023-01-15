#include <iostream>
using namespace std;

int main(){
	double x, r;

	cout << "Please enter temperature in Celcius" << endl;
	cin >> x;
	r = (9.0/5.0) * x + 32.0;

	cout <<"The temperature " << x << " in farenheit is: " << r << endl;
	return 0;
}
