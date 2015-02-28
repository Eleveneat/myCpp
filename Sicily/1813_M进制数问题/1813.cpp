/*
*    Filename: 1813.cpp
*    Description: NULL
*    Last modified: 2015-02-28 13:05
*
*    Created by Eleven on 2015-02-28
*    Email: eleveneat@gmail.com
*    Copyright (C) 2015 Eleven. All rights reserved.
*/
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int toDecimal(string str, int m) {
    int len = str.length();
    int dec = 0;
    for (int i = len - 1; i >= 0; i--) {
        if (str[len - i - 1] >= 'A')
            dec += (str[len-i-1] - 'A' +10) * pow(m, i);
        else
            dec += (str[len-i-1] - '0') * pow(m, i);
    }
    return dec;
}

string toM(int x, int m) {
    if (0 == x) return "0";
    string str1, str2;
    while (0 != x / m || (0 == x / m && x > 0)) {
        if (x % m > 9)
            str1 += 'A' - 10 + x % m;
        else
            str1 += '0' + x % m;
        x /= m;
    }
    for (int i = str1.length() - 1; i >= 0; i--)
        str2 += str1[i];
    return str2;
}

int main() {
    int testNum, m, p, q, aDec, bDec;
    string a, b, pM, qM;
    cin >> testNum;
    while (testNum--) {
        cin >> m >> a >> b;
        aDec = toDecimal(a, m);
        bDec = toDecimal(b, m);
        p = aDec / bDec;
        q = aDec % bDec;
        pM = toM(p, m);
        qM = toM(q, m);
        cout << pM << endl << qM << endl;
    }
    return 0;
}

