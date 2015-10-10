/*
*    Filename: 1176.cpp
*    Description: NULL
*    Last modified: 2015-09-28 20:40
*
*    Created by Eleveneat on 2015-09-28
*    Email: eleveneat@gmail.com
*    Copyright (C) 2015 Eleveneat. All rights reserved.
*/

#include <iostream>
#include <list>

using namespace std;

int main() {
    int aPoint, bPoint, cardNum, gameNum, cardPoint, diffPoint;
    list<int> card;

    gameNum = 0;

    while (cin >> cardNum, cardNum) {
        aPoint =  bPoint = 0;
        gameNum++;

        for (int i = 0; i < cardNum; i++) {
            cin >> cardPoint;
            card.push_back(cardPoint);
        }

        while (!card.empty()) {
            if (card.front() >= card.back()) {
                aPoint += card.front();
                card.pop_front();
            } else {
                aPoint += card.back();
                card.pop_back();
            }

            if (card.front() >= card.back()) {
                bPoint += card.front();
                card.pop_front();
            } else {
                bPoint += card.back();
                card.pop_back();
            }
        }

        diffPoint = aPoint > bPoint ? (aPoint - bPoint) : (bPoint - aPoint);

        cout << "In game " << gameNum << ", the greedy strategy might lose by as many as ";
        cout << diffPoint <<  " points." << endl;
    }

    return 0;
}

