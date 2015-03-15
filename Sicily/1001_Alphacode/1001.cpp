/*
*    Filename: 1001.cpp
*    Description: NULL
*    Last modified: 2015-03-15 22:31
*
*    Created by Eleven on 2015-03-15
*    Email: eleveneat@gmail.com
*    Copyright (C) 2015 Eleven. All rights reserved.
*/
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main() {
    char str[11000];
    int a[11000], len, tenDig, oneDig;
    while (scanf("%s", str) && '0' != str[0]) {
        len = strlen(str);
        if (1 == len) {
            cout << 1 << endl;
            continue;
        }
        a[0] = 1;
        a[1] = ((str[1]-'0') && ((str[1]-'0') + (str[0]-'0') * 10 <= 26)) ? 2 : 1;
        for (int i = 2; i < len; i++) {
            tenDig = str[i-1] - '0';
            oneDig = str[i] - '0';
            if (!oneDig) {
                    a[i] = a[i-2];
            } else {
                if (!tenDig)
                    a[i] = a[i-1];
                else if (tenDig * 10 + oneDig <= 26)
                    a[i] = a[i-1] + a[i-2];
                else
                    a[i] = a[i-1];
            }
        }
        cout << a[len-1] << endl;
    }
    return 0;
}

