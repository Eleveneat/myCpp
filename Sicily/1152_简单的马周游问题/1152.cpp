/*
*    Filename: 1152.cpp
*    Description: NULL
*    Last modified: 2015-03-22 21:32
*
*    Created by Eleven on 2015-03-22
*    Email: eleveneat@gmail.com
*    Copyright (C) 2015 Eleven. All rights reserved.
*/
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <vector>

using namespace std;

bool board[10][10]; // 记录棋盘的位置是否访问过
int path[50]; // 记录马的线路
int nextX[] = {2, 2, -2, -2, 1, 1, -1, -1};
int nextY[] = {1, -1, 1, -1, 2, -2, 2, -2};

struct point {
    int x, y; // xy坐标
    int id; // 位置的号码
    int nextNum; // 可达位置的数目
};

bool isMovable(point p) { // 判断该点是否越界或者已经被访问过
    if (p.x < 1 || p.x > 6)
        return false;
    if (p.y < 1 || p.y > 5)
        return false;
    if (board[p.x][p.y])
        return false;
    return true;
}

bool cmp(const point& a, const point& b) {
    return a.nextNum < b.nextNum;
}

bool dfs(point p, int step) {
    if (30 == step) {
        path[step] = p.id;
        return true;
    } else {
        vector<point> v;
        for (int i = 0; i < 8; i++) {
            point next;
            next.x = p.x + nextX[i];
            next.y = p.y + nextY[i];
            next.id = next.x + (next.y-1) * 6;
            next.nextNum = 0;
            if (isMovable(next))
                v.push_back(next);
        }
        for (int i = 0; i < v.size(); i++) {
            for (int j = 0; j < 8; j++) {
                point next;
                next.x = v[i].x + nextX[j];
                next.y = v[i].y + nextY[j];
                if (isMovable(next))
                    v[i].nextNum++;
            }
        }
        sort(v.begin(), v.end(), cmp);
        for (int i = 0; i < v.size(); i++) {
            board[ v[i].x ][ v[i].y ] = true;
            path[step] = p.id;
            if (dfs(v[i], step + 1))
                return true;
            else
                board[ v[i].x ][ v[i].y ] = false;
        }
    }
    return false;
}

int main () {
    int n;
    while (cin >> n && n != -1) {
        memset(board, false, 10*10*sizeof(bool));
        memset(path, 0, 50*sizeof(int));
        point p;
        p.x = n % 6;
        p.y = (n - 1) / 6 + 1;
        p.id = n;
        board[p.x][p.y] = true;
        dfs(p, 1);
        for (int i = 1; i <= 30; i++) {
            if (1 == i)
                cout << path[i];
            else
                cout << " " << path[i];
        }
        cout << endl;
    }
    return 0;
}

