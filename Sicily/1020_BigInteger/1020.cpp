/*
*    Filename: 1020.cpp
*    Description: NULL
*    Last modified: 2015-09-26 11:24
*
*    Created by Eleveneat on 2015-09-26
*    Email: eleveneat@gmail.com
*    Copyright (C) 2015 Eleveneat. All rights reserved.
*/

#include <iostream>

using namespace std;

int main() {
    int loopNum, testNum, mod;
    int a[120];
    string bigNum;
    cin >> loopNum;
    while (loopNum--) {
        cin >> testNum;
        for (int i = 0; i < testNum; i++)
            cin >> a[i];
        cin >> bigNum;
        cout << "(";
        for (int b = 0; b < testNum; b++) {
            mod = 0;
            for (int i = 0; i < bigNum.length(); i++) {
                mod = (mod * 10 + (bigNum[i] - '0')) % a[b];
            }
            cout << mod;
            if (b + 1 == testNum)
                cout << ")" << endl;
            else
                cout << ",";
        }
    }
    return 0;
}

