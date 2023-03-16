#include <iostream>

using namespace std;

template <class T>
void merge(T v[], int leftstart, int leftend, int rightend);

template<typename T>
void mergeSort(T arr[], int low, int high);

template<typename T>
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
    mergeSort(arr, 0, arrSize - 1);
    printArr(arr, arrSize);

    return 0;
}

template <class T>
void merge(T v[], int leftstart, int leftend, int rightend) {
	int rightstart = leftend + 1;
	int originalstart = leftstart;
    int size = rightend - leftstart + 1;
	int tempstart = 0;
    int *temp;
    temp = new int[size];

	while (leftstart <= leftend && rightstart <= rightend) {
		if (v[leftstart] < v[rightstart])
			temp[tempstart++] = v[leftstart++];
		else
			temp[tempstart++] = v[rightstart++];
	}
	while (leftstart <= leftend) {
			temp[tempstart++] = v[leftstart++];
	}
	while (rightstart <= rightend) {
		temp[tempstart++] = v[rightstart++];
	}

    for (int i = 0; i < size; i++) {
        v[originalstart++] = temp[i];
    }

    delete []temp;
}

template<typename T>
void mergeSort(T arr[], int low, int high){
    int mid;

    if (low == high) return;

    mid = (high + low) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);
    merge(arr, low, mid, high);

}