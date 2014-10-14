/*
*    Filename: TowersOfHanoi.cpp
*    Description: 汉诺塔问题，用递归的思想来解决，有点难度。
*    Last modified: 2014-10-14 00:07
*
*    Created by Eleven on 2014-10-14
*    Email: eleveneat@gmail.com
*    Copyright (C) 2014 Eleven. All rights reserved.
*/

#include "TowersOfHanoi.h"
#include <iostream>
#include <stack>

/*
//求解汉诺塔问题的递归程序
void TowersOfHanoi(int n, int x, int y, int z) { // 把n个碟子从塔x移动到塔y，可借助塔z
 	if (n > 0) {
 		TowersOfHanoi(n-1, x, z, y);
 		std::cout << "Move top disk from tower " << x << " to top of tower" << y << std::endl;
 		TowersOfHanoi(n-1, z, y, x);
 	}
}
int main() {
	TowersOfHanoi(4, 1, 2, 3);
	return 0;
}
*/

void Hanoi::TowersOfHanoi(int n, int x, int y, int z) { // 把n个碟子从塔x移动到塔y，可借助塔z
	int num; // 碟子的编号
	if (n > 0) {
		TowersOfHanoi(n-1, x, z, y);
		num = S[x]->top();
		S[x]->pop(); // 从x中移走一个碟子
		S[y]->push(num); // 把这个碟子放到y上
 		std::cout << "Move top disk from tower " << x << " to top of tower" << y << std::endl;
		TowersOfHanoi(n-1, z, y, x);
	}
}

void TowersOfHanoi(int n) { // TowersOfHanoi的预处理程序
	Hanoi X;
	X.S[1] = new std::stack<int>();
	X.S[2] = new std::stack<int>();
	X.S[3] = new std::stack<int>();

	for (int num = n; num > 0; --num) // 初始化
		X.S[1]->push(num); // 把碟子d放到塔1上

	// 把塔1上的n个碟子移动到塔3上，借助于塔2的帮助
	X.TowersOfHanoi(n, 1, 2, 3);
}

int main() {
	TowersOfHanoi(6);
	return 0;
}
