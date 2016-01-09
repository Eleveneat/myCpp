#1034. Forest

##Constraints

Time Limit: 1 secs, Memory Limit: 32 MB

##Description

In the field of computer science, forest is important and deeply researched , it is a model for many data structures . Now it’s your job here to calculate the depth and width of given forests.

Precisely, a forest here is a directed graph with neither loop nor two edges pointing to the same node. Nodes with no edge pointing to are roots, we define that roots are at level 0 . If there’s an edge points from node A to node B , then node B is called a child of node A , and we define that B is at level (k+1) if and only if A is at level k .
     
We define the depth of a forest is the maximum level number of all the nodes , the width of a forest is the maximum number of nodes at the same level.
##Input

There’re several test cases. For each case, in the first line there are two integer numbers n and m (1≤n≤100, 0≤m≤100, m≤n*n) indicating the number of nodes and edges respectively , then m lines followed , for each line of these m lines there are two integer numbers a and b (1≤a,b≤n)indicating there’s an edge pointing from a to b. Nodes are represented by numbers between 1 and n .n=0 indicates end of input.

##Output

For each case output one line of answer , if it’s not a forest , i.e. there’s at least one loop or two edges pointing to the same node, output “INVALID”(without quotation mark), otherwise output the depth and width of the forest, separated by a white space.
##Sample Input

1 0  
1 1  
1 1  
3 1  
1 3  
2 2  
1 2  
2 1  
0 88

##Sample Output

0 1  
INVALID  
1 2  
INVALID

##Problem Source

ZSUACM Team Member