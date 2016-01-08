/*
*    Filename: 1004.cpp
*    Description: NULL
*    Last modified: 2016-01-08 11:48
*
*    Created by Eleven on 2015-03-16
*    Email: eleveneat@gmail.com
*    Copyright (C) 2015 Eleven. All rights reserved.
*/
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const double MAXSLOPE = 99999;

// 需要注意两个浮点类型的数不能简单地以“==”符号来判断。
// 1e-6代表的是1乘以10的-6次方。
bool equal (double a, double b) {
    return fabs(a-b) < 1e-6;
}

struct Line {
    double k, b, x1, x2, y1, y2;
    bool operator<(const Line& other) const {
        if (equal(k, other.k)) {
            if (k == MAXSLOPE) { // 没有斜率的情况
                if (equal(b, other.b)) {
                    if (y1 == other.y1)
                        return y2 < other.y2;
                    else
                        return y1 < other.y1;
                } else {
                    return b < other.b;
                }
            }
            
            if (equal(b, other.b)) {
                if (x1 == other.x1)
                    return x2 < other.x2;
                else
                    return x1 < other.x1;
            } else {
                return b < other.b;
            }
        } else {
            return k < other.k;
        }
    }
} allLines[10010];

int main() {
    int n;
    while (cin >> n && n) {
        double x1, x2, y1, y2;
        for (int i = 0; i < n; i++) {
            cin >> x1 >> y1 >> x2 >> y2;
            if (x1 > x2 || (x1 == x2 && y1 > y2)) {
                swap(x1, x2); swap(y1, y2);
            }

            allLines[i].x1 = x1; allLines[i].x2 = x2;
            allLines[i].y1 = y1; allLines[i].y2 = y2;

            if (x1 == x2) { // 没有斜率的情况
                allLines[i].k = MAXSLOPE;
                allLines[i].b = x1;
            } else {
                allLines[i].k = (y2 - y1) / (x2 - x1);
                allLines[i].b = y1 - allLines[i].k * x1;
            }
        }

        sort(allLines, allLines + n);

        int count = 1;
        double xEnd = allLines[0].x2;
        double yEnd = allLines[0].y2;
        for (int i = 1; i < n; i++) {
            if (!equal(allLines[i].k, allLines[i-1].k) ||
                !equal(allLines[i].b, allLines[i-1].b) ) {
                // k和b不相等的情况，肯定不再同一直线。
                count++;
                xEnd = allLines[i].x2;
                yEnd = allLines[i].y2;
            } else if ( (allLines[i].k != MAXSLOPE && allLines[i].x1 > xEnd) ||
                        (allLines[i].k == MAXSLOPE && allLines[i].y1 > yEnd) ) {
                // 在同一直线但没有公共部分
                count++;
                xEnd = allLines[i].x2;
                yEnd = allLines[i].y2;
            } else if ( (allLines[i].k != MAXSLOPE && allLines[i].x2 > xEnd) ||
                        (allLines[i].k == MAXSLOPE && allLines[i].y2 > yEnd) ) {
                // 在同一直线有公共部分且当前线段终点更远
                xEnd = allLines[i].x2;
                yEnd = allLines[i].y2;
            }
        }

        cout << count << endl;
    }
    return 0;
}

