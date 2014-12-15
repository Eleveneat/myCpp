/*
*    Filename: test.cpp
*    Description: 
*    Last modified: 2014-10-15 11:53
*
*    Created by Eleven on 2014-10-15
*    Email: eleveneat@gmail.com
*    Copyright (C) 2014 Eleven. All rights reserved.
*/
#include "Queue.h"
#include <iostream>
int main() {
	Queue<int> q;
	for (int i = 0; i < 10000; ++i)
		q.push(i);
	for (int i = 0; i < 10000; ++i) {
		std::cout << q.front() << std::endl;
		q.pop();
	}
	return 0;
}
