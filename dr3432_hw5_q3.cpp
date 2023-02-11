#include <iostream>

using namespace std;

void reverseArray(int arr[], int arrSize);
void removeOdd(int arr[], int& arrSize);
void splitParity(int arr[], int arrSize);
void printArray(int arr[], int arrSize);

int main() {
	int arr1[10] = {9, 2, 14, 12, -3};
	int arr1Size = 5;

	int arr2[10] = {21, 12, 6, 7, 14};
	int arr2Size = 5;

	int arr3[10] = {3, 6, 4, 1, 12};
	int arr3Size = 5;

	reverseArray(arr1, arr1Size);
	printArray(arr1, arr1Size);

	removeOdd(arr2, arr2Size);
	printArray(arr2, arr2Size);

	splitParity(arr3, arr3Size);
	printArray(arr3, arr3Size);

	return 0;
}


void reverseArray(int arr[], int arrSize) {
	int temp;
	for (int i = 0; i < arrSize / 2; i++) {
		temp = arr[i];
		arr[i] = arr[arrSize - i - 1]; 
		arr[arrSize - i - 1] = temp;
	}
}

void removeOdd(int arr[], int& arrSize) {
	int newSize = 0;
	int right = 0;

	while (right < arrSize) {
		if (arr[right] % 2 == 0) {
			arr[newSize] = arr[right];
			newSize++;
		}
		right++;
	}
	arrSize = newSize;
}

void splitParity(int arr[], int arrSize) {
	int left = 0, right = arrSize - 1;
	int temp;
	while (left < right) {
		while (arr[left] % 2 != 0 && left < right) {
			left++;
		}
		while (arr[right] % 2 == 0 && left < right) {
			right--;
		}
		if (left < right) {
			temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;
		}
	}
}

void printArray(int arr[], int arrSize){
	cout << "[ ";
	for (int i = 0; i < arrSize; i++) {
		cout << arr[i] << " ";
	}
	cout << "]" << endl;
}