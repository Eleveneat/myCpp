/*
*    Filename: 1063.cpp
*    Description: NULL
*    Last modified: 2015-10-17 13:52
*
*    Created by Eleveneat on 2015-10-17
*    Email: eleveneat@gmail.com
*    Copyright (C) 2015 Eleveneat. All rights reserved.
*/

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>

using namespace std;

struct employee {
    int id;
    int salary;
    int height;
    int bossId;
    int subNum;
};

vector<employee> allEmp;

bool cmp(const employee& a, const employee& b) {
    return a.salary < b.salary;
}

int main() {
    int testNum, empNum, queNum;
    int idPos[1000000];
    cin >> testNum;
    while (testNum--) {
        allEmp.clear();
        // memset(idPos, 0, 1000000 * sizeof(int));
        scanf("%d %d", &empNum, &queNum);
        for (int i = 0; i < empNum; i++) {
            int id, salary, height;
            scanf("%d %d %d", &id, &salary, &height);
            employee oneEmp = {id, salary, height, 0, 0};
            allEmp.push_back(oneEmp);
        }
        sort(allEmp.begin(), allEmp.end(), cmp);
        for (int i = 0; i < allEmp.size(); i++) {
            int id = allEmp[i].id;
            idPos[id] = i;
            for (int j = i + 1; j < allEmp.size(); j++) {
                if (allEmp[j].height >= allEmp[i].height) {
                    allEmp[i].bossId = allEmp[j].id;
                    allEmp[j].subNum += allEmp[i].subNum + 1;
                    break;
                }
            }
        }
        for (int i = 0; i < queNum; i++) {
            int id;
            cin >> id;
            employee e = allEmp[idPos[id]];
            printf("%d %d\n", e.bossId, e.subNum);
        }
    }
    return 0;
}                                 
