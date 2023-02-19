#include <iostream>
#include <string>

using namespace std;

string* createWordsArray(string sentence, int& outWordsArrSize);
int countWords(string prompt);
void printStrArray(string *arr, int arrSize);

int main(){
    string *res1;
    int outWordsArrSize1;
    string sentence1 = "You can do it";
    cout << "Prompt: \"" << sentence1 << "\"" << endl;
    cout << "Expected result: [\"You\" , \"can\" , \"do\" , \"it\"]" << endl;
    cout << "Result: " << endl;
    res1 = createWordsArray(sentence1, outWordsArrSize1);
    printStrArray(res1, outWordsArrSize1);

    cout << endl << endl;
    
    string *res2;
    int outWordsArrSize2;
    string sentence2 = "Hi, my name is Bob. My friends, call me B";
    cout << "Prompt: \"" << sentence2 << "\"" << endl;
    cout << "Expected result: [\"Hi\", \"my\", \"name\", \"is\", \"Bob\", \"My\", \"firends\", \"call\", \"me\", \"B\"]" << endl;
    cout << "Result: " << endl;
    res2 = createWordsArray(sentence2, outWordsArrSize2);
    printStrArray(res2, outWordsArrSize2);

    cout << endl << endl;

    return 0;
}

string* createWordsArray(string sentence, int& outWordsArrSize) {
    outWordsArrSize = countWords(sentence);

    string *words = new string[outWordsArrSize];
    int i = 0;

    bool startedWord = false;
    int startWordIndex, wordLenght = 0;
    int counter = 0;
    for (char c : sentence) {
        if (c == ' ' || c == ',' || c == '.'|| c == ';') {
            if (startedWord) {
                startedWord = false;
                words[i++] = sentence.substr(startWordIndex, wordLenght);
                wordLenght = 0;
            }
        }
        else {
            if (!startedWord) {
                startedWord = true;
                startWordIndex = counter;
            }
            wordLenght++;
        }

        counter++;
    }

    if (startedWord) words[i] = sentence.substr(startWordIndex, wordLenght);

    return words;
}

int countWords(const string prompt){
    bool startedWord = false;
    int wordCount = 0;
    for (char c : prompt) {
        if (c == ' ' || c == ',' || c == '.'|| c == ';') {
            if (startedWord) {
                wordCount++;
                startedWord = false;
            }
        }
        else 
            if (!startedWord) startedWord = true;
    }

    if (startedWord) wordCount++;

    return wordCount;
}

void printStrArray(string *arr, int arrSize){
    cout << "[";
    for (int i = 0; i < arrSize; i++) {
        if (i == arrSize - 1)
            cout << "\"" << arr[i] << "\"";

        else 
            cout << "\"" << arr[i] << "\", ";
    }
    cout << "]" << endl;

}