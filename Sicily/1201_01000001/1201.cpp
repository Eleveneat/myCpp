/*
*    Filename: 1201.cpp
*    Description: NULL
*    Last modified: 2015-03-07 20:37
*
*    Created by Eleven on 2015-03-07
*    Email: eleveneat@gmail.com
*    Copyright (C) 2015 Eleven. All rights reserved.
*/
#include <iostream>
#include <string>

using namespace std;

void addAndPrint(string& a, string& b) {
    int alen = a.length();
    int blen = b.length();
    int carry = 0, aDig, bDig;
    int pos;
    for (int i = 1; i <= blen; i++) {
        aDig = a[alen-i] - '0';
        bDig = b[blen-i] - '0';
        a[alen-i] = '0' + (aDig + bDig + carry) % 2;
        carry = (aDig + bDig + carry) / 2;
    }
    for (int i = blen + 1; i <= alen && carry; i++) {
        if ('0' == a[alen-i]) {
            a[alen-i] = '1';
            carry = 0;
            break;
        } else {
            a[alen-i] = '0';
        }
    }
    if (carry) {
        cout << '1' << a << endl;
    } else {
        for (pos = 0; pos < alen; pos++)
            if (a[pos] != '0')
                break;
        if (pos == alen)
            cout << "0";
        for (; pos < alen; pos++)
            cout << a[pos];
        cout << endl;
    }
}

int main() {
    int testNum;
    string a, b;
    cin >> testNum;
    for (int i = 1; i <= testNum; i++) {
        cin >> a >> b;
        cout << i << " ";
        if (a.length() >= b.length())
            addAndPrint(a, b);
        else
            addAndPrint(b, a);
    }
    return 0;
}

