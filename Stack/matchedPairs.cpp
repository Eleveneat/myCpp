/*
*    Filename: matchedPairs.cpp
*    Description: Match simple pair expression, like (a*(b+c)+d).
*    Last modified: 2014-10-12 18:32
*
*    Created by Eleven on 2014-10-12
*    Email: eleveneat@gmail.com
*    Copyright (C) 2014 Eleven. All rights reserved.
*/

#include <iostream>
#include <string>
#include <stack>

void printMatchedPairs(std::string str) {
	std::stack<int> sta;
	int len = str.length();
	for (int i = 0; i < len; ++i) {
		if ('(' == str[i]) sta.push(i);
		else if (')' == str[i]) {
			if (sta.empty()) {
				std::cout << "No match for right parenthesis at " << i + 1 << std::endl;
			} else {
				std::cout << sta.top() + 1 << " " << i + 1 << std::endl;
				sta.pop();
			}
		}
	}
}

int main() {
	std::string str;
	std::cout << "Type an expression:" << std::endl;
	std::cin >> str;
	std::cout << "The pairs of matching parentheses in the expression\n"
		<< str << std::endl
		<< "are" << std::endl;
	printMatchedPairs(str);
	return 0;
}
