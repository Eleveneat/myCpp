/*
*    Filename: 1211.cpp
*    Description: NULL
*    Last modified: 2016-01-10 10:47
*
*    Created by Eleveneat on 2016-01-10
*    Email: eleveneat@gmail.com
*    Copyright (C) 2016 Eleveneat. All rights reserved.
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

#define MAX 105

using namespace std;

int main() {
    int n, m, l, q;
    int dp[MAX][MAX][MAX];
    vector<int> roads[MAX];

    memset(dp, 0, sizeof(dp) );

    scanf("%d%d%d", &n, &m, &l);

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        roads[a].push_back(b); // 在a州添加一条到b州的路
        dp[a][b][1] = 1; // 从a到b在一天内的走法为一种
    }

    for (int day = 2; day <= l; day++) {
        for (int i = 1; i <= n; i++) {
            int len = roads[i].size();
            for (int j = 1; j <= n; j++) {
                for (int x = 0; x < len; x++) {
                    dp[i][j][day] += dp[ roads[i][x] ][j][day - 1]; // 状态转移方程
                }
            }
        }
    }

    scanf("%d", &q);
    while (q--) {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", dp[a][b][l]);
    }

    return 0;
}

