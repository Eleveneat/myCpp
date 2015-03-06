#1800. Sequence

##Constraints

Time Limit: 1 secs, Memory Limit: 32 MB

##Description

Given a sequence S of n numbers and two length bounds L and U.

Your task is to write a program to find a segment S[i], S[i+1], …, S[j] with minimum sum over all segments of S with length at least L and at most U.
##Input

The input consists of multiple datasets. The end of the input is indicated by a line containing a zero.

The format of each dataset is as follows.

n

L U

S1 S2 … Sn

Here, all data items are integers. n is the length of the sequence (N≤32767). L and U are two length bounds where L≤U. S1, S2, …, Sn are the sequence of n numbers.
##Output

For each dataset, output the minimum sum of segment, in a separate line.
##Sample Input

9

2 8

-3 2 -2 5 -4 1 -2 3 1

0
##Sample Output

-5
##Hint

the segment is -4 1 -2.