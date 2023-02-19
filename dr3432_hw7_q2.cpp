#include <iostream>
#include <string>
#include <cctype>

using namespace std;

const int LETTERS_IN_ALPHABET = 26;

void countLetters(string prompt, int letterCount[]);
bool isAnagram(int letterCount1[], int letterCount2[]);

int main(){
    string prompt1, prompt2;
    int wordCount;
    int letterCount1[LETTERS_IN_ALPHABET];
    int letterCount2[LETTERS_IN_ALPHABET];

    cout << "Please enter the first line of text: " << endl;
    getline(cin, prompt1);
    cout << endl;

    cout << "Please enter the second line of text: " << endl;
    getline(cin, prompt2);
    cout << endl;


    countLetters(prompt1, letterCount1);
    countLetters(prompt2, letterCount2);

    if (isAnagram(letterCount1, letterCount2)) cout << "The strings:\n\"" << prompt1 << "\"\n\tand \n\"" << prompt2 << "\"\n\nAre an anagram" << endl << endl;
    else cout << "The strings:\n\"" << prompt1 << "\"\n\tand \n\"" << prompt2 << "\n\nAre not anagram" << endl << endl;

    return 0;
}

void countLetters(string prompt, int letterCount[]){
    bool startedWord = false;
    for (int i = 0; i < LETTERS_IN_ALPHABET; i++) letterCount[i] = 0;

    for (char c : prompt)
        if (isalpha(c)) 
            letterCount[tolower(c) - 'a']++;
}

bool isAnagram(int letterCount1[], int letterCount2[]) {
    for (int i = 0; i < LETTERS_IN_ALPHABET; i++) {
        if (letterCount1[i] != letterCount2[i]) return false;
    }

    return true;
}