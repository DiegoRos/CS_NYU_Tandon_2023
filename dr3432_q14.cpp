/*
    TEST 1 QUESTION 13 
    DIEGO ROSENBERG DE ANGOITIA
    NetID: dr3432
    Email: dr3432@nyu.edu
*/

#include <iostream>

using namespace std;

int checkGroupNum(int n);

int main(){
    int g1 = 0, g2 = 0, g3 = 0, g4 = 0;
    int exitCond = 0;
    unsigned int n; 
    int numGroup;

    cout << "\nPlease enter a sequence of numbers (with at least 1-digit and at most 8-digits), \neach one in a separate line. End your sequence by typing -1:" << endl;
    while (exitCond != -1){
        cin >> n;
        if (n == -1) break;

        numGroup = checkGroupNum(n);
        if (numGroup == 1) g1++;
        else if (numGroup == 2) g2++;
        else if (numGroup == 3) g3++;
        else g4++;
    }
    
    cout << "Total count of numbers in the Numbers Group 1: " << g1 << endl;
    cout << "Total count of numbers in the Numbers Group 2: " << g2 << endl;
    cout << "Total count of numbers in the Numbers Group 3: " << g3 << endl;
    cout << "Total count of numbers in the Numbers Group 4: " << g4 << endl;

    return 0;
}

// Returns an int between 1 and 4 for possible groups.
int checkGroupNum(unsigned int n){
    int sum = 0;
    while (n){
        sum += n % 10; 
        n /= 10;
    }

    if (sum < 10) return 1;
    else if (sum < 20) return 2;
    else if (sum < 30) return 3;
    else return 4;
}