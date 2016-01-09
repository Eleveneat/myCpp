/*
*    Filename: 1012.cpp
*    Description: NULL
*    Last modified: 2016-01-09 09:47
*
*    Created by Eleven on 2015-03-16
*    Email: eleveneat@gmail.com
*    Copyright (C) 2015 Eleven. All rights reserved.
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cmath>

using namespace std;

const double DIAMETER = 2.0;

int main() {
    vector<double> v;
    double x, y;
    int n;
    while (cin >> n && n) {
        v.clear();
        for (int i = 0; i < n; i++) {
            cin >> x;
            v.push_back(x);
        }
        sort(v.begin(), v.end());

        x = v.front();
        y = DIAMETER / 2;

        for (int i = 1; i < n; i++) {
            double preX = x;
            x = (v[i] - v[0]) / 2 + v[0]; // 上一层的最左边球的横坐标。
            double bottomMargin = x - preX;
            y += sqrt( pow(DIAMETER, 2) - pow(bottomMargin, 2) ); // 上一层的最左边球的纵坐标，利用勾股定理。
        }

        printf("%.4lf %.4lf\n", x, y);
    }

    return 0;
}

