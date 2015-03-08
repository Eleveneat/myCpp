/*
*    Filename: 1298.cpp
*    Description: NULL
*    Last modified: 2015-03-08 20:25
*
*    Created by Eleven on 2015-03-08
*    Email: eleveneat@gmail.com
*    Copyright (C) 2015 Eleven. All rights reserved.
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    int n, a;
    string value;
    bool isNeg;
    while (cin >> n) {
        if (0 == n) {
            cout << n << endl;
            break;
        } else if (n < 0) {
            isNeg = true;
            n = -n;
        } else {
            isNeg = false;
        }
        value = "";
        while (n != 1) {
            a = n % 3;
            switch (a) {
            case 0:
                value.push_back('0');
                n /= 3;
                break;
            case 1:
                value.push_back('1');
                n /= 3;
                break;
            case 2:
                value.push_back('-');
                n = n / 3 + 1;
                break;
            }
        }
        value.push_back('1');
        for (int i = value.length() - 1; i >= 0; i--) {
            if (isNeg) {
                if ('1' == value[i]) {
                    cout << '-';
                } else if ('-' == value[i]) {
                    cout << '1';
                } else {
                    cout << '0';
                }
            } else {
                cout << value[i];
            }
        }
        cout << endl;
    }
    return 0;
}

