/*
*    Filename: 1934.cpp
*    Description:
*       1. 如果用小球的绝对位置来做，每动一个小球其他小球的
*          位置信息都要改，应该会超时，如果只用相对位置做的
*          话，每次只要改几个相关小球的位置信息就好了，效率
*          高很多。
*    Last modified: 2015-02-15 14:11
*
*    Created by Eleven on 2015-02-15
*    Email: eleveneat@gmail.com
*    Copyright (C) 2015 Eleven. All rights reserved.
*/
#include <iostream>

using namespace std;

struct node {
    int l, r;
};
int main() {
    int testNum, n, m, command, x, y;
    node allNodes[501000];
    cin >> testNum;
    while (testNum--) {
        cin >> n >> m;
        for (int i = 0; i <= n + 1; i++) {
            allNodes[i].l = i - 1;
            allNodes[i].r = i + 1;
        }
        for (int i = 0; i < m; i++) {
            cin >> command >> x >> y;
            allNodes[allNodes[x].l].r = allNodes[x].r;
            allNodes[allNodes[x].r].l = allNodes[x].l;
            if (1 == command) {
                allNodes[x].l = allNodes[y].l;
                allNodes[x].r = y;
                allNodes[allNodes[y].l].r = x;
                allNodes[y].l = x;
            } else {
                allNodes[x].r = allNodes[y].r;
                allNodes[x].l = y;
                allNodes[allNodes[y].r].l = x;
                allNodes[y].r = x;
            }
        }
        for (int next = allNodes[0].r; next != n + 1; next = allNodes[next].r)
            cout << next << ' ';
        cout << endl;
    }
    return 0;
}
