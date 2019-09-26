#include <iostream>
#include "sortedLinkedList.h"
using namespace std;

int main() {
	linkedList<int> intarr(15);
	linkedList<char> chararr(15);
	linkedList<int> intarr2(15);
	linkedList<int> emptyarr(15);

	//test insert
	for (int i = 0; i < 15; i++) {
		intarr.insert(i);
		chararr.insert(i + 97);
	}

	//check isFull and isEmpty
	cout << chararr.isFull() << " " <<chararr.isEmpty() << endl;
	cout << emptyarr.isFull() << " " << emptyarr.isEmpty() << endl;

	//check listSize and maxListSize
	cout << chararr.listSize() << " " << chararr.maxListSize() << endl;
	cout << emptyarr.listSize() << " " << emptyarr.maxListSize() << endl;

	//check print
	intarr.print();
	chararr.print();

	//check isItemAtEqual
	cout << intarr.isItemAtEqual(5, 5) << " " << intarr.isItemAtEqual(4, 5) << endl;

	//check remove
	intarr.remove(5);
	intarr.print();

	//add element back
	intarr.insert(5);
	intarr.print();

	//check retrieveat
	cout << intarr.retreiveAt(5) << endl;

	//clearlist
	intarr.clearList();
	intarr.print();

	//operator =
	intarr2 = intarr;
	intarr2.print();
	return 0;
}