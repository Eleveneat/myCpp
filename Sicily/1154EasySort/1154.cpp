/*
*    Filename: 1154.cpp
*    Description: NULL
*    Last modified: 2015-02-10 14:33
*
*    Created by Eleven on 2015-02-10
*    Email: eleveneat@gmail.com
*    Copyright (C) 2015 Eleven. All rights reserved.
*/
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int main() {
    int testNum, n, a[1010];
    cin >> testNum;
    while(testNum--) {
        memset(a, 0, sizeof(a));
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);
        for (int i = 0; i < n; i++)
            cout << a[i] << endl;
    }
    return 0;
}

