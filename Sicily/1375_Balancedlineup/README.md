#1375. Balanced lineup

##Constraints

Time Limit: 5 secs, Memory Limit: 32 MB

##Description

Farmer John has decided to take a family portrait of some (maybe
all) of the cows. In order to take the portrait, FJ has arranged
all N (1 <= N <= 50,000) cows in a straight line. Each cow is labeled
with its x coordinate (range: 0..1,000,000,000) on the line as well
as its breed (0 or 1).

Over the years, FJ has done some crazy things, and this activity
is no exception. He will only photograph one group of cows, and
that group must be "balanced". A contiguous group of cows is
"balanced" if it contains the same number of cows from each of the
two breeds.

Determine the widest expanse of cows that might have to fit in one
photograph. The length of a balanced group is the difference in x
values between the left-most and right-most cows in the group.

At least one cow of each breed appears in the input, and no two
cows share the same x coordinate.


##Input

* Line 1: A single integer: N
* Lines 2..N+1: Each line contains two space-separated integers that
        describe a single cow containing respectively: a breed ID and
        an x coordinate

##Output

* Line 1: A single integer specifying the size of the largest
        contiguous balanced group of cows.

##Sample Input

7

0 11

1 10

1 25

1 12

1 4

0 13

1 22
##Sample Output

11
##Hint
可以将类型0改为-1，用一个数组sums记录到每一位的类型数的前缀和。这样如果第i位于后面第j位的和是相等的，就说明第i+1到第j位之间的牛是两种类型相等的。题目可以转化成为在sums数组中找到两个位置i,j满足sums[i]=sums[j]，而且使得第i+1头牛的x坐标和第j头的x坐标差值最大（区域最大）

为了实现时间复杂度O（n），只遍历一次sums数组，并另开一个数组sums_position，记录每一个sum出现的位置。

n头牛的sums取值范围是[-n,n],sums_position数组初始化每一个位置为0，对于sums[i]，如果该位置仍为0，则说明第一次遇到这个值。否则该位置已经存放上一次遇到这个值时遍历到的位置。

                                