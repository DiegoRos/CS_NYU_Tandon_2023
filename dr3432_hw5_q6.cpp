#include <iostream>
#include <string>

using namespace std;

int findWord(int start, string &str);
bool wordIsNumber(int start, int end, string &str);
void changeWordToX(int start, int end, string &str);

int main(){
	string sentence;

	cout << "Please enter a line of text:" << endl;
	getline(cin, sentence);

	int start = 0, end = 0;
	while (start < sentence.length() && end < sentence.length()) {
		end = findWord(start, sentence);

		if (wordIsNumber(start, end, sentence)) {
			changeWordToX(start, end, sentence);
		}

		start = end + 1;
	}

	cout << endl << sentence << endl << endl;
	return 0;
}


int findWord(int start, string &str) {
	int end, i;
	for (i = start; i < str.length(); i++) {
		if (i == str.length() - 1) {
			end = str.length();
		}
		else if (str[i] == ' ') {
			end = i;
			break;
		}
	}
	return end;
}

bool wordIsNumber(int start, int end, string &str) {
	for(int i = start; i < end; i++) {
		if (isalpha(str[i])) return false;
	}
	return true;
}

void changeWordToX(int start, int end, string &str) {
	for(int i = start; i < end; i++) {
		str[i] = 'x';
	}
}