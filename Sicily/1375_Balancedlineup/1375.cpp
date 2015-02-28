/*
*    Filename: 1375.cpp
*    Description: NULL
*    Last modified: 2015-02-16 16:23
*
*    Created by Eleven on 2015-02-16
*    Email: eleveneat@gmail.com
*    Copyright (C) 2015 Eleven. All rights reserved.
*/
#include <iostream>
#include <algorithm>

using namespace std;

const int Max_num=51000;

struct Cow {
    int breed;
    int x; // coordinate.
};

bool cmp (const Cow& c1, const Cow& c2) {
    return c1.x < c2.x;
}

int main() {
    int n, max = -1;
    Cow cow[Max_num];
    int sums[Max_num], sums_position[Max_num] = {0};
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> cow[i].breed >> cow[i].x;
        if (0 == cow[i].breed)
            cow[i].breed = -1;
    }
    sort(cow+1, cow+n+1, cmp);
    sums[0] = 0;
    for (int i = 1; i <=n; i++) {
        sums[i] = sums[i-1] + cow[i].breed;
        if (0 == sums_position[sums[i]]) {
            sums_position[sums[i]] = i;
        } else {
            if (max < cow[i].x - cow[sums_position[sums[i]]+1].x)
                max = cow[i].x - cow[sums_position[sums[i]]+1].x;
        }
    }
    cout << max << endl;
    return 0;
}

