#include <iostream>

using namespace std;

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize);
int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr);
void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize);
void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr);
void printIntArray(int *arr, int arrSize);
void test1();
void test2();


int main(){
    test1();
    cout << endl;
    test2();

    return 0;
}

void test1() {
    int arr[] = {3, -1, -3, 0, 6, 4};
    int arrSize = 6;
    cout << "Expected ouptut for: "; 
    printIntArray(arr, arrSize);
    cout << "[3, 6, 4]" << endl;

    int outSize;
    int *res = getPosNums1(arr, arrSize, outSize);
    cout << "Result a):" << endl;
    printIntArray(res, outSize);
    cout << endl;

    int *outSize2 = new int;
    int *res2 = getPosNums2(arr, arrSize, outSize2);
    cout << "Result b):" << endl;
    printIntArray(res2, *outSize2);
    cout << endl;

    int outSize3;
    int *res3; 
    getPosNums3(arr, arrSize, res3, outSize3);
    cout << "Result c):" << endl;
    printIntArray(res3, outSize3);
    cout << endl;

    int *outSize4 = new int;
    int **res4 = new int *;
    getPosNums4(arr, arrSize, res4, outSize4);
    cout << "Result d):" << endl;
    printIntArray(*res4, *outSize4);
    cout << endl;

}

void test2() {
    int arr[] = {-5, 6, 7, 8 ,5 ,2, -17, -4, 1};
    int arrSize = 9;
    cout << "Expected ouptut for: "; 
    printIntArray(arr, arrSize);
    cout << "[6, 7, 8, 5, 2, 1]" << endl << endl;
    
    int outSize;
    int *res = getPosNums1(arr, arrSize, outSize);
    cout << "Result a):" << endl;
    printIntArray(res, outSize);
    cout << endl;

    int *outSize2 = new int;
    int *res2 = getPosNums2(arr, arrSize, outSize2);
    cout << "Result b):" << endl;
    printIntArray(res2, *outSize2);
    cout << endl;

    int outSize3;
    int *res3; 
    getPosNums3(arr, arrSize, res3, outSize3);
    cout << "Result c):" << endl;
    printIntArray(res3, outSize3);
    cout << endl;

    int *outSize4 = new int;
    int **res4 = new int *;
    getPosNums4(arr, arrSize, res4, outSize4);
    cout << "Result d):" << endl;
    printIntArray(*res4, *outSize4);
    cout << endl;
}

//a)
int* getPosNums1(int* arr, int arrSize, int& outPosArrSize){
    outPosArrSize = 0;
    int *positiveArr = new int[arrSize];

    for (int i = 0; i < arrSize; i++) 
        if (arr[i] > 0) 
            positiveArr[outPosArrSize++] = arr[i];

    return positiveArr;
}

//b)
int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr){
    *outPosArrSizePtr = 0;
    int *positiveArr = new int[arrSize];

    for (int i = 0; i < arrSize; i++) 
        if (arr[i] > 0) 
            positiveArr[(*outPosArrSizePtr)++] = arr[i];

    return positiveArr;
}

//c)
void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize){
    outPosArrSize = 0;
    outPosArr = new int[arrSize];

    for (int i = 0; i < arrSize; i++) 
        if (arr[i] > 0) 
            outPosArr[outPosArrSize++] = arr[i];
}

//d)
void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr){
    *outPosArrSizePtr = 0;

    int *outPosArr = new int[arrSize];

    for (int i = 0; i < arrSize; i++) 
        if (arr[i] > 0) 
            outPosArr[(*outPosArrSizePtr)++] = arr[i];

    *outPosArrPtr = outPosArr;
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