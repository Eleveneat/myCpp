/*
*    Filename: 1046.cpp
*    Description: NULL
*    Last modified: 2015-02-09 16:57
*
*    Created by Eleven on 2015-02-09
*    Email: eleveneat@gmail.com
*    Copyright (C) 2015 Eleven. All rights reserved.
*/
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

struct period {
    double perQuarter;
    int totalQuarter, startQuarter, endQuarter;
};

bool cmp(const period& p1, const period& p2) {
    if (p1.perQuarter == p2.perQuarter && p1.totalQuarter == p2.totalQuarter)
        return p1.endQuarter < p2.endQuarter;
    else if (p1.perQuarter == p2.perQuarter)
        return p1.totalQuarter > p2.totalQuarter;
    else
        return p1.perQuarter > p2.perQuarter;
}

int main() {
    int quarterNum, reQuarter, min;
    int testNum, index, planeNum;
    int a[310];
    period allPeriod[100000];
    cin >> testNum;
    for (int num = 1; num <= testNum; num++) {
        index = 0;
        memset(a, 0, sizeof(a));
        memset(allPeriod, 0, sizeof(allPeriod));
        cin >> quarterNum >> reQuarter >> min;
        for (int i = 0; i < quarterNum; i++)
            cin >> a[i];
        for (int i = 0; i < quarterNum - min + 1; i++) {
            for (int j = i + min - 1; j < quarterNum; j++) {
                planeNum = 0;
                for (int tmp = i; tmp <= j; tmp++)
                    planeNum += a[tmp];
                allPeriod[index].perQuarter = (planeNum + 0.0)/ (j - i + 1);
                allPeriod[index].totalQuarter = j - i + 1;
                allPeriod[index].startQuarter = i + 1;
                allPeriod[index].endQuarter = j + 1;
                index++;
            }
        }
        sort(allPeriod, allPeriod + index, cmp);
        cout << "Result for run " << num << ":" << endl;
        for (int i = 0; i < reQuarter && i < index; i++)
            cout << allPeriod[i].startQuarter << "-" << allPeriod[i].endQuarter << endl;
    }
    return 0;
}

