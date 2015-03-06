/*
*    Filename: 1815.cpp
*    Description: NULL
*    Last modified: 2015-02-28 14:44
*
*    Created by Eleven on 2015-02-28
*    Email: eleveneat@gmail.com
*    Copyright (C) 2015 Eleven. All rights reserved.
*/
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

struct point {
    double x, y;
};

int main() {
    int testNum;
    point p1, p2;
    double value;
    cin >> testNum;
    while (testNum--) {
        cin >> p1.x >> p1.y >> p2.x >> p2.y;
        value = sqrt(pow(p1.x-p2.x, 2) + pow(p1.y-p2.y, 2));
        cout << fixed << setprecision(2) << value << endl;
    }
    return 0;
}
