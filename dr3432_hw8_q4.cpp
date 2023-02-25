#include <iostream>

using namespace std;

int lowestJumpIt(int arr[], int arrSize);
int min(int n1, int n2);
void printArray(int arr[], int arrSize);

int main() {
    int arr1[] = {0, 3, 80, 6, 57, 10};
    int arrSize1 = 6;

    int arr2[] = {0, 3, 50, 80, 6, 7, 57, 17, 2, 10};
    int arrSize2 = 10;


    //Tests
    cout << "For game: ";
    printArray(arr1, arrSize1);
    cout << "The minimum score is: " << lowestJumpIt(arr1, arrSize1) << endl;
    cout << endl;

    cout << "For game: ";
    printArray(arr2, arrSize2);
    cout << "The minimum score is: " << lowestJumpIt(arr2, arrSize2) << endl;
    cout << endl;
    
    return 0;
}

int lowestJumpIt(int arr[], int arrSize) {
    if (arrSize <= 2) {
        return arr[arrSize - 1];
    }

    return arr[arrSize - 1] + min(lowestJumpIt(arr, arrSize - 1), lowestJumpIt(arr, arrSize - 2));
}

// Returns minimum of two numbers
int min(int n1, int n2) {
    // Using ternary operator to simplify code.
    return ((n1 < n2) ? n1 : n2);
}

void printArray(int arr[], int arrSize) {
    cout << "[";
    for (int i = 0; i < arrSize; i++) {
        if (i == arrSize - 1) cout << arr[i];
        else cout << arr[i] << ", ";
    }
    cout << "]" << endl;
}