/*
*    Filename: 1146.cpp
*    Description: NULL
*    Last modified: 2015-03-10 17:01
*
*    Created by Eleven on 2015-03-10
*    Email: eleveneat@gmail.com
*    Copyright (C) 2015 Eleven. All rights reserved.
*/
#include <iostream>

using namespace std;

int main() {
    int a[2000] = {0};
    int T, M, time, value;
    cin >> T >> M;
    for (int i = 0; i < M; i++) {
        cin >> time >> value;
        for (int j = T; j >= time; j--) {
            if (a[j-time] + value > a[j])
                a[j] = a[j-time] + value;
        }
    }
    cout << a[T] << endl;
    return 0;
}

