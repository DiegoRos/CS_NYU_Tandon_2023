#include <iostream>

using namespace std;

int sumOfSquares(int arr[], int arrSize);
bool isSorted(int arr[], int arrSize);
void printArray(int arr[], int arrSize);

int main() {
    int arr1[] = {2, -1, 3, 10};
    int arrSize1 = 4;

    int arr2[] = {1, 2, 2, 3, 4, 5, 6, 10};
    int arrSize2 = 8;

    //Tests
    cout << "a)" << endl;
    cout << "For array: ";
    printArray(arr1, arrSize1);
    cout << "The sum of squares is: " << sumOfSquares(arr1, arrSize1) << endl;

    cout << "For array: ";
    printArray(arr2, arrSize2);
    cout << "The sum of squares is: " << sumOfSquares(arr2, arrSize2) << endl;


    cout << "b)" << endl;
    cout << "The array: ";
    printArray(arr1, arrSize1);
    cout << "Is sorted: " << isSorted(arr1, arrSize1) << endl;

    cout << "The array: ";
    printArray(arr2, arrSize2);
    cout << "Is sorted: " << isSorted(arr2, arrSize2) << endl;

    return 0;
}


int sumOfSquares(int arr[], int arrSize) {
    if (arrSize == 1) {
        return arr[arrSize - 1] * arr[arrSize - 1];
    }
    return (arr[arrSize - 1] * arr[arrSize - 1]) + sumOfSquares(arr, arrSize - 1);
}

bool isSorted(int arr[], int arrSize) {
    if (arrSize <= 1) {
        return true;
    }
    
    if (arr[arrSize - 1] < arr[arrSize - 2])
        return false;

    return isSorted(arr, arrSize - 1);
}

void printArray(int arr[], int arrSize) {
    cout << "[";
    for (int i = 0; i < arrSize; i++) {
        if (i == arrSize - 1) cout << arr[i];
        else cout << arr[i] << ", ";
    }
    cout << "]" << endl;
}