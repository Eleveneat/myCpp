/*
*    Filename: 高精度加法.cpp
*    Description: NULL
*    Last modified: 2015-02-08 14:37
*
*    Created by Eleven on 2015-02-08
*    Email: eleveneat@gmail.com
*    Copyright (C) 2015 Eleven. All rights reserved.
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
    string str1, str2;
    int a[250], b[250], len;
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    cin >> str1 >> str2;
    a[0] = str1.length();
    b[0] = str2.length();
    for (int i = 1; i <= a[0]; i++) {
        a[i] = str1[a[0]-i] - '0';
    }
    for (int i = 1; i <= b[0]; i++) {
        b[i] = str2[b[0]-i] - '0';
    }
    len = (a[0] > b[0] ? a[0] : b[0]);
    for (int i = 1; i <= len; i++) {
        a[i] += b[i];
        a[i+1] += a[i] / 10;
        a[i] %= 10;
    }
    len++;
    while((a[len] == 0) && (len > 1))
        len--;
    for (int i = len; i >= 1; i--) {
        cout << a[i];
    }
    cout << endl;
    return 0;
}

