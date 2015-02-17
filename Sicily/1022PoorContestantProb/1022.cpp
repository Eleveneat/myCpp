/*
*    Filename: 1022.cpp
*    Description: NULL
*    Last modified: 2015-02-17 14:54
*
*    Created by Eleven on 2015-02-17
*    Email: eleveneat@gmail.com
*    Copyright (C) 2015 Eleven. All rights reserved.
*/
#include <queue>
#include <iostream>
#include <cstdio>
#include <vector>
#include <string.h>

using namespace std;

struct contestant {
    string name;
    int n; // the number of problems solved.
};

struct smallCmp {
    bool operator() (const contestant& x1, const contestant& x2) {
        return x1.n > x2.n;
    }
};

struct bigCmp {
    bool operator() (const contestant& x1, const contestant& x2) {
        return x1.n < x2.n;
    }
};

int main() {
    int testNum, num;
    char command[8], chr[15];
    scanf("%d", &testNum);
    for (int i = 0; i < testNum; i++) {
        priority_queue<contestant, vector<contestant>, smallCmp> small;
        priority_queue<contestant, vector<contestant>, bigCmp> big;
        while (scanf("%s", command)) {
            if (strcmp(command, "Add") == 0) {
                contestant tmp;
                scanf("%s", chr);
                scanf("%d", &num);
                tmp.name = chr;
                tmp.n = num;
                if (small.size() == big.size()) {
                    if (big.empty() || tmp.n < small.top().n) {
                        big.push(tmp);
                    } else { // tmp.n >= small.top().n
                        big.push(small.top());
                        small.pop();
                        small.push(tmp);
                    }
                } else { // small.size < big.size
                    if (tmp.n > big.top().n) {
                        small.push(tmp);
                    } else {
                        small.push(big.top());
                        big.pop();
                        big.push(tmp);
                    }
                }
            } else if (strcmp(command, "Query") == 0) {
                if (big.size() == small.size())
                    printf("No one!\n");
                else
                    printf("%s\n", big.top().name.c_str());
            } else { // "End" == command
                if (big.size() == small.size())
                    printf("Happy BG meeting!!\n");
                else
                    printf("%s is so poor.\n", big.top().name.c_str());
                break;
            }
        }
        if (i != testNum - 1)
            printf("\n");
    }
    return 0;
}
