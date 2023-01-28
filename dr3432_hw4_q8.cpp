#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
	int correctNum, guess, lower = 1, upper = 100;

	srand(time(0));
	correctNum = (rand() % 100) + 1;

	cout << "I thought of a number between 1 and 100! Try to guess it." << endl;
	for (int i = 0; i < 5; i++) {
		cout << "Range: [" << lower << ", " << upper << "], Number of guesses left: " << 5 - i << endl;
		cout << "Your guess: ";
		cin >> guess;
		
		if (guess == correctNum) {
			cout << "Congrats! You guessed my number in " << i + 1 << " guesses." << endl;
			break;
		}
		else if (i == 4) {
			cout << "Out of guesses! My number is " << correctNum << endl << endl;
		}
		else if (guess < correctNum) {
			cout << "Wrong! My number is bigger" << endl;
			lower = guess + 1;
		}
		else {
			cout << "Wrong! My number is smaller" << endl;
			upper = guess - 1;
		}
	}

	return 0;
}
