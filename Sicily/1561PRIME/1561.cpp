/*
*    Filename: 1561.cpp
*    Description: NULL
*    Last modified: 2015-02-27 19:57
*
*    Created by Eleven on 2015-02-27
*    Email: eleveneat@gmail.com
*    Copyright (C) 2015 Eleven. All rights reserved.
*/
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n, count = 0;
    int key;
    bool isPrime;
    cin >> n;
    for (int i = 2; count != n; i++) {
        isPrime = true;
        for (int j = 1; j <= sqrt(i); j++) {
            if (0 == i % j && j != 1) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            count++;
            key = i;
        }
    }
    cout << key << endl;
    return 0;
}

