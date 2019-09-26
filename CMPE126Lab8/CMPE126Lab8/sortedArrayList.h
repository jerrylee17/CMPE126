#ifndef SORTEDARRAYLIST_H_
#define SORTEDARRAYLIST_H_
#include <iostream>
using namespace std;

template <typename elemType>
class sortedArrayList {
private:
	elemType* arr;
	int size;
	int limit;
	int left, right;

public:
	sortedArrayList(int size);
	~sortedArrayList();
	bool isempty() const;
	bool isFull() const;
	int listSize() const;
	int maxListSize() const;
	void print();
	void insert(elemType T);
	void remove(elemType T);
	void doublesize();
	void sort();
	unsigned int binSearchIter(elemType T);
	unsigned int binSearchRec(elemType T, int l, int r);

};
template<class elemType>
sortedArrayList<elemType>::sortedArrayList(int s1) {
	size = 0;
	limit = s1;
	arr = new elemType[limit];
}

template<class elemType>
sortedArrayList<elemType>::~sortedArrayList() {
	delete[] arr;
}

template<class elemType>
bool sortedArrayList<elemType>::isempty() const {
	if (size == 0) return true;
	return false;
}

template<class elemType>
bool sortedArrayList<elemType>::isFull() const {
	if (limit == size) return true;
	return false;
}

template<class elemType>
int sortedArrayList<elemType>::listSize() const {
	return size;
}

template<class elemType>
int sortedArrayList<elemType>::maxListSize() const {
	return limit;
}

template<class elemType>
void sortedArrayList<elemType>::print() {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

template<class elemType>
void sortedArrayList<elemType>::doublesize() {
	limit *= 2;
	elemType* tmp = new elemType[limit];
	for (int i = 0; i < size; i++) {
		tmp[i] = arr[i];
	}
	delete[] arr;
	arr = tmp;
}

template<class elemType>
void sortedArrayList<elemType>::insert(elemType T) {
	if (size == limit) {
		this->doublesize();
	}
	arr[size] = T;
	size++;
	sort();
}

template<class elemType>
void sortedArrayList<elemType>::remove(elemType T) {
	int index = binSearchIter(T);
	for (int i = index; i < size; i++) {
		arr[i] = arr[i + 1];
	}
}

template<class elemType>
void sortedArrayList<elemType>::sort() {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] < arr[j]) {
				elemType tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}

template<class elemType>
unsigned int sortedArrayList<elemType>::binSearchIter(elemType T) {
	int left = 0;
	int right = size - 1;
	int mid = (right + left) / 2;
	while (left < right) {
		
		if (arr[mid] == T) {
			return mid;
		}
		else if (arr[mid] < T) {
			left = mid + 1;
		}
		else if (arr[mid] > T) {
			right = mid - 1;
		}
		mid = (right + left) / 2;
	}
	return -1;
}

template<class elemType>
unsigned int sortedArrayList<elemType>::binSearchRec(elemType T, int l, int r) {
	int mid = (r + l) / 2;
	if (l >= r || r > size) {
		return -1;
	}
	if (arr[mid] == T) {
		return mid;
	}
	else if (arr[mid] < T) {
		binSearchRec(T, mid + 1, r);
	}
	else if (arr[mid] > T) {
		binSearchRec(T, l, mid - 1);
	}
}
#endif