class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty())
            return true;
        size_t len = s.length();
        bool isPalindrome = true;
        for (int a = 0, b = len - 1; a < len && b >= 0; ++a, --b) {
            while (a < len && !isalnum(s[a]))
                ++a;
            while (b >= 0 && !isalnum(s[b]))
                --b;
            if (a >= len || b < 0)
                break;
            if (tolower(s[a]) != tolower(s[b])) {
                isPalindrome = false;
                break;
            }
        }
        return isPalindrome;
    }
};

class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        auto left = s.begin(), right = prev(s.end());
        while (left < right) {
            if (!::isalnum(*left)) ++left;
            else if (!::isalnum(*right)) --right;
            else if (*left != *right) return false;
            else { left++, right--; }
        }
        return true;
    }
};
