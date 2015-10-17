#1156. Binary tree

##Constraints

Time Limit: 1 secs, Memory Limit: 32 MB

##Description

Your task is very simple: Given a binary tree, every node of which contains one upper case character (‘A’ to ‘Z’); you just need to print all characters of this tree in pre-order.

##Input

Input may contain several test data sets.  
      For each test data set, first comes one integer n (1 <= n <= 1000) in one line representing the number of nodes in the tree. Then n lines follow, each of them contains information of one tree node. One line consist of four members in order: i (integer, represents the identifier of this node, 1 <= i <= 1000, unique in this test data set), c (char, represents the content of this node described as above, ‘A’ <= c <= ‘Z’), l (integer, represents the identifier of the left child of this node, 0 <=  l <= 1000, note that when l is 0 it means that there is no left child of this node), r (integer, represents the identifier of the right child of this node, 0 <=  r <= 1000, note that when r is 0 it means that there is no right child of this node). These four members are separated by one space.  
      Input is ended by EOF.  
      You can assume that all inputs are valid. All nodes can form only one valid binary tree in every test data set.  
##Output

For every test data set, please traverse the given tree and print the content of each node in pre-order. Characters should be printed in one line without any separating space.

##Sample Input

3  
4 C 1 3  
1 A 0 0  
3 B 0 0  
1  
1000 Z 0 0  
3  
1 Q 0 2  
2 W 3 0  
3 Q 0 0  
##Sample Output

CAB  
Z  
QWQ
##Problem Source

ZSUACM Team Member