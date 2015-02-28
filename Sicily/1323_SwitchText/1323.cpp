/*
*    Filename: 1323.cpp
*    Description: NULL
*    Last modified: 2015-02-14 17:07
*
*    Created by Eleven on 2015-02-14
*    Email: eleveneat@gmail.com
*    Copyright (C) 2015 Eleven. All rights reserved.
*/
#include <iostream>
#include <string>

using namespace std;

bool isEmptyOrBlank(string x) {
    int xlen = x.length();
    if (!xlen)return true; // It's empty.
    for (int i = 0; i < xlen; i++)
        if (x[i] != ' ')
            return false;
    return true; // It's blank
}

void process(string x) {
    int xlen = x.length();
    int pos = (xlen % 2) ? (xlen / 2) : (xlen / 2 - 1);
    for (int i = pos; i >= 0; i--)
        cout << x[i];
    for (int i = xlen - 1; i > pos; i--)
        cout << x[i];
    cout << endl;
}

int main () {
    string x, y;
    while (getline(cin, x) && getline(cin, y)) {
        if (!isEmptyOrBlank(y))process(y);
        if (!isEmptyOrBlank(x))process(x);
    }
    return 0;
}

