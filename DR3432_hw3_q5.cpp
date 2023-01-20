#include <iostream>

using namespace std;

const double LB_TO_KG = 0.453592;
const double IN_TO_M = 0.0254;

int main() {
	double weight, height;
	double bmi;

	cout << "Please enter weight (in pounds): ";
	cin >> weight;
	cout << "Please enter height (in inches): ";
	cin >> height;
	cout << endl;

	// Converting to metric
	weight *= LB_TO_KG;
	height *= IN_TO_M;

	bmi = weight / (height * height);

	if (bmi < 18.5) cout << "The weight status is: Underweight" << endl;
	else if (bmi < 25) cout << "The weight status is: Normal" << endl;
	else if (bmi < 30) cout << "The weight status is: Overweight" << endl;
	else cout << "The weight status is: Obese" << endl;
	
	cout << endl;
	return 0;
}

