/*
*    Filename: trainReset.cpp
*    Description: 火车车厢重排 5.5.3. Pages 172. 
*    Last modified: 2014-10-14 14:17
*
*    Created by Eleven on 2014-10-14
*    Email: eleveneat@gmail.com
*    Copyright (C) 2014 Eleven. All rights reserved.
*/

#include <iostream>
#include <stack>

const int MAXSIZE = 1000;

void Output(int& minH, int& minS, std::stack<int> H[], int k, int n);
bool Hold(int c, int& minH, int& minS, std::stack<int> H[], int k, int n);

bool Railroad(int p[], int n, int k) {
	// k个缓冲铁轨， 车厢初始排序为p[1:n]
	// 如果重排成功，返回true，否则返回false

	// 创建与缓冲铁轨对应的堆栈
	std::stack<int> *H;
	H = new std::stack<int>[k+1];
	int NowOut = 1; // 下一次要输出的车厢
	int minH = n + 1; // 缓冲铁轨中编号最小的车厢
	int minS; // minH号车厢对应的缓冲铁轨

	// 车厢重排
	for (int i = 1; i <= n; ++i) {
		if (p[i] == NowOut) { // 直接输出t
			std::cout << "Move car " << p[i] << " from input to output" << std::endl;
			NowOut++;

			// 从缓冲铁轨中输出
			while(minH == NowOut) {
				Output(minH, minS, H, k, n);
				NowOut++;
			}
		} else { // 将p[i]送入某个缓冲铁轨
			if (!Hold(p[i], minH, minS, H, k, n))
				return false;
		}
	}
	return true;
}

void Output(int& minH, int& minS, std::stack<int> H[], int k, int n) {
	// 把车厢从缓冲铁轨送至出轨处，通识修改minS和minH
	int c; // 车厢索引

	// 从堆栈minS中删除编号最小的车厢minH
	H[minS].pop();
	std::cout << "Move car " << minH << " from holding track " << minS << " to output" << std::endl;

	// 通过检查所有的栈顶，搜索新的minH和minS
	minH = n + 2;
	for (int i = 1; i <= k; ++i) {
		if(!H[i].empty() && (c = H[i].top()) < minH) {
			minH = c;
			minS = i;
		}
	}
}

bool Hold(int c, int& minH, int& minS, std::stack<int> H[], int k, int n) {
	// 在一个缓冲铁轨中放入车厢c
	// 如果没有可用的缓冲铁轨， 则返回false
	// 否则放回true

	// 为车厢c寻找最优的缓冲铁轨
	int BestTrack = 0; // 目前最优的铁轨
	int BestTop = n + 1; // 最优铁轨上的头辆车厢
	int x; // 车厢索引

	// 扫描缓冲车厢
	for (int i = 1; i <= k; ++i) {
		if (!H[i].empty()) { //  铁轨i不空
			x = H[i].top();
			if (c < x && x < BestTop) {
				// 铁轨i顶部的车厢编号最小
				BestTop = x;
				BestTrack = i;
			}
		} else { // 铁轨i为空
			if (!BestTrack)BestTrack = i;
		}
	}
	if (!BestTrack) return false; // 没有可用的铁轨

	// 把车厢c送入缓冲铁轨
	H[BestTrack].push(c);
	std::cout << "Move car " << c << " from input to holding track " << BestTrack << std::endl;

	// 必要时修改minH和minS
	if (c < minH) {
		minH = c;
		minS = BestTrack;
	}
	return true;
}

// 测试函数
int main() {
	int Number_Of_Cars, Number_Of_Holding;
	int Car[MAXSIZE];
	std::cout << "Please enter the number of the cars:" << std::endl;
	std::cin >> Number_Of_Cars;
	std::cout << "Please enter the number of the holding track" << std::endl;
	std::cin >> Number_Of_Holding;
	std::cout << "Please list the order of the cars" << std::endl;
	for (int i = 1; i <= Number_Of_Cars; ++i)
		std::cin >> Car[i];
	Railroad(Car, Number_Of_Cars, Number_Of_Holding);
	return 0;
}
