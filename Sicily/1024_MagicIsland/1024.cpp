/*
*    Filename: 1024.cpp
*    Description: NULL
*    Last modified: 2015-10-18 11:50
*
*    Created by Eleveneat on 2015-10-18
*    Email: eleveneat@gmail.com
*    Copyright (C) 2015 Eleveneat. All rights reserved.
*/

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

#define MAXCITY 10010

struct road {
    int id;
    int toCity;
    int distance;
    road(int i, int t, int d) {
        id = i;
        toCity = t;
        distance = d;
    }
};

bool isVisted[MAXCITY];
vector<road> city[MAXCITY];
int curDis, maxDis;

void dfs(int n) {
    for (int i = 0; i < city[n].size(); i++) {
        int id = city[n][i].id;
        if (isVisted[id] == true)
            continue;

        isVisted[id] = true;
        curDis += city[n][i].distance;

        dfs(city[n][i].toCity);

        isVisted[id] = false;
        curDis -= city[n][i].distance;
    }
    if (curDis > maxDis)
        maxDis = curDis;
}

int main() {
    int cityNum, capitalPos;
    while (scanf("%d%d", &cityNum, &capitalPos) != EOF) {
        for (int i = 0; i <= cityNum; i++) {
            city[i].clear();
            isVisted[i] = false;
        }
        int x, y, distance;
        for (int i = 1; i < cityNum; i++) {
            scanf("%d%d%d", &x, &y, &distance);
            city[x].push_back(road(i, y, distance));
            city[y].push_back(road(i, x, distance));
        }
        curDis = maxDis = 0;
        dfs(capitalPos);
        printf("%d\n", maxDis);
    }
    return 0;
}

