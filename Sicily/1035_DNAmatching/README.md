#1035. DNA matching

##Constraints

Time Limit: 1 secs, Memory Limit: 32 MB

##Description

DNA (Deoxyribonucleic acid) is founded in every living creature as the storage medium for genetic information. It is comprised of subunits called nucleotides that are strung together into polymer chains. DNA polymer chains are more commonly called DNA strands.  
    There are four kinds of nucleotides in DNA, distinguished by the chemical group, or base attached to it. The four bases are adenine, guanine, cytosine and thymine, abbreviated as A, G, C and T(these letters will be used to refer to nucleotides containing these bases). Single nucleotides are linked together end-to-end to form DNA single strands via chemical reactions. For simplicity, we can use a string composed of letters A, T, C and G to denote a single strand, such as ATTCGAC, but we must also note that the sequence of nucleotides in any strand has a natural orientation, so ATTCGAC and CAGCTTA can not be viewed as identical strands.  
    DNA does not usually exist in nature as free single strands, though. Under appropriate conditions single strands will pair up and twist around each other, forming the famous double helix structure. This pairing occurs because of a mutual attraction, call hydrogen bonding, that exists between As and Ts, and between Gs and Cs. Hence A/T and G/C are called complementary base pairs.  
In the Molecular Biology experiments dealing with DNA, one important process is to match two complementary single strands, and make a DNA double strand. Here we give the constraint that two complementary single strands must have equal length, and the nucleotides in the same position of the two single strands should be complementary pairs. For example, ATTCGAC and TAAGCTG are complementary, but CAGCTTA and TAAGCTG are not,  neither are ATTCGAC and GTAAGCT.  
As a biology research assistant, your boss has assigned you a job: given n single strands, find out the maximum number of double strands that could be made (of course each strand can be used at most once). If n is small, of course you can find the answer with the help of pen and paper, however, sometimes n could be quite large… Fortunately you are good at programming and there is a computer in front of you, so you can write a program to help yourself. But you must know that you have many other assignments to finish, and you should not waste too much time here, so, hurry up please!  
##Input

Input may contain multiple test cases. The first line is a positive integer T(T<=20), indicating the number of test cases followed. In each test case, the first line is a positive integer n(n<=100), denoting the number of single strands below. And n lines follow, each line is a string comprised of four kinds of capital letters, A, T, C and G. The length of each string is no more than 100.

##Output

For each test case, the output is one line containing a single integer, the maximum number of double strands that can be formed using those given single strands.

##Sample Input

2  
3  
ATCG  
TAGC  
TAGG  
2  
AATT  
ATTA  
##Sample Output

1  
0  
##Problem Source

ZSUACM Team Member