// 超时
class Solution {
public:
    int climbStairs(int n) {
        int count = waysOfStair(n);
        return count;
    }
    
    int waysOfStair(int n) {
        if (n == 0 || n == 1)
            return 1;
        else
            return waysOfStair(n - 1) + waysOfStair(n - 2);
    }
};

class Solution {
public:
    int climbStairs(int n) {
        int f[1000];
        memset(f, 0, sizeof(f));
        f[0] = 1;
        f[1] = 1;
        
        for (int i = 2; i <= n; i++)
            f[i] = f[i - 1] + f[i - 2];
        
        return f[n];
    }
};

// 迭代，时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
    int climbStairs(int n) {
        int prev = 0;
        int cur = 1;
        for (int i = 1; i <= n; i++) {
            int tmp = cur;
            cur += prev;
            prev = tmp;
        }
        
        return cur;
    }
};

class Solution {
public:
    int climbStairs(int n) {
        const double s = sqrt(5);
        return floor((pow((1+s) / 2, n+ 1) + pow((1-s) / 2, n + 1)) / s + 0.5);
    }
};
