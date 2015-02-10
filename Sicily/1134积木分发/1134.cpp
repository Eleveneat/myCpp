/*
*    Filename: 1134.cpp
*    Description: NULL
*    Last modified: 2015-02-10 13:54
*
*    Created by Eleven on 2015-02-10
*    Email: eleveneat@gmail.com
*    Copyright (C) 2015 Eleven. All rights reserved.
*/
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

struct kid {
    int own, need;
};

bool cmp(const kid& k1, const kid& k2) {
    return k1.need < k2.need;
}

int main() {
    int n, s;
    bool flag;
    kid allKids[10010];
    while ((cin >> n >> s) && (n != 0)) {
        flag = true;
        memset(allKids, 0, sizeof(allKids));
        for (int i = 0; i < n; i++)
            cin >> allKids[i].own >> allKids[i].need;
        sort(allKids, allKids + n, cmp);
        for (int i = 0; i < n; i++) {
            if (s < allKids[i].need) {
                flag = false;
                break;
            } else {
                s += allKids[i].own;
            }
        }
        if (flag)cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}

