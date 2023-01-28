#include <iostream>
#include <string>

using namespace std;

int main () {
    int inputNum;
    string binString;

    cout << "Please enter a possitive number: " << endl;
    cin >> inputNum;

    int temp;
    while (inputNum > 0) {
        temp = inputNum % 2;
        binString = to_string(temp) + binString;

        inputNum /= 2;

    }

    cout << binString << endl << endl;
    return 0;
}