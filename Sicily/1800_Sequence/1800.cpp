/*
*    Filename: 1800.cpp
*    Description: NULL
*    Last modified: 2015-02-28 15:10
*
*    Created by Eleven on 2015-02-28
*    Email: eleveneat@gmail.com
*    Copyright (C) 2015 Eleven. All rights reserved.
*/
#include <iostream>
#include <memory.h>

using namespace std;

int main() {
    int a[40000];
    int n, L, U, min, value;
    while (cin >> n && n) {
        memset(a, 0, 40000*sizeof(int));
        min = 100000;
        cin >> L >> U;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int len = L; len <= U; len++) {
            for (int i = 0; i + len <= n; i++) {
                value = 0;
                for (int j = 0; j < len; j++) {
                    value += a[i+j];
                }
                if (value < min)
                    min = value;
            }
        }
        cout << min << endl;
    }
    return 0;
}
