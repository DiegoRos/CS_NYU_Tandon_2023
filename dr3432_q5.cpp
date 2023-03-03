/*
    TEST 2 QUESTION 5
    DIEGO ROSENBERG DE ANGOITIA
    NetID: dr3432
    Email: dr3432@nyu.edu
*/

#include <iostream>


using namespace std;

int findMaxElement(int S[], int length, int &frequencyOfMax);

int main(){
    int S[] = {100, -75, 100, 85, 8, 100, 85, -10};
    int frequencyOfMax;
    int val = findMaxElement(S, 8, frequencyOfMax);
    cout << "Maximum: " << val << " with frequency: " << frequencyOfMax << endl;

    cout << endl;


    int S2[] = {-1, -5, -70, -15, -26, -44, 0, 5, -14, -3};
    val = findMaxElement(S2, 10, frequencyOfMax);
    cout << "Maximum: " << val << " with frequency: " << frequencyOfMax << endl;

    cout << endl;

    int S3[] = {-87, 10, 199, 199, 30, -40, -4, 199, 199, -78, 5};
    val = findMaxElement(S3, 11, frequencyOfMax);
    cout << "Maximum: " << val << " with frequency: " << frequencyOfMax << endl;

    cout << endl;

    return 0;
}


int findMaxElement(int S[], int length, int &frequencyOfMax) {
    if (length == 1) {
        frequencyOfMax = 1;
        return S[length - 1];
    }

    int curMax = findMaxElement(S, length - 1, frequencyOfMax);

    if (S[length - 1] == curMax) {
        frequencyOfMax++;
        return curMax;
    }
    else if (S[length - 1] > curMax) {
        frequencyOfMax = 1;
        return S[length - 1];
    }
    else 
        return curMax;

}