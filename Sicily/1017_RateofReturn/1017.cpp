/*
*    Filename: 1017.cpp
*    Description: NULL
*    Last modified: 2016-01-12 10:34
*
*    Created by Eleveneat on 2016-01-12
*    Email: eleveneat@gmail.com
*    Copyright (C) 2016 Eleveneat. All rights reserved.
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

#define SIZE 15

using namespace std;

const double EPS = 1e-6;

bool dcmp(double x) {
    return (x > -EPS && x < EPS) ? 0 : 1;
}

int main() {
    int n, count, lastMonth, month[SIZE];
    double lastMoney, rate, bRate, eRate, sumMoney, money[SIZE];
    count = 0;
    while (scanf("%d", &n) && n != -1) {
        count++;
        memset(month, 0, sizeof(month) );
        memset(money, 0, sizeof(money) );
        
        for (int i = 0; i < n; i++) {
            scanf("%d%lf", &month[i], &money[i]);
        }
        scanf("%d%lf", &lastMonth, &lastMoney);

        rate = 1.5; bRate = 1.0; eRate = 2.0; sumMoney = 0;
        for (int i = 0; i < n; i++)
            sumMoney += money[i] * pow(rate, lastMonth - month[i] + 1);

        while(dcmp(sumMoney - lastMoney) && eRate - bRate > EPS) {
            if (sumMoney > lastMoney)
                eRate = rate;
            else
                bRate = rate;

            rate = (bRate + eRate) / 2;
            sumMoney = 0;
            for (int i = 0; i < n; i++)
                sumMoney += money[i] * pow(rate, lastMonth - month[i] + 1);
        }

        if (count > 1)
            printf("\nCase %d: %.5lf\n", count, rate - 1);
        else
            printf("Case %d: %.5lf\n", count, rate - 1);
    }
    return 0;
}

