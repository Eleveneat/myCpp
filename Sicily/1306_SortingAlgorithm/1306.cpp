/*
*    Filename: 1306.cpp
*    Description: 
*    Last modified: 2015-02-10 14:17
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
    int m, n;
    int a[101000];
    while ((cin >> n >> m) && (n != 0)) {
        memset(a, 0, sizeof(a));
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);
        cout << a[0];
        for (int i = m; i < n; i += m)
            cout << " " << a[i];
        cout << endl;
    }
    return 0;
}


