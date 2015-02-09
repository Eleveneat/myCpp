/*
*    Filename: 1200.cpp
*    Description: 
*    Last modified: 2015-02-09 12:24
*
*    Created by Eleven on 2015-02-09
*    Email: eleveneat@gmail.com
*    Copyright (C) 2015 Eleven. All rights reserved.
*/
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int main() {
    int totalNum, a[110];
    int eachDigNum;
    cin >> totalNum;
    while (totalNum != 0) {
        memset(a, 0, sizeof(a));
        for (int i = 0; i < totalNum; i++)
            cin >> a[i];
        sort(a, a + totalNum);
        for (int i = 0; i < totalNum; i++) {
            eachDigNum = 1;
            for (; i < totalNum; i++) {
                if (a[i+1] != a[i])
                    break;
                else
                    eachDigNum++;
            }
            if (eachDigNum % 2 == 1) {
                cout << a[i] << endl;
                break;
            }
        }
        cin >> totalNum;
    }
}
