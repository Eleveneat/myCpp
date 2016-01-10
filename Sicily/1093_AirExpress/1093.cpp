/*
*    Filename: 1093.cpp
*    Description: NULL
*    Last modified: 2016-01-10 12:13
*
*    Created by Eleveneat on 2016-01-10
*    Email: eleveneat@gmail.com
*    Copyright (C) 2016 Eleveneat. All rights reserved.
*/

#include <iostream>
#include <cstdio>
#include <cstring>

#define WEIGHT_RANGE_SIZE 4
#define WEIGHT_SIZE 1010

using namespace std;

int main() {
    int weight[WEIGHT_RANGE_SIZE];
    int rate[WEIGHT_SIZE];
    int w, r, n;
    int count = 0;
    while (scanf("%d%d", &w, &r) != EOF) {
        count++;
        memset(weight, 0, sizeof(weight) );
        memset(rate, 0, sizeof(rate) );

        weight[0] = w + 1;
        for (int i = 0; i <= w; i++)
            rate[i] = r;

        for (int i = 1; i <= 2; i++) {
            scanf("%d%d", &w, &r);
            weight[i] = w + 1;
            for (int j = weight[i-1]; j <= w; j++)
                rate[j] = r;
        }

        scanf("%d", &r);
        weight[3] = 1000;
        for (int i = weight[2]; i <= 1000; i++)
             rate[i] = r;

        printf("Set number %d:\n", count);
        while (scanf("%d", &n) && n) {
            int ori = n * rate[n];
            int next = 0;
            for (int i = 0; i < WEIGHT_RANGE_SIZE; i++) {
                if (weight[i] > n) {
                    next = weight[i];
                    break;
                }
            }
            int nextValue = next * rate[next];
            int result = 0;
            int add = 0;
            if (nextValue < ori) {
                result = nextValue;
                add = next - n;
            } else {
                result = ori;
            }
            printf("Weight (%d) has best price $%d (add %d pounds)\n", n, result, add);
        }
        printf("\n");
    }
    return 0;
}

