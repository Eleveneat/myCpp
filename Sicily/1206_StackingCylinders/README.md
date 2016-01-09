#1206. Stacking Cylinders

##Constraints

Time Limit: 1 secs, Memory Limit: 32 MB

##Description

Problem Cylinders (e.g. oil drums) (of radius 1 foot) are stacked in a rectangular bin. Each cylinder on an upper row rests on two cylinders in the row below. The cylinders in the bottom row rest on the floor and do not roll from their original positions. Each row has one less cylinder than the row below.

This problem is to write a program to compute the location of the center of the top cylinder from the centers of the cylinders on the bottom row. Computations of intermediate values should use double precision.

##Input

The input begins with a line containing the count of problem instances, nProb , as a decimal integer, (1<=nProb<=1000) . This is followed by nProb input lines. An input line consists of the number, n , of cylinders on the bottom row followed by n floating point values giving the x coordinates of the centers of the cylinders (the y coordinates are all 1.0 since the cylinders are resting on the floor (y = 0.0 )). The value of n will be between 1 and 10 (inclusive). The distance between adjacent centers will be at least 2.0 (so the cylinders do not overlap) and at most 3.4 (so cylinders at level k cannot touch cylinders at level k - 2 ).

##Output

The output for each data set is a line containing the problem number (1...nProb) , a colon, a space, the x coordinate of the topmost cylinder to 4 decimal places, a space and the y coordinate of the topmost cylinder to 4 decimal places (both x and y ROUNDED to the nearest digit).

Note: To help you check your work, the x -coordinate of the center of the top cylinder should be the average of the x -coordinates of the leftmost and rightmost bottom cylinders. 
##Sample Input

5   
4 1.0 4.4 7.8 11.2  
1 1.0  
6 1.0 3.0 5.0 7.0 9.0 11.0  
10 1.0 3.0 5.0 7.0 9.0 11.0 13.0 15.0 17.0 20.4  
5 1.0 4.4 7.8 11.2 14.6 
##Sample Output

1: 6.1000 4.1607  
2: 1.0000 1.0000  
3: 6.0000 9.6603  
4: 10.7000 15.9100  
5: 7.8000 5.2143