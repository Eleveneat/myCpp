#1294. 高级机密

##Constraints

Time Limit: 1 secs, Memory Limit: 32 MB

##Description

在很多情况下，我们需要对信息进行加密。特别是随着Internet的飞速发展，加密技术就显得尤为重要。
很早以前，罗马人为了在战争中传递信息，频繁地使用替换法进行信息加密。然而在计算机技术高速发展的今天，这种替换法显得不堪一击。因此密码研究人员正在试图寻找一种易于编码、但不易于解码的编码规则。
目前比较流行的编码规则称为RSA，是由美国麻省理工学院的三位教授发明的。这种编码规则是基于一种求密取模算法的：对于给出的三个正整数a,b,c，计算a的b次方除以c的余数。
你的任务是编写一个程序，计算(a^b) mod c。
##Input

输入文件只有一行依次为三个正整数a,b,c，三个正整数之间各以一个空格隔开，并且1<=a,b<c<=32,768。

##Output

(a^b) mod c

##Sample Input

2 6 11
##Sample Output

9
##Problem Source

ZSUACM Team Member