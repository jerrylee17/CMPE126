#include "myInfixPostfix.h"
#include <iostream>
#include "arrayStack.h"

using namespace std;

int operations(char c) {
	if (c == '*' || c == '/') {
		return 2;
	}
	else if (c == '+' || c == '-') {
		return 1;
	}
	return 0;
}

string myInfixPostfix(string infix) {
	arrayStack<char> tmp;
	string postfix = "";
	tmp.push('|');
	char c;

	cout << "infix: "<< infix << endl;

	int a = 0;
	char op;
	c = infix[a];
	while (c != '=' && a != infix.length()) {
		//check if it's an operator
		if (c == '+' || c == '-' || c == '*' || c == '/') {
			while (tmp.Top() != '(' && tmp.Top() != '|') {
				op = tmp.pop();
				if (operations(op) >= operations(c)) {
					postfix += op; 
					tmp.push(c);
				}
				else {
					tmp.push(op);
					tmp.push(c);
				}
				break;
			}
			if (tmp.Top() == '|' || tmp.Top() == '(') {
				tmp.push(c);
			}
		}else if (c == '(') {
			//check if its open parenthesis
			tmp.push(c);
		}
		else if (c == ')') {
			//check if its closed parenthesis
			while (tmp.Top() != ')' && tmp.Top() != '|') {
				op = tmp.pop();
				postfix += op;
				break;
			}
			tmp.pop();
		}
		else if (c >= 'A' && c <= 'Z'){
			postfix += c;
		}
		
		a++;
		c = infix[a];
	}
	while (tmp.Top() != '|') {
		op = tmp.pop();
		if (op != '(')
			postfix += op;
	}
	cout << "postfix: "<< postfix <<endl;
	return postfix;
}