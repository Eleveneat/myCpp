/*
*    Filename: 1159.cpp
*    Description: NULL
*    Last modified: 2015-03-08 19:10
*
*    Created by Eleven on 2015-03-08
*    Email: eleveneat@gmail.com
*    Copyright (C) 2015 Eleven. All rights reserved.
*/
#include <iostream>
#include <memory.h>
#include <string>

using namespace std;

void add(string& a, string& b) {
    int x[110], y[110];
    memset(x, 0, 110*sizeof(int));
    memset(y, 0, 110*sizeof(int));
    x[0] = a.length();
    y[0] = b.length();
    for (int i = 1; i <= x[0]; i++) {
        x[i] = a[x[0]-i] - '0';
    }
    for (int i = 1; i <= y[0]; i++) {
        y[i] = b[y[0]-i] - '0';
    }
    int len = x[0] > y[0] ? x[0] : y[0];
    for (int i = 1; i <= len; i++) {
        x[i] += y[i];
        x[i+1] += x[i] / 10;
        x[i] %= 10;
    }
    len++;
    while (0 == x[len] && len > 1)
        len--;
    a = "";
    for (int i = len; i > 0; i--)
        a += '0' + x[i];
}

int main() {
    string a, b;
    int n;
    while (cin >> n) {
        cin >> a;
        for (int i = 1; i < n; i++) {
            cin >> b;
            add(a, b);
        }
        cout << a << endl;
    }
    return 0;
}

