/*
*    Filename: 1198.cpp
*    Description: NULL
*    Last modified: 2015-09-28 19:57
*
*    Created by Eleveneat on 2015-09-28
*    Email: eleveneat@gmail.com
*    Copyright (C) 2015 Eleveneat. All rights reserved.
*/

#include <iostream>
#include <string.h>

using namespace std;

bool isUsed[10];
string subStr[10];
string minLexStr;
int subStrNum;

void enumeration(string);
void minLex(string);

int main() {
    int testNum;
    cin >> testNum;
    while (testNum--) {
        cin >> subStrNum;
        for (int i = 0; i < subStrNum; i++)
            cin >> subStr[i];

        memset(isUsed, false, 10 * sizeof(bool));
        minLexStr = "";
        enumeration(minLexStr);
        cout << minLexStr << endl;
    }
    return 0;
}

void enumeration(string str) {
    bool isFinish = true;

    for (int i = 0; i < subStrNum; i++)
        if (false == isUsed[i]) {
            isFinish = false;
            break;
        }
    if (isFinish) {
        minLex(str);
        return;
    }

    for (int i = 0; i < subStrNum; i++) {
        if (false == isUsed[i]) {
            isUsed[i] = true;
            enumeration(str + subStr[i]);
            isUsed[i] = false;
        }
    }
}

void minLex(string str) {
    if ("" == minLexStr) {
        minLexStr = str;
        return;
    }

    for (int i = 0; i < str.length(); i++) {
        if (str[i] > minLexStr[i])
            return;
        if (str[i] < minLexStr[i]) {
            minLexStr = str;
            return;
        }
    }
}

