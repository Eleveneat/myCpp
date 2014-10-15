/*
*    Filename: Queue.h
*    Description: 公式化描述的队列，采用循坏队列，添加和删除操作在最坏情况下的时间复杂性均为O(1).
*    Last modified: 2014-10-15 10:44
*
*    Created by Eleven on 2014-10-15
*    Email: eleveneat@gmail.com
*    Copyright (C) 2014 Eleven. All rights reserved.
*/
#ifndef _QUEUE_H
#define _QUEUE_H

#include <iostream>
template <class T>
class Queue {
	public:
		Queue();
		~Queue();
		bool empty();
		int size();
		T& front();//返回队首元素
		T& rear();//返回队尾元素
		void push(T value);
		void pop();
	private:
		int f;//指向第一个元素
		int r;//指向最后一个元素
		int MAXSIZE;//队列数组的大小，可变
		T* queue;//数组
};
#endif //QUEUE_H

template <class T>
Queue<T>::Queue() {
	queue = new T[MAXSIZE];
	MAXSIZE = 100;
	f = 0;
	r = -1;
}

template <class T>
Queue<T>::~Queue() {
	delete []queue;
	MAXSIZE = 100;
	f = 0;
	r = -1;
}

template <class T>
bool Queue<T>::empty() {
	return -1 == r;
}

template <class T>
int Queue<T>::size() {
	if (empty())return 0;
	else if (f <= r) return r - f + 1;
	else return MAXSIZE - (f - r + 1);
}

template <class T>
T& Queue<T>::front() {
	return queue[f];
}

template <class T>
T& Queue<T>::rear() {
	return queue[r];
}

template <class T>
void Queue<T>::push(T value) {
	if (empty())queue[++r] = value;//如果数组为空
	else if ((r + 1) % MAXSIZE == f) {//如果数组已满
		T* tmp = new T[MAXSIZE*2];//开辟一个比之前大一倍的数组空间
		for (int i = 0; i <= r; ++i)
			tmp[i] = queue[i];
		tmp[++r] = value;
		for (int i = MAXSIZE - f; i > 0; --i) {
			tmp[MAXSIZE*2 - i] = queue[MAXSIZE - i];
		}
		f += MAXSIZE;
		MAXSIZE *= 2;
		delete []queue;
		queue = tmp;
	} else {
		r = (r + 1) % MAXSIZE;
		queue[r] = value;
	}
}

template <class T>
void Queue<T>::pop() {
	if (empty()) {}//如果数组为空
	else if (f == r) { f = 0; r = -1; }//如果数组大小为1
	else f = (f + 1) % MAXSIZE;
}


