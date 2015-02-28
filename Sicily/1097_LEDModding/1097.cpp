/*
*    Filename: 1097.cpp
*    Description: NULL
*    Last modified: 2015-02-11 14:52
*
*    Created by Eleven on 2015-02-11
*    Email: eleveneat@gmail.com
*    Copyright (C) 2015 Eleven. All rights reserved.
*/
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

struct resistor {
    string name;
    int r; // Resistance
};

bool cmp (const resistor& re1, const resistor& re2) {
    return re1.r < re2.r;
}

int main() {
    int USB, LED_V, LED_mA, N;
    double Optimum_Res;
    while (cin >> USB >> LED_V >> LED_mA >> N) {
        resistor a[51000];
        for (int i = 0; i < N; i++)
            cin >> a[i].name >> a[i].r;
        if (USB <= 0) {
            cout << "IMPOSSIBLE" << endl;
            continue;
        } else if (USB <= LED_V) {
            cout << "---" << endl;
            continue;
        }
        Optimum_Res = (USB - LED_V + 0.0) / LED_mA * 1000.0;
        sort(a, a+N, cmp);
        if ((!N) || (a[N-1].r < Optimum_Res)) {
            cout << "IMPOSSIBLE" << endl;
            continue;
        }
        for (int i = 0; i < N; i++) {
            if (a[i].r >= Optimum_Res) {
                cout << fixed << setprecision(2)
                     << Optimum_Res << " " << a[i].name << endl;
                break;
            }
        }
    }
    return 0;
}
