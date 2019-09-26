#include <iostream>
#include "ArrayQueue.h"
using namespace std;

int main() {
	int c = 0;
	arrayQueue<int> arr1(10);
	arr1.enqueue(10);
	arr1.enqueue(2);
	arr1.dequeue();

	cout << "Get first element: " << arr1.getFront() << endl;
	cout << "IsEmpty: " << arr1.isEmpty() << endl;
	cout << "IsFull: " << arr1.isFull() << endl;
	cout << "Dequeue:" << arr1.dequeue() << endl;
	cout << "Empty: " << arr1.isEmpty() << endl;

	return 0;
}