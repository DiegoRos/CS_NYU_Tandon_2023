#include <iostream>
#include <vector>

using namespace std;

void resize(int *arr, int &oldSize, int newSize);
void main1();
void main2();
void findNums1(int num, int *arr, int arrSize);
void findNums2(int num, vector<int> &arr);


int main(){
    main1();
    cout << endl << endl;
    main2(); 
    return 0;
}

void main1() {
    const int SIZE = 20;
    int *arr = new int[SIZE];
    int arrSize = SIZE;
    int counter = 0;
    int val = 0;
    cout << "Please enter a sequence of positive integers, each in a separate line.\nEnd you input by typing -1." << endl;
    while (val != -1) {
        cin >> val;
        if (val != -1){
            if (counter % SIZE == 0 && counter != 0) resize(arr, arrSize, arrSize + SIZE);
            arr[counter++] = val;
        }
    }

    int num;
    cout << "Please enter the number you want to search: " << endl;
    cin >> num;
    findNums1(num, arr, arrSize);
}

void main2() {
    vector<int> nums;
    int val = 0;
    cout << "Please enter a sequence of positive integers, each in a separate line.\nEnd you input by typing -1." << endl;
    while (val != -1) {
        cin >> val;
        if (val != -1){
            nums.push_back(val);
        }
    }

    int num;
    cout << "Please enter the number you want to search: " << endl;
    cin >> num;
    findNums2(num, nums);
}

void resize(int *arr, int &oldSize, int newSize) {
    int *temp = new int[newSize];
    for (int i = 0; i < oldSize; i++) temp[i] = arr[i];

    delete [] arr;
    arr = temp;
    oldSize = newSize;
}

void findNums1(int num, int *arr, int arrSize) {
    int count = 0;
    cout << num << " shows up in lines: ";
    for (int i = 0; i < arrSize; i++){
        if (arr[i] == num) {
            if (count != 0) cout << ", ";
            count++;
            cout << i + 1;
        }
    }
    if (!count) cout << "NONE";
    cout << "." << endl;
}

void findNums2(int num, vector<int> &arr) {
    int count = 0;
    cout << num << " shows up in lines: ";
    for (int i = 0; i < arr.size(); i++){
        if (arr[i] == num) {
            if (count != 0) cout << ", ";
            count++;
            cout << i + 1;
        }
    }
    if (!count) cout << "NONE";
    cout << "." << endl;
}