#include <iostream>


using namespace std;

int main() {
	int inputNum;
    cout << "Please enter a possitive number: ";
    cin >> inputNum;
    cout << endl;
    int totalSpaces = ((inputNum - 1) * 2) + 1; 
    
    for (int i = inputNum - 1; i >= 0; i--) {
        int numAsterisk = (i * 2) + 1;

        for (int j = 0; j < (totalSpaces - numAsterisk)/2; j++)
            cout << " ";

        for (int k = 0; k < numAsterisk; k++)
            cout << "*";

        cout << endl;
    }

    for (int i = 1; i < inputNum; i++) {
        int numAsterisk = (i * 2) + 1;

        for (int j = 0; j < (totalSpaces - numAsterisk)/2; j++)
            cout << " ";

        for (int k = 0; k < numAsterisk; k++)
            cout << "*";

        cout << endl;
    }

	return 0;
}
