/*
*    Filename: 1510.cpp
*    Description: NULL
*    Last modified: 2015-02-27 20:25
*
*    Created by Eleven on 2015-02-27
*    Email: eleveneat@gmail.com
*    Copyright (C) 2015 Eleven. All rights reserved.
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    int testNum, pos;
    string str;
    cin >> testNum;
    for (int i = 1; i <= testNum; i++) {
        cin >> pos >> str;
        cout << i << " ";
        for (int j = 0; j < str.length(); j++)
            if (j != pos - 1)
                cout << str[j];
        cout << endl;
    }
    return 0;
}

