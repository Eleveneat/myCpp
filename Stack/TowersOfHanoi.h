/*
*    Filename: TowersOfHanoi.h
*    Description: Declaration of class Hanoi.
*    Last modified: 2014-10-14 00:32
*
*    Created by Eleven on 2014-10-14
*    Email: eleveneat@gmail.com
*    Copyright (C) 2014 Eleven. All rights reserved.
*/
#ifndef _TOWERSOFHANOI_H
#define _TOWERSOFHANOI_H
#include <stack>

class Hanoi {
	friend void TowersOfHanoi(int);
	public:
		void TowersOfHanoi(int n, int x, int y, int z);
	private:
		std::stack<int> *S[4];
};

#endif //TOWERSOFHANOI_H

