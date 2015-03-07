/*
*    Filename: 1294.cpp
*    Description: NULL
*    Last modified: 2015-03-07 19:59
*
*    Created by Eleven on 2015-03-07
*    Email: eleveneat@gmail.com
*    Copyright (C) 2015 Eleven. All rights reserved.
*/
#include <iostream>

using namespace std;

int main() {
    int a, b, c, value;
    cin >> a >> b >> c;
    value = a;
    for (int i = 1; i < b; i++) {
        value = value * a % c;
    }
    cout << value << endl;
    return 0;
}

