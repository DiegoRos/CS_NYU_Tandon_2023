#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

const int STANDARD_NUM_ARR[] = {0, 1, 2, 3,4, 5, 6, 7, 8, 9};
const int POSSIBLE_NUM = 10;
const int PIN_SIZE = 5;
const int PIN = 12345;

bool checkValidInput(int n);
void setRandomArr(int arr[], int arrSize);
bool checkCorrectEntry(int digitPosition, int mixedNum, int mixedArr[]);
bool checkInputedPin(int pin, int mixedArr[]);
void printArray(const int arr[], int arrSize);

int main(){
    srand(time(0));
    int n;
    int mixedArr[POSSIBLE_NUM];
    setRandomArr(mixedArr, POSSIBLE_NUM);

    cout << "Please enter your PIN according to the following mapping: " << endl;
    printArray(STANDARD_NUM_ARR, POSSIBLE_NUM);
    printArray(mixedArr , POSSIBLE_NUM);
    cin >> n;

    if (!checkValidInput(n)) return 1;

    if (checkInputedPin(n, mixedArr)) cout << "Your PIN is correct" << endl;
    else cout << "Your PIN is not correct" << endl;

    return 0;
}

bool checkValidInput(int n) {
    if (n <= 0) {
        cout << "Invalid input, please try again." << endl;
        return false;
    }

    int digitCount = 0, temp = n;
    while (temp > 0) {
        int digit = temp % 10;
        if (digit > 3 || digit < 1) {
            cout << "Invalid input, number different than 1, 2, or 3 entered" << endl;
            return false;
        }
        digitCount++;
        temp /= 10;
    }
    if (digitCount != 5) {
        cout << "Invalid input, PIN entered is not of 5 digits." << endl;
        return false;
    }
    return true;
}

void setRandomArr(int arr[], int arrSize) {
    for (int i = 0; i < arrSize; i++) arr[i] = (rand() % 3) + 1;
}

bool checkCorrectEntry(int digitPosition, int mixedNum, int mixedArr[]) {
    int temp = mixedNum / (int)pow(10, PIN_SIZE - digitPosition - 1);
    int mixedNumDigit =  temp % 10;

    temp = PIN / (int)pow(10, PIN_SIZE - digitPosition - 1);
    int digitPIN = temp % 10;
    
    return mixedArr[digitPIN] == mixedNumDigit; 
}

bool checkInputedPin(int pinTest, int mixedArr[]) {
    for (int i = 0; i < PIN_SIZE; i++) {
        if (!checkCorrectEntry(i, pinTest, mixedArr)) 
            return false;
    }

    return true;
}

void printArray(const int arr[], int arrSize) {
	for (int i = 0; i < arrSize; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}