#include <iostream>

using namespace std;

template<class T>
void selectionSort(T arr[], int arrSize);

template<class T>
void printArr(T arr[], int arrSize) {
    cout << "[";
    for (int i = 0; i < arrSize; i++) {
        if (i == arrSize - 1) cout << arr[i];
        else cout << arr[i] << ", ";
    }
    cout << "]" << endl;
}

int main() {
    int arr[] = {1,5,67,3,25,100,3,5,4,8,9,4,385,351,5111,48};
    int arrSize = 16;

    printArr(arr, arrSize);
    selectionSort(arr, arrSize);
    printArr(arr, arrSize);

    return 0;
}

template<class T>
void selectionSort(T arr[], int arrSize) {
    T minimumVal;
    int positionMin;
    for (int i = 0; i < arrSize; i++){
        minimumVal = arr[i];
        positionMin = i;
        for (int j = i + 1; j < arrSize; j++) {
            if (minimumVal > arr[j]){
                minimumVal = arr[j];
                positionMin = j;
            }
        }

        if (positionMin != i){
            int temp = arr[i];
            arr[i] = minimumVal;
            arr[positionMin] = temp;
        }
    }
}