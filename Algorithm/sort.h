/*
*    Filename: sort.h
*    Description: 
*    Last modified: 2015-01-11 20:48
*
*    Created by Eleven on 2015-01-11
*    Email: eleveneat@gmail.com
*    Copyright (C) 2015 Eleven. All rights reserved.
*/
#ifndef _SORT_H
#define _SORT_H

#include <iostream>
#include <stack>

// 插入排序
// 最差时间复杂度：O(n^2)
// 最优时间复杂度：O(n)
// 平均时间复杂度：O(n^2)
// 最差空间复杂度：O(n)
// 辅助空间：      O(1)
// 稳定性：        稳定
template<typename T>
void insertion_sort_1(T arr[], int len) { // 整数或浮点数皆可使用，若要使用class时必须设定大于>的运算子功能
	int i, j;
	T tmp;
	for (i = 1; i < len; i++) {
		tmp = arr[i];
		for (j = i - 1; j >= 0 && arr[j] > tmp; j--) {
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = tmp;
	}
}

template<typename T>
void insertion_sort_2(T* first, T *last) {
	T *i, *j, tmp;
	for (i = first + 1; i <= last; i++) {
		tmp = *i;
		for (j = i - 1; j >= first && *j > tmp; j--) {
			*(j + 1) = *j;
		}
		*(j + 1) = tmp;
	}
}

// 希尔排序
// 最差时间复杂度：O(n^1.25) 不太确定....
// 最优时间复杂度：O(n)
// 平均时间复杂度：O(n^1.25) 不太确定....
// 最差空间复杂度：
// 辅助空间：      O(1)
// 稳定性：        不稳定

template<typename T>
void shell_sort(T arr[], int len) {
	int gap, i, j;
	T tmp;
	for (gap = len >> 1; gap > 0; gap >>= 1) {
		for (i = gap; i < len; i++) { 
			tmp = arr[i];
			for (j = i - gap; j >= 0 && arr[j] > tmp; j -= gap) {
				arr[j + gap] = arr[j];
			}
			arr[j + gap] = tmp;
		}
	}
}

// 选择排序
// 最差时间复杂度：O(n^2)
// 最优时间复杂度：O(n^2)
// 平均时间复杂度：O(n^2)
// 最差空间复杂度：O(n)
// 辅助空间：      O(1)
// 稳定性：        不稳定

template<typename T>
void selection_sort(T arr[], int len) {
	int i, j, min;
	T tmp;
	for (i = 0; i < len - 1; i++) {
		min = i;
		for (j = i + 1; j < len; j++)
			if (arr[min] > arr[j])
				min = j;
		if (min != i) { 
			tmp = arr[min];
			arr[min] = arr[i];
			arr[i] = tmp;
		}
	}
}

// 快速排序
// 最差时间复杂度：O(n^2)
// 最优时间复杂度：O(nlogn)
// 平均时间复杂度：O(nlogn)
// 最差空间复杂度：
// 辅助空间：      
// 稳定性：        不稳定


struct Range {
	explicit Range(int s = 0, int e = 0) : start(s), end(e) {}
	int start, end;
};
void quick_sort(int n, int arr[]) {
	if (n <= 0) return;
	std::stack<Range> st;
	st.push(Range(0, n - 1));
	while(!st.empty()) {
		Range range = st.top();
		st.pop();
		int pivot = arr[range.end];
		int pos = range.start - 1;
		for (int i = range.start; i < range.end; ++i) {
			if (arr[i] < pivot) {
				std::swap(arr[i], arr[++pos]);
			}
		}
		std::swap(arr[++pos], arr[range.end]);
		if (pos - 1 > range.start) {
			st.push(Range(range.start, pos - 1));
		}
		if (pos + 1 < range.end) {
			st.push(Range(pos + 1, range.end));
		}
	}
}

//#只完成兩段之間歸併的功能#%
void Merge(int a[], int b[], int low, int mid, int high)
{
    int k = low;
    int begin1 = low;
    int end1 = mid;
    int begin2 = mid + 1;
    int end2 = high;
    while(k <= high )
    {
        if(begin1 > end1)
            b[k++] = a[begin2++];
        else if(begin2 > end2)
            b[k++] = a[begin1++];
        else
	{
	    if(a[begin1] <= a[begin2])
		b[k++] = a[begin1++];
	    else
		b[k++] = a[begin2++];
	}
    }
 
}
 
// 归并排序 [并未完全理解代码]
// 最差时间复杂度：O(nlogn)
// 最优时间复杂度：O(n)
// 平均时间复杂度：O(nlogn)
// 最差空间复杂度：O(n)
// 辅助空间：     O(logn)
// 稳定性：       稳定

void MergePass(int a[], int b[], int seg, int size)
{
    int seg_start_ind = 0;
    while(seg_start_ind <= size - 2 * seg) //#size - 2 * seg的意思是滿足可兩兩歸併的最低臨界值
    {
	Merge(a, b, seg_start_ind, seg_start_ind + seg - 1, seg_start_ind + seg * 2 - 1);
	seg_start_ind += 2 * seg;
    }
    //#如果一段是正好可歸併的數量而另一段則少於正好可歸併的數量
    if(seg_start_ind + seg < size)
	Merge(a, b, seg_start_ind, seg_start_ind + seg - 1, size - 1);
    else
	for(int j = seg_start_ind; j < size; j++) //#如果只剩下一段或者更少的數量
	    b[j] = a[j];
}
 
void MergeSort(int a[], int size)
{
    int* temp = new int[size];
    int seg = 1;
    while(seg < size)
    {
	MergePass(a, temp, seg, size);
	seg += seg;
	MergePass(temp, a, seg, size);
	seg += seg;
    }
    delete [] temp;
}
 
// 堆排序 [并未完全理解代码]
// 最差时间复杂度：O(nlogn)
// 最优时间复杂度：O(nlogn)
// 平均时间复杂度：O(nlogn)
// 最差空间复杂度：O(n)
// 辅助空间：     O(1)
// 稳定性：       不稳定

/*
	#堆排序#%
          #数组实现#%
*/
//#筛选算法#%
void sift(int d[], int ind, int len)
{
	//#置i为要筛选的节点#%
	int i = ind;
 
	//#c中保存i节点的左孩子#%
	int c = i * 2 + 1; //#+1的目的就是为了解决节点从0开始而他的左孩子一直为0的问题#%
 
	while(c < len)//#未筛选到叶子节点#%
	{
		//#如果要筛选的节点既有左孩子又有右孩子并且左孩子值小于右孩子#%
		//#从二者中选出较大的并记录#%
		if(c + 1 < len && d[c] < d[c + 1])
			c++;
		//#如果要筛选的节点中的值大于左右孩子的较大者则退出#%
		if(d[i] > d[c]) break;
		else
		{
			//#交换#%
			int t = d[c];
			d[c] = d[i];
			d[i] = t;
			//
			//#重置要筛选的节点和要筛选的左孩子#%
			i = c;
			c = 2 * i + 1;
		}
	}
 
	return;
}
 
void heap_sort(int d[], int n)
{
	//#初始化建堆, i从最后一个非叶子节点开始#%
	for(int i = (n - 2) / 2; i >= 0; i--)
		sift(d, i, n);
 
	for(int j = 0; j < n; j++)
	{
                //#交换#%
		int t = d[0];
		d[0] = d[n - j - 1];
		d[n - j - 1] = t;
 
		//#筛选编号为0 #%
		sift(d, 0, n - j - 1);
 
	}
}


#endif //SORT_H

