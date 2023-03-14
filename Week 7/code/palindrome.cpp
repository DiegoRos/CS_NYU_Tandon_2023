#include <iostream>
#include <string>

using namespace std;

bool intIsPalindrome(int num);
string intToString(int n);

int main(){
    int n;

	cout << "Please enter a possitive integer: ";
	cin >> n;
    if (n < 0) {
        cout << "Incorrect entry, please try again." << endl;
        return 1;
    }

    if (n / 10  == 0) {
        cout << n << " is a palindrome" << endl;
        return 0;
    } 


	if (intIsPalindrome(n)) cout << n << " is a palindrome" << endl;
	else cout << n << " is not a palindrome" << endl;

	return 0;
}

bool intIsPalindrome(int num){
    string str = intToString(num);
	int n = str.length();
	for (int i = 0; i < n / 2; i++) {
		if (str[i] != str[n - i - 1]) 
			return false;

	}

	return true;
}

string intToString(int n) {
    string ans = "";
    while (n > 0) {
        ans += n % 10;
        n /= 10;
    }
    return ans;
}