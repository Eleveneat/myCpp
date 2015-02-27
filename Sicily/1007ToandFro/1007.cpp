/*
*    Filename: 1007.cpp
*    Description: NULL
*    Last modified: 2015-02-27 19:34
*
*    Created by Eleven on 2015-02-27
*    Email: eleveneat@gmail.com
*    Copyright (C) 2015 Eleven. All rights reserved.
*/
#include <iostream>
#include <string.h>
#include <memory.h>

using namespace std;

int main() {
    char a[220][220], str[220];
    int columns, x, y;
    while (cin >> columns && columns) {
        cin >> str;
        x = y = 0;
        for (int i = 0; i < strlen(str); i++) {
            if (0 == x % 2)
                a[x][y] = str[i];
            else
                a[x][columns - 1 - y] = str[i];
            y = (y + 1) % columns;
            if (0 == y) x++;
        }
        for (int i = 0; i < columns; i++) {
            for (int j = 0; j < x; j++) {
                cout << a[j][i];
            }
        }
        cout << endl;
    }
    return 0;
}

