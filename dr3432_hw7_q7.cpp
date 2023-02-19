#include <iostream>

using namespace std;

int* findMissing(int arr[], int n, int& resArrSize);
void printIntArray(int *arr, int arrSize);

int main(){
    int arr1[] = {3, 1, 3, 0, 6, 4};
    int n1 = 6;
    cout << "Expected ouptut for: "; 
    printIntArray(arr1, n1);
    cout << "Is:\n[2, 5]" << endl;
    int resArrSize1;
    int *ans1 = findMissing(arr1, n1, resArrSize1);
    cout << endl << "Result:" << endl;
    printIntArray(ans1, resArrSize1);

    cout << endl << endl;
    int arr2[] = {0, 1, 2, 3, 4};
    int n2 = 5;
    cout << "Expected ouptut for: "; 
    printIntArray(arr2, n2);
    cout << "Is:\n[5]" << endl;
    int resArrSize2;
    int *ans2 = findMissing(arr2, n2, resArrSize2);
    cout << endl << "Result:" << endl;
    printIntArray(ans2, resArrSize2);

    cout << endl << endl;
    int arr3[] = {3, 1, 5, 8, 9, 9, 9, 10, 11, 5, 2, 4};
    int n3 = 12;
    cout << "Expected ouptut for: "; 
    printIntArray(arr3, n3);
    cout << "Is:\n[0, 6, 7, 12]" << endl;
    int resArrSize3;
    int *ans3 = findMissing(arr3, n3, resArrSize3);
    cout << endl << "Result:" << endl;
    printIntArray(ans3, resArrSize3);


    return 0;
}

int* findMissing(int arr[], int n, int& resArrSize) {
    int *ans = new int[n + 1];
    bool *seen = new bool[n + 1];
    for (int i = 0; i <= n; i++) seen[i] = false;

    for (int i = 0; i <= n; i++) seen[arr[i]] = true;

    resArrSize = 0;
    for (int i = 0; i <= n; i++)
        if (!seen[i])
            ans[resArrSize++] = i;

    return ans;
}   

void printIntArray(int *arr, int arrSize){
    cout << "[";
    for (int i = 0; i < arrSize; i++) {
        if (i == arrSize - 1)
            cout << arr[i];

        else 
            cout << arr[i] << ", ";
    }
    cout << "]" << endl;

}