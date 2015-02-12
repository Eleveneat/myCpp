/*
*    Filename: 1006.cpp
*    Description: NULL
*    Last modified: 2015-02-12 15:23
*
*    Created by Eleven on 2015-02-12
*    Email: eleveneat@gmail.com
*    Copyright (C) 2015 Eleven. All rights reserved.
*/
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int n, value, len = 5, min = 1000;
    int pos[5];
    string name, next;
    string a[110];
    while (cin >> n && n) {
        for (int i = 0; i < n; i++)
            cin >> a[i];
        next = "ABCDE";
        min = 1000;
        do {
            for (int i = 0; i < len; i++)
                pos[next[i] - 'A'] = i;
            value = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < len; j++) {
                    for (int k = j + 1; k < len; k++) {
                        if (pos[a[i][j]-'A'] > pos[a[i][k]-'A'])
                            value++;
                    }
                }
            }
            if (value < min) {
                name = next;
                min = value;
            }
        } while (next_permutation(next.begin(), next.end()));
        cout << name << " is the median ranking with value " << min << "." << endl;
    }
}

