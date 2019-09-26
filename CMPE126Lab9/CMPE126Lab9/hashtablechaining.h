/*
 * HashTableChaining.h
 *
 *  Created on: Apr 16, 2019
 *      Author: davin
 */

#ifndef HASHTABLECHAINING_H_
#define HASHTABLECHAINING_H_

#include <iostream>
#include "LinkedList.h"
using namespace std;

template <typename elemType>
class HashTableChaining {
public:
	HashTableChaining(int x);
	~HashTableChaining();
	void print();
	bool insert(elemType T);
	elemType search(elemType T);
private:
	int HTsize;
	linkedList<elemType> *HT;
};

template <typename elemType>

HashTableChaining<elemType>::HashTableChaining(int x) {
	HTsize = x;
	HT = new linkedList<elemType>[HTsize];
}

template <typename elemType>

HashTableChaining<elemType>::~HashTableChaining() {
	delete[]HT;
}

template <typename elemType>

void HashTableChaining<elemType>::print() {
	for (int i = 0; i < HTsize; i++) {
		cout << "Bucket " << i << ": ";
		HT[i].print();
	}
}

template <typename elemType>

bool HashTableChaining<elemType>::insert(elemType T) {
	int i = (T % HTsize);
	if (!HT[i].seqSearchIter(T)) {
		HT[i].insert(T);
		return true;
	}
	return false;
}

template <typename elemType>

elemType HashTableChaining<elemType>::search(elemType T) {
	int i = (T % HTsize);
	elemType tmp = -1;
	if (HT[i].seqSearchIter(T)) {
		tmp = T;
		HT[i].remove(T);
	}
	return tmp;
}
#endif /* HASHTABLECHAINING_H_ */
