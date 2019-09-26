#ifndef ARRAYSTACK_H_
#define ARRAYSTACK_H_
using namespace std;

template <typename elemType>
class arrayStack {
private:
	elemType* arr;
	int arrsize;
	int arrlimit;
public:
	arrayStack(int =10);
	~arrayStack();
	void push(elemType T);
	elemType pop();
	int size() const;
	int maxsize() const;
	bool empty() const;
	elemType Top() const;
};


template<class elemType>
arrayStack<elemType>::arrayStack(int n) {
	arrsize = 0;
	arrlimit = n;
	arr = new elemType[arrlimit];
}

template<class elemType>
arrayStack<elemType>::~arrayStack() {
	delete[] arr;
}

template<class elemType>
void arrayStack<elemType>::push(elemType T) {
	if (arrsize == arrlimit) {
		arrlimit *= 2;
		elemType* tmp = new elemType[arrlimit];
		for (int i = 0; i < arrsize; i++) {
			tmp[i] = arr[i];
		}
		delete[] arr;
		arr = tmp;
	}
	arr[arrsize] = T;
	arrsize++;
}

template<class elemType>
elemType arrayStack<elemType>::pop() {
	if (empty()) {
		throw "EmptyStackException";
	}

	arrsize--;
	return arr[arrsize];
}

template<class elemType>
int arrayStack<elemType>::size() const{
	return arrsize;
}

template<class elemType>
int arrayStack<elemType>::maxsize() const{
	return arrlimit;
}

template<class elemType>
bool arrayStack<elemType>::empty() const{
	return (arrsize == 0);
}

template<class elemType>
elemType arrayStack<elemType>::Top() const {
	if (empty()) {
		throw "EmptyStackException";
	}
	return arr[arrsize - 1];
}




#endif