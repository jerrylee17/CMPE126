#include <iostream>
#include "arrayList.h"
using namespace std;


int main() {
	
	arrayList<int> intarr(15);
	arrayList<char> chararr(15);
	arrayList<int> intarr2(8);
	arrayList<int> emptyarray(15);
	//populate arrays - uses insertEnd/insertAt
	for (int i = 0; i < 15; i++) {
		intarr.insertEnd(i);
		chararr.insertEnd(i + 97);
		intarr2.insertAt(i, i);
	}
	//int array
	intarr.print();
	//char array
	chararr.print();
	intarr2.print();

	//check the booleans
	cout << intarr.isFull() << " " << intarr.isempty() << endl;
	cout << emptyarray.isFull() << " " << emptyarray.isempty() << endl;

	//check listsizes
	cout << intarr.listSize() << " out of " << intarr.maxListSize() << " used\n";

	//check isitematequal
	cout << intarr.isItemAtEqual(4, 4) << " should be true and " << intarr.isItemAtEqual(5, 3) << " should be false.\n";

	//check retrieve
	cout << intarr.retreiveAt(5) << endl;

	//remove element at 1
	intarr.removeAt(1);
	intarr.print();

	intarr.insertAt(2, 5);
	intarr.print();
	
	//check replace
	for (int i = 0; i < 15; i++) {
		intarr.replaceAt(i, i);
	}
	intarr.print();

	//check clearlist
	intarr.clearList();
	intarr.print();
	
	//operator=
	//emptyarray = intarr;
	//cout << "Asdfasdf";
	emptyarray.print();
}