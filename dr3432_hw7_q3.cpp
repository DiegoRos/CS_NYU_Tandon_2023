#include <iostream>

using namespace std;

void oddsKeeyEvensFlip(int arr[], int arrSize);
void printIntArray(int arr[], int arrSize);


int main(){
    int arr1[] = {5,2,11,7,6,4};
    int sizeArr1 = 6;

    oddsKeeyEvensFlip(arr1, sizeArr1);
    printIntArray(arr1, sizeArr1);
    cout << "Expected result: [5, 11, 7, 4, 6, 2]" << endl; 
    
    cout << endl << endl;

    int arr2[] = {5,2,11,7,6,4, 17, 20};
    int sizeArr2 = 8;

    oddsKeeyEvensFlip(arr2, sizeArr2);
    printIntArray(arr2, sizeArr2);
    cout << "Expected result: [5, 11, 7, 17, 20, 4, 6, 2]" << endl; 
    
    cout << endl << endl;

    int arr3[] = {2, 5};
    int sizeArr3 = 2;

    oddsKeeyEvensFlip(arr3, sizeArr3);
    printIntArray(arr3, sizeArr3);
    cout << "Expected result: [5, 2]" << endl; 
    
    cout << endl << endl;

    int arr4[] = {1,2,3,4,5,6,5,2,11,7,6,4, 17, 20};
    int sizeArr4 = 14;

    oddsKeeyEvensFlip(arr4, sizeArr4);
    printIntArray(arr4, sizeArr4);
    cout << "Expected result: [1, 3, 5, 5, 11, 7, 17, 20, 4, 6, 2, 6, 4, 2]" << endl; 

    cout << endl;
    return 0;
}

void oddsKeeyEvensFlip(int arr[], int arrSize){
    int *tempArr = new int[arrSize];
    for (int i = 0; i < arrSize; i++) tempArr[i] = arr[i];

	int oddIndex = 0; 
    int evenIndex = arrSize - 1;
	for (int i = 0; i < arrSize; i++) {
        if (tempArr[i] % 2 != 0)
            arr[oddIndex++] = tempArr[i];
        else 
            arr[evenIndex--] = tempArr[i];
    }

    delete [] tempArr;
}

void printIntArray(int arr[], int arrSize){
    cout << "[";
    for (int i = 0; i < arrSize; i++) {
        if (i == arrSize - 1)
            cout << arr[i];

        else 
            cout << arr[i] << ", ";
    }
    cout << "]" << endl;

}
