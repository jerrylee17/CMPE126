#include <iostream>
#include "ArrayList.h"

using namespace std;
//exercise 1
unsigned int lucas(unsigned int n) {
	cout << "call lucas(" << n << ")" << endl;
	if (n == 0) {
		throw "No 0th Lucas Number";
	}
	else if (n == 1) {
		cout << "returning 2 from " << n << endl;
		return 2;
	}
	else if (n == 2) {
		cout << "returning 1 from " << n << endl;
		return 1;
	}
	//cout << "zzzreturning " << n - 1 << " from " << n << endl;
	return lucas(n - 1) + lucas(n - 2);
	
}

//exercise 2
bool check_palindrome(const string&s) {
	if (s.length() == 0 || s.length() == 1) {
		return true;
	}
	if (s.back() == s.front()) {
		return check_palindrome(s.substr(1, s.length()-2));
	}
	return false;
}

void ptest() {
	cout << check_palindrome("racecar") << endl;
}

int main() {
	ptest();
	arrayList <int> arr1(10);
	for (int i = 0; i < 10; i++) {
		arr1.insertEnd(i+100);
	}
	cout << arr1.getMin() << endl;
	unsigned int n = 7;
	//cout << "The " << n << "th Lucas number is " << lucas(n) << endl;
	return 0;
}
