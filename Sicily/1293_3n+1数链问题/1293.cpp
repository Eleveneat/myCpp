/*
*    Filename: 1293.cpp
*    Description: NULL
*    Last modified: 2015-03-07 19:36
*
*    Created by Eleven on 2015-03-07
*    Email: eleveneat@gmail.com
*    Copyright (C) 2015 Eleven. All rights reserved.
*/
#include <iostream>

using namespace std;

int main() {
    int a, b, n, len, max  = -1;
    cin >> a >> b;
    for (int i = a; i <= b; i++) {
        n = i;
        len = 1;
        while (1) {
            if (1 == n) {
                if (len > max)
                    max = len;
                break;
            } else {
                if (1 == n % 2) {
                    n = 3 * n + 1;
                } else {
                    n /= 2;
                }
                len++;
            }
        }
    }
    cout << max << endl;
    return 0;
}

