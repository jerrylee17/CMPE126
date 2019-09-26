#include <iostream>
#include "arrayList.h"
#include "sortedArrayList.h"
#include "linkedListList.h"

using namespace std;

int main() {
	arrayList<int> arr1(15);
	sortedArrayList<int> arr2(15);
	linkedList<int> arr3(15);
	for (int i = 0; i < 15; i++) {
		arr1.insertEnd(i);
		arr2.insert(i);
		arr3.insert(i);
	}
	cout << "seq search iter: " << arr1.seqSearchIter(5) << endl;
	cout << "seq search rec: " << arr1.seqSearchRec(5) << endl;
	arr2.print();
	cout << "bin search iter: " << arr2.binSearchIter(5) << endl;
	cout << "bin search rec: " << arr2.binSearchRec(5,0, arr2.listSize()) << endl;
	cout << "seq linkedlist: " << arr3.seqSearchIter(5) << endl;
	cout << "seq linkedlist rec: " << arr3.seqSearchRec(5, arr3.head) << endl;
	return 0;
}