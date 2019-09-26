#pragma once
#ifndef linkedList_H_
#define linkedList_H_
#include <iostream>
using namespace std;


template <typename elemType>
class linkedList {
private:
	struct node {
		elemType element;
		node* next;
	};
	
	node* tail;
	node* tmp;
	int size;
	int sizelimit;

public:
	node* head;
	linkedList();
	linkedList(int i);
	~linkedList();
	bool isEmpty() const;
	bool isFull() const;
	int listSize() const;
	int maxListSize() const;
	void print();
	bool isItemAtEqual(int i, elemType T);
	void insert(elemType T);
	void remove(elemType T);
	elemType retreiveAt(int i);
	void clearList();
	void operator=(const linkedList& T);
	void sortList();

	bool seqSearchIter(elemType T);
	bool seqSearchRec(elemType T, node *temp);
	bool binSearchIter(elemType T);
	bool binSearchRec(elemType T);
};

template <typename elemType>
bool linkedList<elemType>::seqSearchIter(elemType T) {
	tmp = head;
	for (int i = 0; i < size; i++) {
		if ((tmp->element) == T) {
			return true;
		}
		tmp = tmp->next;
	}
	return false;
}

template <typename elemType>
bool linkedList<elemType>::seqSearchRec(elemType T, node *temp) {
	if (temp->next == NULL)
		return false;
	else if (temp->element == T)
		return true;
	else {
		return seqSearchRec(T, temp->next);
	}
}

template <typename elemType>
bool linkedList<elemType>::binSearchIter(elemType T) {
	return false;
}

template <typename elemType>
bool linkedList<elemType>::binSearchRec(elemType T) {
	return false;
}

template <typename elemType>
void linkedList<elemType>::sortList() {
	tail = head;
	while (tail->next != NULL) {
		if (tail->next->element < tail->element) {
			elemType T = tail->element;
			tail->element = tail->next->element;
			tail->next->element = T;
			tail = head;
		}
		tail = tail->next;
	}
}

template <typename elemType>
linkedList<elemType>::linkedList() {
	head = NULL;
	size = 0;
}

template <typename elemType>
linkedList<elemType>::linkedList(int i) {
	sizelimit = i;
	size = 0;
	head = NULL;
	tail = NULL;
	tmp = NULL;
}

template <typename elemType>
linkedList<elemType>::~linkedList() {
	node *next = head;
	while (next) {
		node *kill = next;
		next = next->next;
		delete kill;
	}
}

template <typename elemType>
bool linkedList<elemType>::isEmpty() const {
	return (size == 0);
}

template <typename elemType>
bool linkedList<elemType>::isFull() const {
	return (size == sizelimit);
}

template <typename elemType>
int linkedList<elemType>::listSize() const {
	return size;
}

template <typename elemType>
int linkedList<elemType>::maxListSize() const {
	return sizelimit;
}

template <typename elemType>
void linkedList<elemType>::print() {
	tmp = head;
	for (int i = 0; i < size; i++) {
		cout << (tmp->element) << " ";
		tmp = tmp->next;
	}
	cout << endl;
}

template <typename elemType>
bool linkedList<elemType>::isItemAtEqual(int i, elemType T) {
	tmp = head;
	for (int j = 0; j < i; j++) {
		tmp = tmp->next;
	}
	return (tmp->element == T);
}

template <typename elemType>
void linkedList<elemType>::insert(elemType T) {
	if (!isFull()) {
		node *n = new node;
		n->next = NULL;
		n->element = T;
		if (head != NULL) {
			tail = head;
			while (tail->next != NULL) {
				tmp = tail;
				tail = tail->next;
			}
			tail->next = n;
		}
		else {
			head = n;
		}
		size++;
		sortList();
	}
}

template <typename elemType>
void linkedList<elemType>::remove(elemType T) {
	tail = head;
	while ((tail != NULL) && (tail->element != T)) {
		tmp = tail;
		tail = tail->next;
	}
	tail = tail->next;
	tmp->next = tail;
	size--;
}

template <typename elemType>
elemType linkedList<elemType>::retreiveAt(int i) {
	if (i < size) {
		tmp = head;
		for (int j = 0; j < i; j++) {
			tmp = tmp->next;
		}
		return tmp->element;
	}
	return -1;
}

template <typename elemType>
void linkedList<elemType>::clearList() {
	size = 0;
}

template <typename elemType>
void linkedList<elemType>::operator=(const linkedList<elemType>& T) {
	size = T.size;
	sizelimit = T.sizelimit;
	head = T.head;
	tail = T.tail;
}

#endif