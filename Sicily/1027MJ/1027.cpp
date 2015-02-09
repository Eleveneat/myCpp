/*
*    Filename: 1027.cpp
*    Description: NULL
*    Last modified: 2015-02-09 13:45
*
*    Created by Eleven on 2015-02-09
*    Email: eleveneat@gmail.com
*    Copyright (C) 2015 Eleven. All rights reserved.
*/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct user{
    string mainID, maJia;
};

bool cmp(user& u1, user& u2) {
    return u1.mainID < u2.mainID;
}

int main() {
    int testNum, userNum = 0;
    string id[25], ip[25];
    user allUser[15];
    while (cin >> testNum && testNum) {
        userNum = 0;
        for (int i = 0; i < testNum; i++)
            cin >> id[i] >> ip[i];
        for (int i = 0; i < testNum - 1; i++) {
            for (int j = i + 1; j < testNum; j++) {
                if (ip[j] == ip[i]) {
                    allUser[userNum].mainID = id[i];
                    allUser[userNum].maJia = id[j];
                    userNum++;
                    break;
                }
            }
        }
        sort(allUser, allUser + userNum, cmp);
        for (int i = 0; i < userNum; i++)
            cout << allUser[i].maJia << " is the MaJia of " << allUser[i].mainID << endl;
        cout << endl;
    }
    return 0;
}

