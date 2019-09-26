#include <iostream>
#include <stack>
#include <string>
#include "stlInfixPostfix.h"
#include "myInfixPostfix.h"

using namespace std;

string stlInfixPostfix(string infix) {
	stack<char> tmp;
	string postfix = "";
	tmp.push('|');
	char c;

	cout << "infix: " << infix << endl;

	int a = 0;
	char op;
	c = infix[a];
	while (c != '=' && a != infix.length()) {
		//check if it's an operator
		if (c == '+' || c == '-' || c == '*' || c == '/') {
			while (tmp.top() != '(') {
				op = tmp.top();
				tmp.pop();
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
			if (tmp.top() == '|' || tmp.top() == '(') {
				tmp.push(c);
			}
		}
		else if (c == '(') {
			//check if its open parenthesis
			tmp.push(c);
		}
		else if (c == ')') {
			//check if its closed parenthesis
			while (tmp.top() != ')'&& tmp.top() != '|') {
				op = tmp.top();
				tmp.pop();
				postfix += op;
				break;
			}
			tmp.pop();
		}
		else {
			postfix += c;
		}

		a++;
		c = infix[a];
	}
	while (tmp.top() != '|') {
		op = tmp.top();
		tmp.pop();
		if (op != '(')
			postfix += op;
	}
	cout << "postfix: " << postfix << endl;

	return postfix;
}