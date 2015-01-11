/*
*    Filename: main.cpp
*    Description: 
*    Last modified: 2015-01-11 11:35
*
*    Created by Eleven on 2015-01-11
*    Email: eleveneat@gmail.com
*    Copyright (C) 2015 Eleven. All rights reserved.
*/
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 1000
int father[MAX], son[MAX];
int nodeNum, edgeNum; // 顶点数、边数

typedef struct abc { // 存储边的信息
	int from; // 起点
	int to;   // 终点
	int value; //路径长
}Kruskal;

bool cmp(const Kruskal & a, const Kruskal & b) {
	return a.value < b.value;
}

int unionsearch(int x) { // 查找根节点＋路径压缩
	return x == father[x] ? x : unionsearch(father[x]);
}

bool join(int x, int y) { // 合并
	int root1, root2;
	root1 = unionsearch(x);
	root2 = unionsearch(y);
	if(root1 == root2) // 为环
		return false;
	else if (son[root1] >= son[root2]) {
		father[root2] = root1;
		son[root1] += son[root2];
	} else {
		father[root1] = root2;
		son[root2] += son[root1];
	}
	return true;
}

int main() {
	int nCase;
	cin >> nCase;
	while (nCase--) {
		int edgeTotal = 0, sum = 0, longestRoad = 0; // 已选择的边数、权值之和、已选择边数中的最大权值
		bool flag = false;
		Kruskal edge[MAX];
		cin >> nodeNum;
		edgeNum = nodeNum * (nodeNum - 1) / 2;
		for (int i = 0; i < nodeNum; i++) { // 初始化father和son数组
			father[i] = i;
			son[i] = 1;
		}
		for (int i = 0, length = 0; i < nodeNum; i++) {
			for (int j = 0; j < nodeNum; j++) {
				int distance;
				cin >> distance;
				if (j <= i) continue;
				edge[length].from = i;
				edge[length].to = j;
				edge[length].value = distance;
				length++;
			}
		}
		sort(edge, edge + edgeNum, cmp); // 按权值由小到大排序
		for (int i = 0; i < edgeNum; i++) {
			if (join(edge[i].from, edge[i].to)) {
				edgeTotal++; // 已选择的边数加一
				sum += edge[i].value; // 记录权值之和
				if (longestRoad < edge[i].value) longestRoad = edge[i].value;
			}
			if ( edgeTotal == nodeNum - 1) {
				flag = true;
				break;
			}
		}
		if (flag) cout << longestRoad << endl;
        else cout << "error";
        if (nCase != 0) cout << endl;
	}
	return 0;
}
