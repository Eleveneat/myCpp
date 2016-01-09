/*
*    Filename: 1059.cpp
*    Description: 1. 由于求两直线交点只需两条直线即可，所以先通过向量旋转分别得到D、G、F、H。
*                 2. 求DG中点L和FH中点N，然后求直线LA和NC的交点。
*                 3. 求两直线交点有三种情况：LA无斜率、NC无斜率以及都有斜率。
*    Last modified: 2016-01-09 12:42
*
*    Created by Eleven on 2015-01-09
*    Email: eleveneat@gmail.com
*    Copyright (C) 2015 Eleven. All rights reserved.
*/
#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

const double PI = 3.1415926535897932384626433832795;
const double EPS = 1e-8;

struct Point {
    double x, y;
    Point() {}
    Point(double xx, double yy) : x(xx), y(yy) {}

    double operator*(const Point& p) { // 计算叉乘
        return x * p.y - p.x * y;
    }
    Point operator+(const Point& p) {
        return Point(x + p.x, y + p.y);
    }
    Point operator-(const Point& p) {
        return Point(x - p.x, y - p.y);
    }
};

Point rotate(Point p, double angle) {
    Point newP;
    newP.x = p.x * cos(angle) - p.y * sin(angle);
    newP.y = p.x * sin(angle) + p.y * cos(angle);
    return newP;
}

double area(Point& A, Point& B, Point& C) { // 三角形面积 
    return ((B-A)*(C-A) / 2.0);
}

Point noSlop(double x, Point& p1, Point& p2) { // 无斜率
    Point result;
    double k = (p1.y - p2.y) / (p1.x - p2.x);
    double b = p1.y - k * p1.x;
    result.x = x;
    result.y = k * x + b;
    return result;
}

Point withSlop(Point& p1, Point& p2, Point& p3, Point& p4) { // 都有斜率 
    Point result;
    double k1 = (p1.y - p2.y) / (p1.x - p2.x);
    double b1 = p1.y - k1 * p1.x;
    double k2 = (p3.y - p4.y) / (p3.x - p4.x);
    double b2 = p3.y - k2 * p3.x;
    result.x = (b1 - b2) / (k2 - k1);
    result.y = k1 * result.x + b1;
    return result;
}

Point intersection(Point& p1, Point& p2, Point& p3, Point& p4) { // 求直线交点
    Point result;
    if (fabs(p1.x - p2.x) < EPS) {
        result = noSlop(p1.x, p3, p4);
    } else if (fabs(p3.x-p4.x) < EPS) {
        result = noSlop(p3.x, p1, p2);
    } else {
        result = withSlop(p1, p2, p3, p4);
    }
    return result;
}

double fix(double x) {
    if (x < -EPS ? -1 : x > EPS)
        return x;
    else
        return 0;
}

int main() {
    Point A, B, C;
    Point D, G, F, H, L, N, O;
    int n;
    cin >> n;
    while (n--) {
        scanf("%lf%lf", &A.x, &A.y);
        scanf("%lf%lf", &B.x, &B.y);
        scanf("%lf%lf", &C.x, &C.y);

        if (area(A, B, C) < 0)
            swap(B, C);

        // 如向量AB=(B-A),旋转90后，变成AD=(D-A); 所以D = Rotate(B-A,-PI/2) + A
        D = rotate(B - A, -PI / 2) + A;
        G = rotate(C - A, PI / 2) + A;
        L = D + G;
        L.x /= 2; L.y /= 2;

        F = rotate(A - C,-PI/2) + C;
        H = rotate(B - C, PI/2) + C;
        N = F + H;
        N.x /= 2; N.y /= 2;
        O = intersection(A, L, C, N);
        printf("%.4lf %.4lf\n", fix(O.x), fix(O.y));
    }
    return 0;
}

