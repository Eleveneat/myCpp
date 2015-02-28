#1813. M进制数问题

##Constraints

Time Limit: 1 secs, Memory Limit: 32 MB

##Description

试用 C++的类来表示一般进制数。

给定 2 个n位m进制整数A和B，计算m进制数整数P = A / B (向下取整)与 Q = A % B的值。

##Input

输入包含多个测试点。第一行为一个整数T，表示测试点数。

对于每个测试点第 1 行是进制 m 。第 2 行和第 3 行分别给出 m 进制整数 A 和 B。

所有 m 进制数的10进制表示均不超出int范围。

 

##Output

对于每个测试点，第一行输出 m 进制数整数 P = A / B 的值，第二行输出 Q = A % B 的值。

##Sample Input

1

16

29FA5

7
##Sample Output

5FF3

0