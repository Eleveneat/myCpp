//超时
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() <= 1) return s;
        int longestNum = 1;
        int len = s.size();
        string result = "";
        for (int i = 0; i < len - longestNum; i++) {
            for (int j = longestNum; i + j < len; j++) {
                string str = s.substr(i, i + j + 1);
                if (isPalindrome(str)) {
                    longestNum = str.size();
                    result = str;
                }
            }
        }
        return result;
    }
private:
    bool isPalindrome(string s) {
        int len = s.size();
        for (int i = 0; i < len / 2; i++)
            if (s[i] != s[len - 1 - i])
                return false;
        return true;
    }
};

// 动态规划
class Solution {
public:
    string longestPalindrome(string s) {
        const int n = s.size();
        bool f[n][n];
        fill_n(&f[0][0], n * n, false);
        size_t max_len = 1, start = 0;
        
        for (size_t i = 0; i < s.size(); i++) {
            f[i][i] = true;
            for (size_t j = 0; j < i; j++) {
                f[j][i] = (s[j] == s[i] && (i - j < 2 || f[j + 1][i - 1]));
                if (f[j][i] && max_len < (i - j + 1)) {
                    max_len = i - j + 1;
                    start = j;
                }
            }
        }
        return s.substr(start, max_len);
    }
};

//超时
class Solution {
public:
    string preProcess(const string& s) {
        int n = s.length();
        if (n == 0) return "^$";
        string ret = "^";
        for (int i = 0; i < n; i++) ret += "#" + s.substr(i, 1);
        ret += "#$";
        return ret;
    }
    string longestPalindrome(string s) {
        string T = preProcess(s);
        const int n = T.length();
        int P[n];
        int C = 0, R = 0;
        
        for (int i = 1; i < n - 1; i++) {
            int i_mirror = 2 * C - i;
            
            P[i] = (R > i) ? min(R - i, P[i_mirror]) : 0;
            
            while (T[i + 1 + P[i]] == T[i - 1 - P[i]])
                P[i]++;
            
            if (i + P[i] > R) {
                C = i;
                R = i + P[i];
            }
        }
        
        int max_len = 0;
        int center_index = 0;
        for (int i = 1; i < n - 1; i++) {
            if (P[i] > max_len) {
                max_len = P[i];
                center_index = i;
            }
        }
        
        return s.substr((center_index - 1 - max_len) / 2, max_len);
    }
};
