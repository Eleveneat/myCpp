/*
*    Filename: 1147.cpp
*    Description: NULL
*    Last modified: 2015-02-27 20:50
*
*    Created by Eleven on 2015-02-27
*    Email: eleveneat@gmail.com
*    Copyright (C) 2015 Eleven. All rights reserved.
*/
#include <iostream>
#include <string>

using namespace std;

struct student {
    string name;
    int average, classMark, paper;
    char isLeader, isWest;
    int scholarship;
};

void matchYuanShi(student& x) {
    if (x.average > 80 && x.paper)
        x.scholarship += 8000;
}

void matchWuSi(student& x) {
    if (x.average > 85 && x.classMark > 80)
        x.scholarship += 4000;
}

void matchYouXiu(student& x) {
    if (x.average > 90)
        x.scholarship += 2000;
}

void matchWest(student& x) {
    if (x.average > 85 && 'Y' == x.isWest)
        x.scholarship += 1000;
}

void matchClass(student& x) {
    if (x.classMark > 80 && 'Y' == x.isLeader)
        x.scholarship += 850;
}

void matchAllScholarship(student& x) {
    matchYuanShi(x);
    matchWuSi(x);
    matchYouXiu(x);
    matchWest(x);
    matchClass(x);
}
int main() {
    int n, total = 0, max = -1;
    string name;
    student a[110];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].name >> a[i].average >> a[i].classMark
            >> a[i].isLeader >> a[i].isWest >> a[i].paper;
        a[i].scholarship = 0;
        matchAllScholarship(a[i]);
        if (a[i].scholarship > max) {
            max = a[i].scholarship;
            name = a[i].name;
        }
        total += a[i].scholarship;
    }
    cout << name << endl << max << endl << total << endl;
    return 0;
}

