#include <iostream>

using namespace std;

void printShiftedTriangle(int n, int m, char symbol);
void printPineTree(int n, char symbol);

int main(){
	int n;
	char symb;

	cout << "Please enter the number of triangles in the pinetree: ";
	cin >> n;

	if (n <= 0) {
		cout << "Incorrect entry, please try again." << endl;
		return -1;
	}

	cout << "Please enter the desired symbol to be used: ";
	cin >> symb;

	printPineTree(n, symb);

	return 0;
}


void printShiftedTriangle(int n, int m, char symbol){
	for (int i = 0; i < n; i++){
		int numChars = (2*i) + 1;
		int numSpaces = m + (n - i - 1);

		for (int j = 0; j < numSpaces; j++) cout << " ";
		for (int j = 0; j < numChars; j++) cout << symbol;
		cout << endl;
	}

}

void printPineTree(int n, char symbol){
	for(int i = 0; i < n; i++) {
		printShiftedTriangle(2 + i, n - i - 1, symbol);
	}

}