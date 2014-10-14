/*
*    Filename: LinkedStack.cpp
*    Description: 用链表描述的stack，异常处理并未完成，不能编译。
*    Last modified: 2014-10-14 10:50
*
*    Created by Eleven on 2014-10-14
*    Email: eleveneat@gmail.com
*    Copyright (C) 2014 Eleven. All rights reserved.
*/
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

