/*
*    Filename: 1210.cpp
*    Description: NULL
*    Last modified: 2015-02-09 15:55
*
*    Created by Eleven on 2015-02-09
*    Email: eleveneat@gmail.com
*    Copyright (C) 2015 Eleven. All rights reserved.
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    string pre, post;
    int len, postIndex, count = 1;
    cin >> pre >> post;
    len = pre.length();
    for (int i = 1; i < len; i++) {
        postIndex = len - 2;
        while (pre[i] != post[postIndex])
            postIndex--;
        if (pre[i-1] == post[postIndex+1])
            count *= 2;
    }
    cout << count;
    return 0;
}

