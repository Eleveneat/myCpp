/*
*    Filename: 1022.cpp
*    Description: NULL
*    Last modified: 2015-02-17 12:12
*
*    Created by Eleven on 2015-02-17
*    Email: eleveneat@gmail.com
*    Copyright (C) 2015 Eleven. All rights reserved.
*/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct contestant {
    string name;
    int x; // the number of problems solved.
};

contestant a[101000];
int len;

bool cmp(const contestant& c1, const contestant& c2) {
    return c1.x < c2.x;
}

void add() {
    cin >> a[len].name >> a[len].x;
    len++;
}

void query() {
    if (0 == len % 2) {
        cout << "No one!" << endl;
    } else {
        sort(a, a+len, cmp);
        cout << a[len/2].name << endl;
    }
}

void end() {
    if (0 == len % 2) {
        cout << "Happy BG meeting!!" << endl;
    } else {
        sort(a, a+len, cmp);
        cout << a[len/2].name << " is so poor." << endl;
    }
    cout << endl;
}

int main() {
    int testNum;
    string command;
    cin >> testNum;
    while (testNum--) {
        len = 0;
        while (cin >> command) {
            if ("Add" == command) {
                add();
            } else if ("Query" == command) {
                query();
            } else {
                end();
                break;
            }
        }
    }
    return 0;
}
