#include <iostream>

using namespace std;

const int ARR_SIZE = 20;

int minInArray(int arr[], int arrSize);
void findMinValInArray(int arr[], int arrSize);

int main(){
	int arr[ARR_SIZE];
	cout << "Please enter 20 integers separated by a space: "<< endl;
	for (int i = 0; i < ARR_SIZE; i++)
		cin >> arr[i];

	findMinValInArray(arr, ARR_SIZE);
	
	return 0;
}


int minInArray(int arr[], int arrSize) {
	if (arrSize <= 0) {
		cout << "Empty array or negative size given. Try again." << endl;
		return INT_MIN;
	}

	int minVal = arr[0];
	for (int i = 1; i < arrSize; i++) {
		// Using the ternary operator instead of an if else statement.
		minVal = (minVal > arr[i]) ? arr[i] : minVal;
	}
	return minVal;
}

void findMinValInArray(int arr[], int arrSize){
	int minVal = minInArray(arr, arrSize);

	cout << "The minimum value is " << minVal << ", and it is located in the following indeces: ";
	for (int i = 0; i < arrSize; i++) {
		if (arr[i] == minVal)
			cout << i << " ";
	}
	cout << endl;
}