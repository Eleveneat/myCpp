/*
*    Filename: 1145.cpp
*    Description: NULL
*    Last modified: 2015-03-10 14:56
*
*    Created by Eleven on 2015-03-10
*    Email: eleveneat@gmail.com
*    Copyright (C) 2015 Eleven. All rights reserved.
*/
#include <iostream>
#include <memory.h>

using namespace std;

int main() {
    int a[20000], L, M, from, to, count = 0;
    cin >> L >> M;
    memset(a, 1, 20000 * sizeof(int));
    for (int i = 0; i < M; i++) {
        cin >> from >> to;
        for (int j = from; j <= to; j++)
            a[j] = 0;
    }
    for (int i = 0; i <= L; i++) {
        if (a[i])
            count++;
    }
    cout << count << endl;
    return 0;
}

