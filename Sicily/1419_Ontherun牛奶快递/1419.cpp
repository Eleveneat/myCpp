/*
*    Filename: 1419.cpp
*    Description: NULL
*    Last modified: 2015-03-13 21:46
*
*    Created by Eleven on 2015-03-13
*    Email: eleveneat@gmail.com
*    Copyright (C) 2015 Eleven. All rights reserved.
*/
#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

int t1[1005][1005], t2[1005][1005];

int main() {
    int testNum, N, L, pos;
    int a[1005];
    cin >> testNum;
    while (testNum--) {
        cin >> N >> L;
        for (int i = 0; i < N; i++)
            cin >> a[i];
        a[N++] = L;
        sort(a, a+N);
        pos = 0;
        while (a[pos] < L)
            pos++;
        memset(t1, 1100, 1005*1005*sizeof(int));
        memset(t2, 1100, 1005*1005*sizeof(int));
        t1[pos][pos] = t2[pos][pos] = 0;
        for (int i = pos; i >= 0; i--) {
            for (int j = pos; j < N; j++) {
                if (i < pos) {
                    t1[i][j] = min(t1[i+1][j] + (a[i+1] - a[i])*(N - (j-i)),
                                   t2[i+1][j] + (a[j] - a[i])*(N - (j-i)));
                }
                if (j > pos) {
                    t2[i][j] = min(t1[i][j-1] + (a[j] - a[i])*(N - (j-i)),
                                   t2[i][j-1] + (a[j] - a[j-1])*(N - (j-i)));
                }
            }
        }
        cout << min(t1[0][N-1], t2[0][N-1]) << endl;
    }
    return 0;
}

