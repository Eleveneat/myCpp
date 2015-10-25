/*
*    Filename: 1151.cpp
*    Description: NULL
*    Last modified: 2015-10-10 14:36
*
*    Created by Eleveneat on 2015-10-10
*    Email: eleveneat@gmail.com
*    Copyright (C) 2015 Eleveneat. All rights reserved.
*/

#include <iostream>
#include <cstring>
#include <string>
#include <list>
#include <cmath>

using namespace std;

// 魔板
struct magicBoard {
    int x; // 以整数形式保存第一行数字
    int y; // 以整数形式保存第二行数字
    string step; // 以字符串形式保存到达该状态之前的所有操作
};

int maxStep; // 最大步数
magicBoard targetMb; // 目标魔板
bool isVisit[41000]; // 8! = 40320.
list<magicBoard> queue; // 存放魔板的队列
list<magicBoard>::iterator headItr; // 指向BFS队列头的迭代器
int factorial[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320}; // 8!的阶乘表

// 判断传入魔板是否已经出现过
bool isExist(magicBoard newMb) {
    int mbNum[8], pos;
    // 还原为8位的数字
    int num = newMb.x * 10000 + newMb.y;
    for (int i = 0; i < 8; i++) {
        mbNum[i] = num % 10;
        num /= 10;
    }

    // 计算康托展开的数值
    pos = 0;
    for (int i = 0; i < 8; i++) {
        int count = 0;
        for (int j = i - 1; j >= 0; j--) {
            if (mbNum[i] > mbNum[j]) {
                count++;
            }
        }
        pos += count * factorial[i];
    }
    // 根据康托展开值在数组中判断该魔板是否已经出现
    // 若出现，则返回true
    if (isVisit[pos])
        return true;

    // 在数组中标记为true，代表魔板已经出现
    isVisit[pos] = true;
    return false;
}

// 操作A，上下行互换
bool opA() {
    magicBoard newMb;
    newMb.x = headItr->y;
    newMb.y = headItr->x;
    newMb.step = headItr->step + "A";
    // 若该魔板状态未出现，压入队列
    if (!isExist(newMb)) {
        queue.push_back(newMb);
    }
    // 若该魔板状态等于目标魔板，返回true
    if (newMb.x == targetMb.x && newMb.y == targetMb.y)
        return true;
    return false;
}

// 操作B，行循环右移
bool opB() {
    magicBoard newMb;
    newMb.x = headItr->x / 10 + headItr->x % 10 * 1000;
    newMb.y = headItr->y / 10 + headItr->y % 10 * 1000;
    newMb.step = headItr->step + "B";
    // 若该魔板状态未出现，压入队列
    if (!isExist(newMb)) {
        queue.push_back(newMb);
    }
    // 若该魔板状态等于目标魔板，返回true
    if (newMb.x == targetMb.x && newMb.y == targetMb.y)
        return true;
    return false;
}

// 操作C，中间四小块顺时针转一格
bool opC() {
    magicBoard newMb;
    int x = headItr->x;
    int y = headItr->y;
    newMb.x = x / 1000 * 1000 + y / 100 % 10 * 100 + x / 100 % 10 * 10 + x % 10;
    newMb.y = y / 1000 * 1000 + y / 10 % 10 * 100 + x / 10 % 10 * 10 + y % 10;
    newMb.step = headItr->step + "C";
    // 迭代器加一，队列头指向下一个魔板
    headItr++;
    // 若该魔板状态未出现，压入队列
    if (!isExist(newMb)) {
        queue.push_back(newMb);
    }
    // 若该魔板状态等于目标魔板，返回true
    if (newMb.x == targetMb.x && newMb.y == targetMb.y)
        return true;
    return false;
}

// 宽度优先搜索
void bfs() {
    // 定义初始魔板，并压进队列
    magicBoard firstMb = {1234, 8765, ""};
    queue.push_back(firstMb);
    headItr = queue.begin();
    while (1) {
        // 取得队列尾的魔板
        magicBoard lastMb = queue.back();
        // 判断是否超过最大步数，若超过，则输出-1且退出循环
        if (lastMb.step.length() > maxStep) {
            cout << -1 << endl;
            break;
        }
        // 判断是否为目标状态，若是，则输出结果且退出循环
        if (lastMb.x == targetMb.x && lastMb.y == targetMb.y) {
            cout << lastMb.step.length() << " " << lastMb.step << endl;
            break;
        }
        // 分别进行操作A、B、C
        // 若其中一个操作返回true，则代表找到目标状态，立即跳过接下来的操作，继续循环
        if (opA() || opB() || opC())
            continue;
    }
}

int main() {
    int tmpNum;
    while (cin >> maxStep, maxStep != -1) {
        // 初始化目标魔板
        targetMb.x = targetMb.y = 0;
        for (int i = 3; i >= 0; i--) {
            cin >> tmpNum;
            targetMb.x += pow(10, i) * tmpNum;
        }
        for (int i = 3; i >= 0; i--) {
            cin >> tmpNum;
            targetMb.y += pow(10, i) * tmpNum;
        }

        memset(isVisit, false, 41000 * sizeof(bool));
        queue.clear();
        bfs();
    }

    return 0;
}



