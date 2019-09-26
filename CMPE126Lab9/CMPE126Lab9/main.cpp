#include <iostream>
#include "HashTable.h"
#include "HashTableChaining.h"
using namespace std;

int main() {
	HashTable<int> ht(7);

	cout << "Hash Table Linear probing: " << endl;

	cout << "Insert: " << endl;

	cout << ht.insert(7) << endl;
	cout << ht.insert(13) << endl;
	cout << ht.insert(22) << endl;
	cout << ht.insert(1) << endl;
	cout << ht.insert(134) << endl;
	cout << ht.insert(3) << endl;
	cout << ht.insert(24) << endl;
	cout << "Table after inserting: " << endl;
	ht.print();

	cout << "Remove: " << endl;

	cout << ht.search(6) << endl;
	cout << ht.search(134) << endl;

	cout << "Table after removing:" << endl;
	ht.print();
	/*
	HashTableChaining<int> ht1(7);

	cout << "Hash Table Linear probing: " << endl;

	cout << "Insert: " << endl;

	cout << ht1.insert(7) << endl;
	cout << ht1.insert(13) << endl;
	cout << ht1.insert(22) << endl;
	cout << ht1.insert(1) << endl;
	cout << ht1.insert(134) << endl;
	cout << ht1.insert(3) << endl;
	cout << ht1.insert(24) << endl;
	cout << "Table after inserting: " << endl;
	ht1.print();

	cout << "Remove: " << endl;

	cout << ht1.search(6) << endl;
	cout << ht1.search(134) << endl;

	cout << "Table after removing:" << endl;
	ht1.print();*/

	return 0;
}
