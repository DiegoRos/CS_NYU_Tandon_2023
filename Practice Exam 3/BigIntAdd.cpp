#include <iostream>
#include <vector>
#include <cctype>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

const string FILE1 = "num1.txt";
const string FILE2 = "num2.txt";
const string RESULTFILE = "Result.txt";

void getLargeNum(string fileName, vector<int>& num);
void addLargeNum(const vector<int> num1, const vector<int> num2, vector<int> &result);
void printToFile(string fileName, const vector<int> res, int lineSeparator = 25);


int main() {
    vector<int> num1;
    vector<int> num2;
    vector<int> result;

    getLargeNum(FILE1, num1);
    getLargeNum(FILE2, num2);

    addLargeNum(num1, num2, result);

    printToFile(RESULTFILE, result);

    return 0;
}


void getLargeNum(string fileName, vector<int>& num) {
    ifstream file;
    file.open(fileName);
    char c;
    //Add while loop to check
    while (file >> c) {
        if (isdigit(c))
            num.push_back(int(c - '0'));
    }
    file.close();
}

void addLargeNum(const vector<int> num1, const vector<int> num2, vector<int> &result) {
    int carry = 0, digit, sum;
    int i = num1.size() - 1, j = num2.size() - 1;

    while (i >= 0 && j >= 0) {
        sum = num1[i--] + num2[j--] + carry;
        digit = (sum % 10);
        carry = sum / 10;

        result.push_back(digit);
    }

    while (i >= 0) {
        sum = num1[i--] + carry;
        digit = (sum % 10);
        carry = sum - digit;
        result.push_back(digit);
    }

    while (j >= 0) {
        sum = num2[j--] + carry;
        digit = (sum % 10);
        carry = sum - digit;
        result.push_back(digit);
    }

    // Could write a reverse function but this is faster for this practice
    reverse(result.begin(), result.end());
}

void printToFile(string fileName, const vector<int> res, int lineSeparator) {
    ofstream file;
    file.open(fileName);

    for (int i = 0; i < res.size(); i++) {
        if (((i + 1) % lineSeparator) == 0)
            file << endl;
        file << res[i];
    }
}
