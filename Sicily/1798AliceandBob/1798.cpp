/*
*    Filename: 1798.cpp
*    Description: NULL
*    Last modified: 2015-02-27 20:37
*
*    Created by Eleven on 2015-02-27
*    Email: eleveneat@gmail.com
*    Copyright (C) 2015 Eleven. All rights reserved.
*/
#include <iostream>

using namespace std;

int main() {
    int n;
    while (cin >> n && n) {
        if (0 == n % 2)
            cout << "Alice" << endl;
        else
            cout << "Bob" << endl;
    }
    return 0;
}

