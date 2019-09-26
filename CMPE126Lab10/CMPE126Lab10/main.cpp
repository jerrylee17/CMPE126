
#include <iostream>
#include "maxheap.h"
using namespace std;

int main() {
	MaxHeap<int> heap1(10);
	cout << heap1.insert(5) << endl;
	heap1.print();
	cout << heap1.insert(7) << endl;
	heap1.print();
	cout << heap1.insert(80) << endl;
	heap1.print();
	cout << heap1.insert(50) << endl;
	heap1.print();
	cout << heap1.insert(-3) << endl;
	heap1.print();
	cout << heap1.insert(10) << endl;
	heap1.print();
	cout << heap1.insert(2) << endl;
	heap1.print();
	cout << "Final Heap: ";
	heap1.buildHeap();
	heap1.print();
	cout << "80 is at index " << heap1.search(80) << endl;
	cout << "7 is at index " << heap1.search(7) << endl;
	heap1.sort();
	return 0;
}
