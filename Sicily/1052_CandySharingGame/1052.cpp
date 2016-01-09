/*
*    Filename: 1052.cpp
*    Description: NULL
*    Last modified: 2016-01-09 10:35
*
*    Created by Eleven on 2015-03-16
*    Email: eleveneat@gmail.com
*    Copyright (C) 2015 Eleven. All rights reserved.
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, count;
    vector<int> v;
    while (cin >> n && n) {
        v.clear();
        count = 0;

        for (int i = 0; i < n; i++) {
            int tmp;
            cin >> tmp;
            v.push_back(tmp);
        }
        if (n == 1) {
            cout << "0 " << v[0] << endl;
            continue;
        }

        while (1) {
            count++;

            // 同时减半
            for (int i = 0; i < v.size(); i++)
                v[i] /= 2;

            // 逆时针分给同伴
            int preValue = v[0];
            for (int i = 1; i < v.size(); i++) {
                int value = v[i];
                v[i] += preValue;
                preValue = value;
            }
            v[0] += preValue;

            // 奇数＋1
            for (int i = 0; i < v.size(); i++)
                if (v[i] & 1)
                    v[i]++;

            // 判断是否相等
            bool isSame = true;
            for (int i = 1; i < v.size(); i++) {
                if (v[i] != v[i-1]) {
                    isSame = false;
                    break;
                }
            }
            if (isSame)
                break;
        }

        cout << count << " " << v[0] << endl;
    }
    return 0;
}

