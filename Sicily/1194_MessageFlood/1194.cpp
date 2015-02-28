/*
*    Filename: 1194.cpp
*    Description: NULL
*    Last modified: 2015-02-16 18:07
*
*    Created by Eleven on 2015-02-16
*    Email: eleveneat@gmail.com
*    Copyright (C) 2015 Eleven. All rights reserved.
*/
#include <iostream>
#include <string>
#include <memory.h>
#include <algorithm>

using namespace std;

string friends[21000];
bool isFound[21000];

bool cmp(const string& s1, const string& s2) {
    return s1 < s2;
}

bool bi_search(string str, int len) {
    int left = 0;
    int right = len - 1;
    int mid;
    while (left <= right) {
        mid = (left + right) / 2;
        if (str == friends[mid]) {
            if (isFound[mid]) {
                return false;
            } else {
                isFound[mid] = true;
                return true;
            }
        } else if (str > friends[mid]) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return false;
}

int main() {
    int n, m, count;
    string sender;
    while (cin >> n && n) {
        cin >> m;
        count = n;
        memset(isFound, false, 21000*sizeof(bool));
        for (int i = 0; i < n; i++) {
            cin >> friends[i];
            transform(friends[i].begin(), friends[i].end(), friends[i].begin(), ::tolower);
        }
        sort(friends, friends+n, cmp);
        for (int i = 0; i < m; i++) {
            cin >> sender;
            transform(sender.begin(), sender.end(), sender.begin(), ::tolower);
            if (bi_search(sender, n))
                count--;
        }
        cout << count << endl;
    }
    return 0;
}
