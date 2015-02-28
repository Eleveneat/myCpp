/*
*    Filename: 1036.cpp
*    Description: NULL
*    Last modified: 2015-02-27 13:43
*
*    Created by Eleven on 2015-02-27
*    Email: eleveneat@gmail.com
*    Copyright (C) 2015 Eleven. All rights reserved.
*/
#include <iostream>
#include <string>
#include <memory.h>

using namespace std;

int main() {
    string key, ciphertext;
    char a[110][110];
    int num, tmp;
    while (cin >> key && "THEEND" != key) {
        tmp = 0;
        memset(a, '\0', 110*110*sizeof(char));
        cin >> ciphertext;
        num = ciphertext.size() / key.size();
        for (int i = 0; i < 26; i++) {
            for (int n = 0; n < key.size(); n++) {
                if (key[n] == 'A' + i) {
                    for (int index = 0; index < num; index++)
                        a[index][n] = ciphertext[tmp++];
                }
            }
        }
        for (int i = 0; i < num; i++)
            cout << a[i];
        cout << endl;
    }
    return 0;
}

