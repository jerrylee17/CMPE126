
#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include <iostream>
using namespace std;

template <typename elemType>
class HashTable {
private:
	elemType *HT;
	int HTsize;
public:
	HashTable(int x = 10);
	~HashTable();
	void print();
	bool insert(elemType T);
	elemType search(elemType T);
};

template <typename elemType>
HashTable<elemType>::HashTable(int x) {
	HTsize = x;
	HT = new elemType[x];
	for (int i = 0; i < HTsize; i++) {
		HT[i] = NULL;
	}
}

template <typename elemType>
HashTable<elemType>::~HashTable() {
	delete HT;
}

template <typename elemType>
void HashTable<elemType>::print() {
	for (int i = 0; i < HTsize; i++) {
		if (HT[i] != NULL) {
			cout << HT[i] << endl;
		}
	}
}

template <typename elemType>
bool HashTable<elemType>::insert(elemType T) {
	int i = (T % HTsize);
	if (HT[i] == NULL) {
		HT[i] = T;
		return true;
	}
	else {
		for (int j = i; j < HTsize; j++) {
			if (HT[j] == NULL) {
				HT[j] = T;
				return true;
			}
		}
	}
	return false;
}

template <typename elemType>
elemType HashTable<elemType>::search(elemType T) {
	elemType retval = 0;
	for (int i = 0; i < HTsize; i++) {
		if (T == HT[i]) {
			retval = i;
			HT[i] = NULL;
		}
	}
	return retval;
}

#endif