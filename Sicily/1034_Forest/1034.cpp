/*
*    Filename: 1034.cpp
*    Description: NULL
*    Last modified: 2016-01-09 22:14
*
*    Created by Eleven on 2016-01-09
*    Email: eleveneat@gmail.com
*    Copyright (C) 2015 Eleven. All rights reserved.
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>

#define MAX 110

using namespace std;

int nodesNum, edgesNum;
int in[MAX], tree[MAX][MAX], width[MAX];
bool isVisit[MAX];
vector<int> inIs0; // 入度为0的点的集合，即根节点的集合。
bool isValid;
int maxHeight, maxWidth;

void dfs(int node, int height) {
    if (height > maxHeight)
        maxHeight = height;
    for (int i = 1; i <= nodesNum; i++) {
        if (tree[node][i]) {
            if (isVisit[i]) { // 存在环的情况
                isValid = false;
                return;
            } else {
                isVisit[i] = true;
            }
            width[height + 1]++;
            dfs(i, height + 1);
            if (!isValid)
                return;
        }
    }
}

int main() {
    while (scanf("%d%d", &nodesNum, &edgesNum) && nodesNum) {
        inIs0.clear();
        memset(in, 0, MAX * sizeof(int) );
        memset(width, 0, MAX * sizeof(int) );
        memset(isVisit, false, MAX * sizeof(bool) );
        memset(tree, 0, MAX * MAX * sizeof(int) );

        isValid = true;
        for (int i = 0; i < edgesNum; i++) {
            int nodeA, nodeB;
            scanf("%d%d", &nodeA, &nodeB);
            tree[nodeA][nodeB] = 1;
            if (in[nodeB] == 1) // 判断入度是否会超过1
                isValid = false;
            else
                in[nodeB] = 1;
        }

        if (!isValid) { // 存在入度大于1的情况
            printf("INVALID\n");
            continue;
        }

        for (int i = 1; i <= nodesNum; i++)
            if (in[i] == 0)
                inIs0.push_back(i);

        maxHeight = maxWidth = 0;

        for (int i = 0; i < inIs0.size(); i++) {
            int node = inIs0[i];
            isVisit[node] = true;
            width[0]++;
            dfs(node, 0);
            if (!isValid)
                break;
        }

        for (int i = 1; i <= nodesNum; i++) // 除非存在环，不然已遍历所有节点
            if (!isVisit[i])
                isValid = false;

        if (!isValid) {
            printf("INVALID\n");
            continue;
        }

        for (int i = 0; i <= maxHeight; i++) // 找出最大宽度
            if (maxWidth < width[i])
                maxWidth = width[i];

        printf("%d %d\n", maxHeight, maxWidth);
    }
    return 0;
}

