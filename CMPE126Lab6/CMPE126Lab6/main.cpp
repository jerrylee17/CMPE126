#include "myInfixPostfix.h"
#include "stlInfixPostfix.h"
using namespace std;

int main() {
	string infix = "A-C+(B-C/(D+C-D)+(A+B)*(C-D))";
	myInfixPostfix(infix);
	stlInfixPostfix(infix);
	string infix2 = "(A+B)*(C-D)";
	myInfixPostfix(infix2);
	stlInfixPostfix(infix2);
	return 0;
}