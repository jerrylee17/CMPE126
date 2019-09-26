#pragma once
/*


*/
#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

// this is my sorted linkedlist data type. i'm removing the sorted functionality so it's just a normal linked list for the purpose of this lab
#include <iostream>
using namespace std;

template <class elemType>
class linkedList {
public:
	struct node {
		elemType dataPoint;
		node *nextNode;
	};
	node *head;
	node *tail;
	node *temp;
	node *bigTemp;
	int size;
	int maxSize;
	linkedList(int);
	linkedList();
	//~linkedList();
	bool isEmpty() const;
	bool isFull() const;
	int listSize() const;
	int maxListSize() const;
	void print();
	bool isItemAtEqual(int, elemType);
	void insert(elemType);
	void remove(elemType);
	elemType retreiveAt(int);
	void clearList();
	void operator=(const linkedList<elemType>);
	bool seqSearchIter(elemType);
	bool seqSearchRec(elemType, node*);
	//void listSorter();
};

template <class elemType>
linkedList<elemType>::linkedList(){
	maxSize = 10;
	size = 0;
	head = NULL;
	tail = NULL;
	temp = NULL;
	//	bigTemp = head;
}

template <class elemType>
linkedList<elemType>::linkedList(int maxSize) : maxSize(maxSize), size(0) {
	head = NULL;
	tail = NULL;
	temp = NULL;
	//	bigTemp = head;
}


// this function is O(1)
template <class elemType>
bool linkedList<elemType>::isEmpty() const {
	return size == 0; // false if current size = 0, true if current size != 0
}

// this function is O(1)
template <class elemType>
bool linkedList<elemType>::isFull() const {
	return size == maxSize; // false if current size != max size, true if current size = max size
}

// this function is O(1)
template <class elemType>
int linkedList<elemType>::listSize() const {
	return size; // returns current size of list
}

// this function is O(1)
template <class elemType>
int linkedList<elemType>::maxListSize() const {
	return maxSize; // returns maximum size of the list
}

// this function is O(n)
template <class elemType>
void linkedList<elemType>::print() {
	temp = head;
	for (int i = 0; i < size; i++) {
		cout << temp->dataPoint << " ";
		temp = temp->nextNode;
	}
	cout << endl;
}

// this function is O(n)
template <class elemType>
bool linkedList<elemType>::isItemAtEqual(int pos, elemType data) {
	temp = head;
	for (int i = 0; i <= pos; i++) { // we're iterating through the list to see if the data at position (pos) is the same
		temp = temp->nextNode;
	}
	return temp->dataPoint == data;
}

// this function is O(n)
template <class elemType>
void linkedList<elemType>::insert(elemType data) {
	if (!isFull()) { // we only want to insert as long as list isn't full
		node *newNode = new node;
		newNode->nextNode = NULL;
		newNode->dataPoint = data;
		if (head != NULL) {
			temp = head;
			while (temp->nextNode != NULL) { // as long as we're not at the end of the list keep iterating
				temp = temp->nextNode;
			}
			temp->nextNode = newNode;
			tail = newNode;
		}
		else {
			head = newNode;
			tail = head;
		}
		size++;
		// listSorter();
	}
}

// this function is O(n)
template <class elemType>
void linkedList<elemType>::remove(elemType data) {
	temp = head;
	while (temp != NULL && temp->dataPoint != data) {
		temp = temp->nextNode;
	}
	tail = temp->nextNode;
	size--;
}

// this function is O(n)
template <class elemType>
elemType linkedList<elemType>::retreiveAt(int pos) {
	if (pos > size) {  // exits user if they enter a position > size
		cout << "error";
		return;
	}
	else {
		for (int i = 0; i < pos; i++) {
			temp = temp->nextNode; // goes up until the pos - 1 and returns what is at position
		}
		return temp->dataPoint;
	}
}

// this function is O(1)
template <class elemType>
void linkedList<elemType>::clearList() {
	size = 0;
	maxSize = 0;
	head = NULL;
	tail = NULL;
}

// this function is O(1)
template <class elemType>
void linkedList<elemType>::operator=(const linkedList<elemType> node1) {
	size = node1.size;
	maxSize = node1.maxSize;
	head = node1.head;
	tail = node1.tail;
}

template <class elemType>
bool linkedList<elemType>::seqSearchIter(elemType e) {
	temp = head;
	for (int i = 0; i < size; i++) {
		if (temp->dataPoint == e)
			return true;
		temp = temp->nextNode;
	}
	return false;
}

template <class elemType>
bool linkedList<elemType>::seqSearchRec(elemType e, node *bigTemp) {
	if (bigTemp->nextNode == NULL)
		return false;
	else if (bigTemp->dataPoint == e)
		return true;
	else {
		//bigTemp = bigTemp->nextNode;
		return seqSearchRec(e, bigTemp->nextNode);
	}
}

#endif