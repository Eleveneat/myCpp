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

struct magicBoard {
    int x;
    int y;
    string step;
};

int maxStep;
magicBoard oriMb;
bool isVisit[41000]; // 8! = 40320.
list<magicBoard> queue;
list<magicBoard>::iterator headItr;
int factorial[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320}; // 8!的阶乘表

void bfs();
bool opA();
bool opB();
bool opC();
bool isExist(magicBoard);

int main() {
    int tmpNum;
    while (cin >> maxStep, maxStep != -1) {
        oriMb.x = oriMb.y = 0;
        for (int i = 3; i >= 0; i--) {
            cin >> tmpNum;
            oriMb.x += pow(10, i) * tmpNum;
        }
        for (int i = 3; i >= 0; i--) {
            cin >> tmpNum;
            oriMb.y += pow(10, i) * tmpNum;
        }
        memset(isVisit, false, 41000 * sizeof(bool));
        queue.clear();
        bfs();
    }

    return 0;
}

void bfs() {
    magicBoard firstMb = {1234, 8765, ""};
    queue.push_back(firstMb);
    headItr = queue.begin();
    while (1) {
        magicBoard lastMb = queue.back();
        if (lastMb.step.length() > maxStep) {
            cout << -1 << endl;
            break;
        }
        if (lastMb.x == oriMb.x && lastMb.y == oriMb.y) {
            cout << lastMb.step.length() << " " << lastMb.step << endl;
            break;
        }
        if (opA() || opB() || opC())
            continue;
    }
}

bool opA() {
    magicBoard newMb;
    newMb.x = headItr->y;
    newMb.y = headItr->x;
    newMb.step = headItr->step + "A";
    if (!isExist(newMb)) {
        queue.push_back(newMb);
    }
    if (newMb.x == oriMb.x && newMb.y == oriMb.y)
        return true;
    return false;
}

bool opB() {
    magicBoard newMb;
    newMb.x = headItr->x / 10 + headItr->x % 10 * 1000;
    newMb.y = headItr->y / 10 + headItr->y % 10 * 1000;
    newMb.step = headItr->step + "B";
    if (!isExist(newMb)) {
        queue.push_back(newMb);
    }
    if (newMb.x == oriMb.x && newMb.y == oriMb.y)
        return true;
    return false;
}

bool opC() {
    magicBoard newMb;
    int x = headItr->x;
    int y = headItr->y;
    newMb.x = x / 1000 * 1000 + y / 100 % 10 * 100 + x / 100 % 10 * 10 + x % 10;
    newMb.y = y / 1000 * 1000 + y / 10 % 10 * 100 + x / 10 % 10 * 10 + y % 10;
    newMb.step = headItr->step + "C";
    headItr++;
    if (!isExist(newMb)) {
        queue.push_back(newMb);
    }
    if (newMb.x == oriMb.x && newMb.y == oriMb.y)
        return true;
    return false;
}

bool isExist(magicBoard newMb) {
    int mbNum[8], pos;
    int num = newMb.x * 10000 + newMb.y;
    for (int i = 0; i < 8; i++) {
        mbNum[i] = num % 10;
        num /= 10;
    }

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
    if (isVisit[pos])
        return true;

    isVisit[pos] = true;
    return false;
}

