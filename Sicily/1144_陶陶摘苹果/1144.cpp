/*
*    Filename: 1144.cpp
*    Description: NULL
*    Last modified: 2015-03-10 14:47
*
*    Created by Eleven on 2015-03-10
*    Email: eleveneat@gmail.com
*    Copyright (C) 2015 Eleven. All rights reserved.
*/
#include <iostream>

using namespace std;

int main() {
    int apple[15], height, count = 0;
    for (int i = 0; i < 10; i++) {
        cin >> apple[i];
    }
    cin >> height;
    for (int i = 0; i < 10; i++) {
        if (apple[i] <= height + 30)
            count++;
    }
    cout << count << endl;
    return 0;
}

