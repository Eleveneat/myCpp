/*
*    Filename: 1351.cpp
*    Description: NULL
*    Last modified: 2015-02-10 15:33
*
*    Created by Eleven on 2015-02-10
*    Email: eleveneat@gmail.com
*    Copyright (C) 2015 Eleven. All rights reserved.
*/
#include <iostream>
#include <string.h>

using namespace std;

int a[1001000], s[3001000];
bool visit[1001000];

int main() {
    int c, n, len;
    while((cin >> c >> n)) {
        len = 0;
        memset(a, 0, sizeof(a));
        memset(s, 0, sizeof(s));
        memset(visit, false, sizeof(visit));
        for (int i = 0; i < n; i++)
            cin >> s[i];
        for (int i = n - 1; i >= 0; i--) {
            if(!visit[s[i]]) {
                a[len++] = s[i];
                visit[s[i]] = true;
            }
        }
        cout << len << endl;
        for (int i = len - 1; i > 0; i--)
            cout << a[i] << " ";
        cout << a[0] << endl;
    }
    return 0;
}

