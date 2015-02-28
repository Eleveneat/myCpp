/*
*    Filename: 1443.cpp
*    Description: NULL
*    Last modified: 2015-02-14 16:27
*
*    Created by Eleven on 2015-02-14
*    Email: eleveneat@gmail.com
*    Copyright (C) 2015 Eleven. All rights reserved.
*/
#include <iostream>

using namespace std;

int main() {
    int testNum, len, pos, time, front;
    int a[110];
    bool isMax;
    cin >> testNum;
    while (testNum--) {
        time = 0;
        cin >> len >> pos;
        for (int i = 0; i < len; i++)
            cin >> a[i];
        while (1) {
            isMax = true;
            for (int i = 1; i < len; i++) {
                if (a[i] > a[0]) {
                    isMax = false;
                    break;
                }
            }
            front = a[0];
            for (int i = 0; i < len-1; i++)
                a[i] = a[i+1];
            if (isMax && 0 == pos) {
                time++;
                break;
            } else if (isMax && 0 != pos) {
                time++;
                len--;
                pos--;
                continue;
            } else {
                pos--;
                pos = (pos + len) % len;
                a[len-1] = front;
                continue;
            }
        }
        cout << time << endl;
    }
    return 0;
}

