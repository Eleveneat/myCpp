// Problem#: 1051
// Submission#: 3848922
/*
*    Filename: 1051.cpp
*    Description: NULL
*    Last modified: 2015-09-26 14:52
*
*    Created by Eleveneat on 2015-09-26
*    Email: eleveneat@gmail.com
*    Copyright (C) 2015 Eleveneat. All rights reserved.
*/

#include <iostream>
#include <cstdio>

using namespace std;

const double PI = 3.1415927;

int main() {
    int testNum = 0;
    int revolutions;
    double diameter, time, distance, mph;

    while (cin >> diameter >> revolutions >> time, revolutions) {
        distance = PI * diameter * revolutions / (12 * 5280);
        mph = (distance  * 3600) / time;
        printf("Trip #%d: %.2f %.2f\n", ++testNum, distance, mph);
    }

    return 0;
}

