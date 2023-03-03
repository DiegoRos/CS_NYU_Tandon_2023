
/*
    TEST 2 QUESTION 6
    DIEGO ROSENBERG DE ANGOITIA
    NetID: dr3432
    Email: dr3432@nyu.edu
*/

#include <iostream>
#include <vector>

using namespace std;

void mergeSortedArrays(int S1[], int S2[], int n1, int n2, vector<int> &MergedArray);
void printArray(int arr[], int n);
void printVector(vector<int> v);


int main(){
    int S1[] = {-100, -75, -20, 15}, S2[] = {-75, -20, -10, 20};
    vector<int> res1;
    mergeSortedArrays(S1, S2, 4, 4, res1);
    cout << "The result of sorting arrays:" << endl;
    printArray(S1, 4);
    printArray(S2, 4);
    cout << "Is: ";
    printVector(res1);
    cout << endl;
    
    int S3[] = {-1, 5, 15, 17, 26, 44}, S4[] = {-10, 5, 24, 30, 50};
    vector<int> res2;
    mergeSortedArrays(S3, S4, 6, 5, res2);
    cout << "The result of sorting arrays:" << endl;
    printArray(S1, 6);
    printArray(S2, 5);
    cout << "Is: ";
    printVector(res2);
    cout << endl;
    
    int S5[] = {-10, 5, 15}, S6[] = {0, 15, 24, 30, 90};
    vector<int> res3;
    mergeSortedArrays(S5, S6, 3, 5, res3);
    cout << "The result of sorting arrays:" << endl;
    printArray(S5, 3);
    printArray(S6, 5);
    cout << "Is: ";
    printVector(res3);
    cout << endl;

     return 0;
}

void mergeSortedArrays(int S1[], int S2[], int n1, int n2, vector<int> &MergedArray) {
    int i = 0, j = 0;
    while (i < n1 && j < n2) {
        if (S1[i] == S2[j]) {
            MergedArray.push_back(S1[i]);
            i++;
            j++;
        }
        else if(S1[i] < S2[j]) {
            MergedArray.push_back(S1[i]);
            i++;
        }
        else {
            MergedArray.push_back(S2[j]);
            j++;
        }
    }

    while (i < n1) {
        MergedArray.push_back(S1[i++]);
    }

    while (j < n2) {
        MergedArray.push_back(S2[j++]);
    }

    return;
}


void printArray(int arr[], int n){
    cout << "[";
    for (int i = 0; i < n; i++) {
        if (i == n - 1) cout << arr[i];
        else cout << arr[i] << ", ";
    }
    cout << "]" << endl;
}

void printVector(vector<int> v){
    int n = v.size();

    cout << "[";
    for (int i = 0; i < n; i++) {
        if (i == n - 1) cout << v[i];
        else cout << v[i] << ", ";
    }
    cout << "]" << endl;
}
