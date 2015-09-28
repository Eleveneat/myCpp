/*
*    Filename: 1035.cpp
*    Description: NULL
*    Last modified: 2015-09-26 13:35
*
*    Created by Eleveneat on 2015-09-26
*    Email: eleveneat@gmail.com
*    Copyright (C) 2015 Eleveneat. All rights reserved.
*/

#include <iostream>
#include "string.h"

using namespace std;

bool isMatch(string, string);

int main() {
    int testNum, n, max;
    bool isVisit[120];
    string allStrands[120];
    cin >> testNum;
    while (testNum--) {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> allStrands[i];

        max = 0;
        memset(isVisit, false, 120 * sizeof(bool));

        for (int i = 0; i < n; i++) {
            if (isVisit[i])
                continue;
            for (int j = i + 1; j < n; j++) {
                if (isVisit[j])
                    continue;
                if (isMatch(allStrands[i], allStrands[j])) {
                    isVisit[i] = isVisit[j] = true;
                    max++;
                    break;
                }
            }
        }
        cout << max << endl;
    }
    return 0;
}

bool isMatch(string s1, string s2) {
    if (s1.length() != s2.length())
        return false;
    for (int i = 0; i < s1.length(); i++) {
        if (s1[i] == 'A' && s2[i] == 'T')
            continue;
        if (s1[i] == 'T' && s2[i] == 'A')
            continue;
        if (s1[i] == 'C' && s2[i] == 'G')
            continue;
        if (s1[i] == 'G' && s2[i] == 'C')
            continue;
        return false;
    }
    return true;
}

