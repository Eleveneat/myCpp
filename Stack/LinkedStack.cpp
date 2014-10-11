#include "LinkedStack.h"

template <class T>
LinkedStack<T>::~LinkedStack() {
	Node<T> *next;
	while(top) {
		next = top->link;
		delete top;
		top = next;
	}
}
template <class T>
bool LinkedStack<T>::isFull() {
	try {
		Node<T> *foo = new Node<T>;
		delete foo;
		return false;
	}
	catch (NoMem) {return true;}
}
template <class T>
T LinkedStack<T>::top(const T& x) {
	if (isEmpty())throw OutOfBounds();
	return top->data;
}
template <class T>
void LinkedStack<T>::push(const T& x) {
	Node<T> *foo = new Node<T>;
	foo->data = x;
	foo->link = top;
	top = foo;
}
template <class T>
void LinkedStack<T>::pop() {
	Node<T> *foo = top;
	top = top->link;
	delete foo;
}

