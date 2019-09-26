#pragma once
#ifndef ARRAYLIST_H_
#define ARRAYLIST_H_
#include <iostream>
using namespace std;

template <typename elemType>
class arrayList {
private:
	elemType* arr;
	int size;
	int limit;
	
public:
	arrayList(int size);
	~arrayList();
	bool isempty() const;
	bool isFull() const;
	int listSize() const;
	int maxListSize() const;
	void print();
	bool isItemAtEqual(int i, elemType T);
	void insertAt(int i, elemType T);
	void insertEnd(elemType T);
	void removeAt(int i);
	elemType retreiveAt(int i);
	void replaceAt(int i, elemType T);
	void clearList();
	arrayList& operator=(const arrayList& T);
	void doublesize();
	
};
template<class elemType>
void arrayList<elemType>::doublesize() {
	limit *= 2;
	elemType* tmp = new elemType[limit];
	for (int i = 0; i < size; i++) {
		tmp[i] = arr[i];
	}
	delete[] arr;
	arr = tmp;
}

template<class elemType>
arrayList<elemType>::arrayList(int s1) {
	size = 0;
	limit = s1;
	arr = new elemType[limit];
}

template<class elemType>
arrayList<elemType>::~arrayList() {
	delete[] arr;
}

template<class elemType>
bool arrayList<elemType>:: isempty() const {
	if (size == 0) return true;
	return false;
}

template<class elemType>
bool arrayList<elemType>:: isFull() const {
	if (limit == size) return true;
	return false;
}

template<class elemType>
int arrayList<elemType>:: maxListSize() const {
	return limit;
}

template<class elemType>
int arrayList<elemType>:: listSize() const {
	return size;
}

template<class elemType>
void arrayList<elemType>:: print() {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

template<class elemType>
bool arrayList<elemType>:: isItemAtEqual(int i, elemType T) {
	if (i >= 0 && i < size && arr[i] == T) return true;
	return false;
}

template<class elemType>
void arrayList<elemType>:: insertAt(int i, elemType T) {
	if (size == limit) {
		this->doublesize();
	}
	if (i<0 || i>size) {
		cout << "error";
	}else{
		for (int j = size; j > i; j--) {
			arr[j] = arr[j - 1];
		}
		arr[i] = T;
		size++;
	}
}

template<class elemType>
void arrayList<elemType>:: insertEnd(elemType T) {
	if (size == limit) {
		this->doublesize();
	}
	arr[size] = T;
	size++;
}

template<class elemType>
void arrayList<elemType>::removeAt(int i) {
	if (i >= 0 && i < size) {
		for (int j = i; j < size; j++) {
			arr[j] = arr[j + 1];
		}
		size--;
	}
}

template<class elemType>
elemType arrayList<elemType>:: retreiveAt(int i) {
	if (i >= 0 && i < size) {
		return arr[i];
	}
}

template<class elemType>
void arrayList<elemType>::replaceAt(int i, elemType T) {
	if (i >= 0 && i < size) {
		arr[i] = T;
	}
}

template<class elemType>
void arrayList<elemType>:: clearList() {
	size = 0;
}

template<class elemType>
arrayList<elemType> &arrayList<elemType>::operator=(const arrayList& T) {
	delete[] arr;
	limit = T.limit;
	size = T.size;
	for (int i = 0; i < size; i++) {
		arr[i] = T.arr[i];
	}

	return *this;
}


#endif