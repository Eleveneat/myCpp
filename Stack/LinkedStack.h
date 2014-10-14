/*
*    Filename: LinkedStack.h
*    Description: None.
*    Last modified: 2014-10-14 10:50
*
*    Created by Eleven on 2014-10-14
*    Email: eleveneat@gmail.com
*    Copyright (C) 2014 Eleven. All rights reserved.
*/
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
