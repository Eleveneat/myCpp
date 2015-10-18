/*
*    Filename: 1024.cpp
*    Description: NULL
*    Last modified: 2015-10-18 10:15
*
*    Created by Eleveneat on 2015-10-18
*    Email: eleveneat@gmail.com
*    Copyright (C) 2015 Eleveneat. All rights reserved.
*/

#include <iostream>
#include <vector>

using namespace std;

struct city {  
    int lPos, rPos;
    int lDist, rDist;
    bool isVisted;
};

vector<city> arr;
int maxDis, curDis;

void dfs(int pos, int prePos) {
    if (curDis > maxDis)
        maxDis = curDis;

    if (arr[pos].isVisted == true)
        return;

    arr[pos].isVisted = true;

    int preDis = curDis;
    city thisCity = arr[pos];
    if (thisCity.lPos != -1 && thisCity.lPos != prePos) {
        curDis += thisCity.lDist;
        dfs(thisCity.lPos, pos);
        curDis = preDis;
    }
    if (thisCity.rPos != -1 && thisCity.rPos != prePos) {
        curDis += thisCity.rDist;
        dfs(thisCity.rPos, pos);
        curDis = preDis;
    }

    arr[pos].isVisted = false;
}

void pushCity(int x, int y, int distance) {
    if (arr[x].lPos == -1) {
        arr[x].lPos = y;
        arr[x].lDist = distance;
    } else {
        arr[x].rPos = y;
        arr[x].rDist = distance;
    }
}

void initArr(int num) {
    // 创建 num + 1 空间大小的Vector
    for (int i = 0; i <= num; i++) {
        city nullCity = {-1, -1, -1, -1, false};
        arr.push_back(nullCity);
    }
}

int main() {
    int cityNum, capitalPos;
    while (cin >> cityNum >> capitalPos) {
        arr.clear();
        initArr(cityNum);
        maxDis = -1;

        int x, y, distance;
        for (int i = 0; i < cityNum - 1; i++) {
            cin >> x >> y >> distance;
            pushCity(x, y, distance);
            pushCity(y, x, distance);
        }

        curDis = 0;
        dfs(capitalPos, 0);
        if (maxDis == -1)
            cout << 0 << endl;
        else
            cout << maxDis << endl;
    }
    return 0;
}

