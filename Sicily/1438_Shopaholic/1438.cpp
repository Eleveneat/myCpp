/*
*    Filename: 1438.cpp
*    Description: NULL
*    Last modified: 2015-02-11 13:44
*
*    Created by Eleven on 2015-02-11
*    Email: eleveneat@gmail.com
*    Copyright (C) 2015 Eleven. All rights reserved.
*/
#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int main() {
    int testNum, n;
    int a[21000], max;
    cin >> testNum;
    while(testNum--) {
        memset(a, 0, sizeof(a));
        max = 0;
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a+n);
        for (int i = n % 3; i < n; i += 3)
            max += a[i];
        cout << max << endl;
    }
    return 0;
}

