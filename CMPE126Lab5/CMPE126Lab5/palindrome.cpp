/*#include <iostream>
#include <string>
using namespace std;

bool check_palindrome(const string&s) {
	if (s.length() == 0 || s.length() == 1) {
		return true;
	}
	if (s.back() == s.front()) {
		return check_palindrome(s.substr(1, s.length() - 2));
	}
	return false;
}

void ptest() {
	cout << check_palindrome("racecar");
}*/