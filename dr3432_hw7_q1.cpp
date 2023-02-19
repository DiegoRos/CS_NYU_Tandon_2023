#include <iostream>
#include <string>
#include <cctype>

using namespace std;

const int LETTERS_IN_ALPHABET = 26;

void countWordsAndLetters(string prompt, int &wordCount, int letterCount[]);
void printResults(int wordCount, int letterCount[]);

int main(){
    string prompt;
    int wordCount;
    int letterCount[LETTERS_IN_ALPHABET];

    cout << "Please enter a line of text: " << endl;
    getline(cin, prompt);
    
    countWordsAndLetters(prompt, wordCount, letterCount);

    printResults(wordCount, letterCount);

    return 0;
}

void countWordsAndLetters(string prompt, int &wordCount, int letterCount[]){
    bool startedWord = false;
    wordCount = 0;
    for (int i = 0; i < LETTERS_IN_ALPHABET; i++) letterCount[i] = 0;

    for (char c : prompt) {
        if (c == ' ' || c == ',' || c == '.') {
            if (startedWord) {
                wordCount++;
                startedWord = false;
            }
        }
        else {
            if (!startedWord) startedWord = true;
            letterCount[tolower(c) - 'a']++;
        }
    }

    if (startedWord) wordCount++;
}

void printResults(int wordCount, int letterCount[]) {
    cout << endl << wordCount << "\twords" << endl << endl;
    
    cout << "Letters: " << endl;
    for (int i = 0; i < LETTERS_IN_ALPHABET; i++)
        if (letterCount[i])
            cout << letterCount[i] << "\t" << char(i + 'a') << endl;
    cout << endl;
}