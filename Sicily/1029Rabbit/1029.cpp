/*
*    Filename: 1029.cpp
*    Description: NULL
*    Last modified: 2015-02-08 17:18
*
*    Created by Eleven on 2015-02-08
*    Email: eleveneat@gmail.com
*    Copyright (C) 2015 Eleven. All rights reserved.
*/
#include <iostream>
#include <string>
using namespace std;

int rabbitNum[110][31];

void init(int mouth) {
    int num = mouth + 1;
    for (int i = 0; num > 0; i++) {
        rabbitNum[mouth][i] = num % 10;
        num /= 10;
    }
}
void addition(int a, int b) { // 高精度加法
    int tmp;
    for (int i = 0; i < 30; i++) {
        tmp = rabbitNum[a][i];
        rabbitNum[a][i] = (tmp + rabbitNum[a-1][i] + rabbitNum[b][i]) % 10;
        rabbitNum[a][i+1] = (tmp + rabbitNum[a-1][i] + rabbitNum[b][i]) / 10;
    }
}
int main() {
    int m, d;
    int len;
    cin >> m >> d;
    while(m + d != 0) {
        memset(rabbitNum, 0, sizeof(rabbitNum));
//        for (int i = 0; i < 110; i ++) {
//           for (int j = 0; j < 31; j++) {
//               rabbitNum[i][j] = 0;
//           }
//        }
        for (int i = 0; i <= d; i++) {
            if (i <= m) // 初始化m个月前的兔子，包括第m个月。
                init(i);
            else
                addition(i, i - m);
        }
        for (len = 30; rabbitNum[d][len] == 0; len--) // 去掉开头的0。
            continue;
        for (int i = len; i >= 0; i--) {
            cout << rabbitNum[d][i];
        }
        cout << endl;
        cin >> m >> d;
    }
    return 0;
}
