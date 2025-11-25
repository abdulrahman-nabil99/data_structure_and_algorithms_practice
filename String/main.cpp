#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
void to_lower(char* string) {
	for (int i = 0; string[i] != '\0'; i++) {
		string[i] = (string[i] + 32 > 122) ? string[i] : string[i] + 32;
	}
}
void to_upper(char* string) {
	for (int i = 0; string[i] != '\0'; i++) {
		string[i] = (string[i] - 32 < 65) ? string[i] : string[i] - 32;
	}
}
void toggle_string(char* string) {
	for (int i = 0; string[i] != '\0'; i++) {
		if (string[i] >= 65 && string[i] <= 90) {
			string[i] = (string[i] + 32 > 122) ? string[i] : string[i] + 32;
		}
		else if (string[i] >= 97 && string[i] <= 122) {
			string[i] = (string[i] - 32 < 65) ? string[i] : string[i] - 32;
		}		
	}
}
bool is_palindrome(char* string) {
	int i = 0, lastCharIndex = 0;
	for (lastCharIndex; string[lastCharIndex] != '\0'; lastCharIndex++) {
	}
	lastCharIndex--;
	for (i; i < lastCharIndex; i++, lastCharIndex--) {
		if (string[i] != string[lastCharIndex]) {
			return false;
		}
	}
	return true;
}
void main() {
	char letterArrayString[] = "assa";
	int lenght = 0;
	for (char c : letterArrayString) {
		if (c == '\0')
			break;
		lenght++;
	}
	//to_lower(letterArrayString);
	//cout << letterArrayString << endl;
	//to_upper(letterArrayString);
	//cout << letterArrayString << endl;
	toggle_string(letterArrayString);
	cout << letterArrayString << endl;
	cout << lenght << endl;
	cout << is_palindrome(letterArrayString) << endl;
}