/*
*    Filename: 1817.cpp
*    Description: NULL
*    Last modified: 2015-03-06 20:27
*
*    Created by Eleven on 2015-03-06
*    Email: eleveneat@gmail.com
*    Copyright (C) 2015 Eleven. All rights reserved.
*/
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <iomanip>
#include <cstdio>

using namespace std;

struct player {
    double average;
    int score[110];
};
int main() {
    int testNum;
    int n, m;
    //cin >> testNum;
    scanf("%d", &testNum);
    while (testNum--) {
        player a[110];
        //cin >> n >> m;
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                //cin >> a[j].score[i];
                scanf("%d", &a[j].score[i]);
            }
        }
        for (int i = 0; i < m; i++) {
            sort(a[i].score, a[i].score + n);
            a[i].average = 0;
            for (int j = 1; j < n-1; j++)
                a[i].average += (a[i].score[j] + 0.0);
            a[i].average = (a[i].average + 0.0) / (n - 2);
            //cout << fixed << setprecision(2) << a[i].average << endl;
            printf("%.2f\n", a[i].average);
        }
    }
    return 0;
}

