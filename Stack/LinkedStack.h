#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H

template <class T>
class Node {
	friend LinkedStack<T>;
	private:
		T data;
		Node<T> *link;
};
template <class T>
class LinkedStack {
	public:
		LinkedStack() {top = 0;}
		~LinkedStack();
		bool isEmpty() const {return top == 0;}
		bool isFull() const;
		T top();
		void push(const T& x);
		void pop();
	private:
		Node<T> *top;
};
#endif
