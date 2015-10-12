/*
*    Filename: 1009.cpp
*    Description: NULL
*    Last modified: 2015-10-12 20:09
*
*    Created by Eleveneat on 2015-10-12
*    Email: eleveneat@gmail.com
*    Copyright (C) 2015 Eleveneat. All rights reserved.
*/

#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(long long);
long long getCompositeNum(long long);

int main() {
    int num;
    long long mersenneNum, compositeNum, restNum;
    cin >> num;
    for (int i = 1; i <= num; i++) {
        if (61 == i)
            continue; // Ignore 61, because it takes a long time to compute...
        if (!isPrime(i))
            continue;
        mersenneNum = (long long)pow(2.0, i) - 1;
        compositeNum = getCompositeNum(mersenneNum);
        if (0 != compositeNum) {
            cout << compositeNum;
            restNum = mersenneNum / compositeNum;
            while (!isPrime(restNum)) {
                compositeNum = getCompositeNum(restNum);
                cout << " * " << compositeNum;
                restNum /= compositeNum;
            }
            cout << " * " << restNum << " = " << mersenneNum << " = ( 2 ^ "
                << i << " ) - 1" << endl;
        }
    }
    return 0;
}

bool isPrime(long long n) {
    if (n <= 1)
        return false;
    for (long long i = 2; i * i <= n; i++)
        if (0 == n % i)
            return false;
    return true;
}

long long getCompositeNum(long long n) {
    long long compositeNum = 0;
    for (long long i = 2; i * i <= n; i++) {
        if (0 == n % i) {
            compositeNum = i;
            break;
        }
    }
    return compositeNum;
}


