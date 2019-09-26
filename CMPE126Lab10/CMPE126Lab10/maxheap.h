#ifndef MAXHEAP_H_
#define MAXHEAP_H_

#include <iostream>
using namespace std;

template <class elemType>
class MaxHeap {
private:
	elemType *array;
	int maxsize;
	int size;
	void heapify(int a, int b);
public:
	MaxHeap(int n = 10);
	~MaxHeap();
	void print();
	int insert(elemType T);
	int search(elemType T);
	void buildHeap();
	void sort();
};

template <class elemType>
MaxHeap<elemType>::MaxHeap(int n) {
	size = 0;
	maxsize = n;
	array = new elemType[maxsize];
}

template <class elemType>
MaxHeap<elemType>::~MaxHeap() {
	delete[] array;
}

template <class elemType>
void MaxHeap<elemType>::print() {
	for (int i = 0; i < size; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}

template <class elemType>
int MaxHeap<elemType>::insert(elemType T) {
	if (size == maxsize) {
		cout << "Full";
		return -1;
	}
	else if (size == 0){
		array[0] = T;
		size++;
		return 0;
	}
	else {
		array[size] = T;
		size++;
		int node = size;
		int parent = (node - 1) / 2;
		while (array[parent] < array[node]) {
			elemType tmp = array[parent];
			array[parent] = array[node];
			array[node] = tmp;
			parent = (node - 1) / 2;
		}
		buildHeap();
		return search(T);
	}
}

template <class elemType>
int MaxHeap<elemType>::search(elemType T) {
	for (int i = 0; i < size; i++) {
		if (array[i] == T) {
			return i;
		}
	}
	return -1;
}

template <class elemType>
void MaxHeap<elemType>::buildHeap() {
	for (int i = size / 2 - 1; i >= 0; i--) {
		heapify(i, size - 1);
	}
}

template <class elemType>
void MaxHeap<elemType>::heapify(int a, int b) {
	int high = 2 * a + 1;
	elemType tmp = array[a];
	while (high <= b) {
		if (high < b) {
			if (array[high] < array[high + 1]) {
				high++;
			}
		}
		if (tmp > array[high]) {
			break;
		}
		else {
			array[a] = array[high];
			a = high;
			high = 2 * a + 1;
		}
	}
	array[a] = tmp;
}

template <class elemType>
void MaxHeap<elemType>::sort() {
	while (size > 0) {
		cout << array[0] << endl;
		array[0] = array[size - 1];
		size--;
		buildHeap();
	}
}

#endif