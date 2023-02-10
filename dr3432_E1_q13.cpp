/*
    TEST 1 QUESTION 12 
    DIEGO ROSENBERG DE ANGOITIA
    NetID: dr3432
    Email: dr3432@nyu.edu
*/

#include <iostream>

using namespace std;

int main(){
    int n;
    cout << "Please enter a positive integer: \n";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid entry, please try again" << endl;
        return -1;
    }

    for (int i = 0; i < 2 * n; i++){
        for (int j = 1 + i; j < 2 * n; j++) cout << " ";

        for (int j = 0; j < i + 1; j++) cout << "*";
        cout << endl;
    }
    cout << endl;

    return 0;
}