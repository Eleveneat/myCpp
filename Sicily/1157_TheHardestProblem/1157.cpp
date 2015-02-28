/*
*    Filename: 1157.cpp
*    Description: NULL
*    Last modified: 2015-02-27 21:26
*
*    Created by Eleven on 2015-02-27
*    Email: eleveneat@gmail.com
*    Copyright (C) 2015 Eleven. All rights reserved.
*/
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int num;
    while(cin >> num && num){
        int a[4];
        for(int i = 0; i < num; i++){
            cin >> a[i];
        }
        sort(a, a + num);
        cout << a[num - 1] << endl;
    }
    return 0;
}                                 
