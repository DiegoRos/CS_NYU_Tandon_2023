#include <iostream>
#include <cmath>
using namespace std;

int main() {
	double a, b, c;
	double discriminant;
	double sol1, sol2;

	cout << "Please enter value of a: ";
	cin >> a;
	cout << "Please enter value of b: ";
	cin >> b;
	cout << "Please enter value of c: ";
	cin >> c;
	cout << endl;

	if (a == 0 && b == 0 && c == 0) {
		cout << "Infinite number of solutions" << endl;
	}

	else if (a == 0 && b == 0 && c != 0) {
		cout << "No solution" << endl;
	}

	else if (a == 0) {
		cout << "1 real solution: \t x = " << -c / b;
	}
	else {
		discriminant = (b * b) - (4 * a * c);

		if (discriminant == 0) { // 1 Solution
			cout << "1 real solution: \t x = " << -(b / (2*a));
		}
		else if (discriminant > 0) { // 2 real solutions
			cout << "2 real solutions: \t x1 = " << (-b + sqrt(discriminant)) / (2 * a)
				<< "  x2 = " << (-b - sqrt(discriminant)) / (2 * a) << endl;
		}
		else {// No real solutions
			cout << "No real solution" << endl;
		}
	}
	cout << endl;
	return 0;
}

