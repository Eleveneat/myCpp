/*
*    Filename: 1003.cpp
*    Description: NULL
*    Last modified: 2015-03-16 20:29
*
*    Created by Eleven on 2015-03-16
*    Email: eleveneat@gmail.com
*    Copyright (C) 2015 Eleven. All rights reserved.
*/
#include <iostream>
#include <queue>

using namespace std;

struct player {
    queue<int> q;
    int count;
};

int main() {
    int testNum, n, loop, card;
    bool isWin;
    cin >> testNum;
    for (int num = 1; num <= testNum; num++) {
        cout << "Case " << num << ":";
        cin >> n;
        player players[15];
        int lastCard[15];
        for (int i = 0; i < 52; i++) {
            cin >> card;
            players[0].q.push(card);
        }
        for (int i = 0; i < n; i++) {
            players[i].count = 1;
        }
        loop = 1100;
        while (loop--) {
            for (int i = 0; i < n; i++) {
                if (players[i].q.empty())
                    continue;
                if (players[i].q.front() == players[i].count) {
                    card = players[i].q.front();
                    players[i].q.pop();
                    players[i+1].q.push(card);
                    if (players[i].q.empty())
                        lastCard[i] = card;
                    loop = 1100;
                } else {
                    card = players[i].q.front();
                    players[i].q.pop();
                    players[i].q.push(card);
                }
                players[i].count++;
                if (14 == players[i].count)
                    players[i].count = 1;
            }
        }
        isWin = true;
        for (int i = 0; i < n; i++)
            if (!players[i].q.empty())
                isWin = false;
        if (isWin) {
            for (int i = 0; i < n; i++)
                cout << " " << lastCard[i];
        } else {
            cout << " unwinnable";
        }
        cout << endl;
    }
    return 0;
}

