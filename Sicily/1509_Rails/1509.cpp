/*
*    Filename: 1509.cpp
*    Description: NULL
*    Last modified: 2015-02-15 16:15
*
*    Created by Eleven on 2015-02-15
*    Email: eleveneat@gmail.com
*    Copyright (C) 2015 Eleven. All rights reserved.
*/
#include <iostream>
#include <stack>

using namespace std;

int main() {
    int n, pos, a[1100];
    stack<int> s;
    while (cin >> n && n) {
        while (cin >> a[0] && a[0]) {
            for (int i = 1; i < n; i++)
                cin >> a[i];
            while (!s.empty())
                s.pop();
            pos = 1;
            for (int i = 0; pos <= n; pos++) {
                if (pos == a[i]) {
                    i++;
                    while (!s.empty() && s.top() == a[i]) {
                        s.pop();
                        i++;
                    }
                } else {
                    s.push(pos);
                }
            }
            if (s.empty()) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
        cout << endl;
    }
    return 0;
}

