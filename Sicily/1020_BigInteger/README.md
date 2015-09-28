#1020. Big Integer

##Constraints

Time Limit: 1 secs, Memory Limit: 32 MB

##Description

Long long ago, there was a super computer that could deal with VeryLongIntegers(no VeryLongInteger will be negative). Do you know how this computer stores the VeryLongIntegers? This computer has a set of n positive integers: b1,b2,...,bn, which is called a basis for the computer.

The basis satisfies two properties:  
1) 1 < bi <= 1000 (1 <= i <= n),  
2) gcd(bi,bj) = 1 (1 <= i,j <= n, i ≠ j).

Let M = b1*b2*...*bn

Given an integer x, which is nonegative and less than M, the ordered n-tuples (x mod b1, x mod b2, ..., x mod bn), which is called the representation of x, will be put into the computer.

##Input

The input consists of T test cases. The number of test cases (T) is given in the first line of the input.
Each test case contains three lines.  
The first line contains an integer n(<=100).  
The second line contains n integers: b1,b2,...,bn, which is the basis of the computer.  
The third line contains a single VeryLongInteger x.

Each VeryLongInteger will be 400 or fewer characters in length, and will only contain digits (no VeryLongInteger will be negative).

##Output

For each test case, print exactly one line -- the representation of x.  
The output format is:(r1,r2,...,rn)

##Sample Input

2

3  
2 3 5  
10  

4  
2 3 5 7  
13

##Sample Output

(0,1,0)  
(1,1,3,6)  
Problem Source  

ZSUACM Team Member