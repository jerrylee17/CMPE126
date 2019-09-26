#ifndef arrayQueue_H_
#define arrayQueue_H_
using namespace std;

template <typename elemType>
class arrayQueue {
private:
	elemType* arr;
	//int arrsize;	//number of filled stuff
	int arrlimit;	//max size of array
	int front;		//index of first element
	int back;		//index of space after last eleemnt
public:
	arrayQueue(int = 10);
	~arrayQueue();
	void enqueue(elemType T);
	elemType dequeue();
	int size() const;
	int maxsize() const;
	bool isEmpty() const;
	bool isFull() const;
	elemType getFront() const;
	void doublesize();
};


template<class elemType>
arrayQueue<elemType>::arrayQueue(int n) {
	front = 0;
	back = 0;
	arrlimit = n;
	arr = new elemType[arrlimit];
}

template<class elemType>
arrayQueue<elemType>::~arrayQueue() {
	delete[] arr;
}

template<class elemType>
void arrayQueue<elemType>::enqueue(elemType T) {
	if (isFull()) {
		doublesize();
	}
	arr[back] = T;
	back++;
}

template<class elemType>
elemType arrayQueue<elemType>::dequeue() {
	if (isEmpty()) {
		throw "EmptyQueueException";
	}
	
	front = (front + 1) % arrlimit;
	return arr[(front - 1) % arrlimit];
}

template<class elemType>
int arrayQueue<elemType>::size() const {
	return (back-front)%arrlimit;
}

template<class elemType>
int arrayQueue<elemType>::maxsize() const {
	return arrlimit;
}

template<class elemType>
bool arrayQueue<elemType>::isEmpty() const {
	return (front == back);
}

template<class elemType>
bool arrayQueue<elemType>::isFull() const {
	return (arrlimit == (arrlimit-front+back)%arrlimit);
}

template<class elemType>
elemType arrayQueue<elemType>::getFront() const {
	if (isEmpty()) {
		throw "EmptyQueueException";
	}
	return arr[front];
}

template<class elemType>
void arrayQueue<elemType>::doublesize() {
	arrlimit *= 2;
	elemType* tmp = new elemType[arrlimit];
	for (int i = front; i < (back - front) % arrlimit; i++) {
		tmp[i-front] = arr[i];
	}
	back = arrlimit / 2;
	front = 0;
	delete[] arr;
	arr = tmp;
}



#endif