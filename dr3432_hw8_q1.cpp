#include <iostream>

using namespace std;

void printTriangle(int n);
void printOpositeTriangles(int n);
void printRuler(int n);


int main() {
    cout << "a)" << endl;
    printTriangle(4);

    cout << endl << endl;
    
    cout << "b)" << endl;
    printOpositeTriangles(4);

    cout << endl << endl;

    cout << "c)" << endl;
    printRuler(4);

    cout << endl << endl;
    return 0;
}


void printTriangle(int n) {
    if (n == 1) {
        cout << "*" << endl;
        return;
    }
    printTriangle(n - 1);
    for (int i = 0; i < n; i++) cout << "*";
    cout << endl;

}

void printOpositeTriangles(int n) {
    if (n == 1) {
        cout << "*" << endl << "*" << endl;
        return;
    }
    for (int i = 0; i < n; i++) cout << "*";
    cout << endl;
    printOpositeTriangles(n - 1);
    for (int i = 0; i < n; i++) cout << "*";
    cout << endl;
}

void printRuler(int n) {
    if (n == 1) {
        cout << "-" << endl;
        return;
    }
    printRuler(n - 1);
    for (int i = 0; i < n; i++) cout << "-";
    cout << endl;
    printRuler(n - 1);
}
