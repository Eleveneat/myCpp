/*
*    Filename: 1050.cpp
*    Description: NULL
*    Last modified: 2015-10-14 13:38
*
*    Created by Eleveneat on 2015-10-14
*    Email: eleveneat@gmail.com
*    Copyright (C) 2015 Eleveneat. All rights reserved.
*/

#include <iostream>
#include <cstring>

using namespace std;

#define NUMBER 5

int targetNum, approNum, currentNum;
int arr[NUMBER + 1];
bool isUsed[NUMBER + 1];

void bfs(int count) {
    if (approNum == targetNum)
        return;
    if (currentNum > approNum && currentNum <= targetNum)
        approNum = currentNum;
    if (!count)
        return;
    for (int i = 0; i < NUMBER; i++) {
        if (isUsed[i] == true)
            continue;
        isUsed[i] = true;
        for (int j = i + 1; j < NUMBER; j++) {
            if (isUsed[j] == true)
                continue;
            int tmp = arr[j];
            // +
            arr[j] = currentNum = arr[i] + tmp;
            bfs(count - 1);
            // -
            arr[j] = currentNum = arr[i] - tmp;
            bfs(count - 1);
            arr[j] = currentNum = tmp - arr[i];
            bfs(count - 1);
            // *
            arr[j] = currentNum = arr[i] * tmp;
            bfs(count - 1);
            // /
            if (tmp && arr[i] % tmp == 0) {
                arr[j] = currentNum = arr[i] / tmp;
                bfs(count - 1);
            }
            if (arr[i] && tmp % arr[i] == 0) {
                arr[j] = currentNum = tmp / arr[i];
                bfs(count - 1);
            }
            arr[j] = tmp;
        }
        isUsed[i] = false;
    }
}

int main() {
    int testNum;
    cin >> testNum;
    while (testNum--) {
        for(int i = 0; i < NUMBER; i++) {
            cin >> arr[i];
        }
        cin >> targetNum;
        currentNum = approNum = -2000000000;
        memset(isUsed, false, (NUMBER + 1) * sizeof(bool));
        bfs(NUMBER - 1);
        cout << approNum << endl;
    }
    return 0;
}

