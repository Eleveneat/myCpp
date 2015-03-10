/*
*    Filename: 1342.cpp
*    Description: NULL
*    Last modified: 2015-03-10 22:31
*
*    Created by Eleven on 2015-03-10
*    Email: eleveneat@gmail.com
*    Copyright (C) 2015 Eleven. All rights reserved.
*/
#include <iostream>
#include <memory.h>

using namespace std;

int main() {
    int totalMomey, num, price, value;
    int a[31000];
    while (cin >> totalMomey >> num) {
        memset(a, 0, 31000*sizeof(int));
        for (int i = 0; i < num; i++) {
            cin >> price >> value;
            for (int j = totalMomey; j >= price; j--) {
                if (a[j-price] + price * value > a[j])
                    a[j] = a[j-price] + price * value;
            }
        }
        cout << a[totalMomey] << endl;
    }
    return 0;
}

