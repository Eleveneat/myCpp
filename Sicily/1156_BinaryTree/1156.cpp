/*
*    Filename: 1156.cpp
*    Description: NULL
*    Last modified: 2015-10-17 10:09
*
*    Created by Eleveneat on 2015-10-17
*    Email: eleveneat@gmail.com
*    Copyright (C) 2015 Eleveneat. All rights reserved.
*/

#include <iostream>

using namespace std;

struct Node {
    char c;
    int l, r;
    bool isChild;
};

Node arr[1010];

void print(int n) {
    cout << arr[n].c;
    int l = arr[n].l;
    int r = arr[n].r;
    if (l != 0)
        print(l);
    if (r != 0)
        print(r);
}

int main() {
    int testNum;
    int pos[1010];
    while (cin >> testNum) {
        for (int i = 0; i < testNum; i++) {
            int n, l, r;
            char value;
            cin >> n >> value >> l >> r;
            pos[i] = n;
            arr[n].c = value;
            arr[n].l = l;
            arr[n].r = r;
            arr[n].isChild = false;
        }
        // 使所有子节点的isChild属性为true
        for (int i = 0; i < testNum; i++) {
            int l = arr[pos[i]].l;
            int r = arr[pos[i]].r;
            if (l != 0)
                arr[l].isChild = true;
            if (r != 0)
                arr[r].isChild = true;
        }
        int root;
        // 寻找根节点
        for (int i = 0; i < testNum; i++) {
            if (arr[pos[i]].isChild == false) {
                root = pos[i];
                break;
            }
        }
        print(root);
        cout << endl;
    }
    return 0;
}

