class Solution {
public:
    int myAtoi(string str) {
        if (str.empty())
            return 0;
        int pos = 0;
        int len = str.length();
        for (; pos < len && isspace(str[pos]); pos++);
        bool isPositive;
        if (pos < len && (str[pos] == '-' || str[pos] == '+')) {
            isPositive = str[pos] == '-' ? false : true;
            ++pos;
        }
        if (pos < len && !isdigit(str[pos]))
            return 0;
        long long result = 0;
        for (; pos < len && isdigit(str[pos]); pos++) {
            int digit = str[pos] - '0';
            result = result * 10 + digit;
            if (result > INT_MAX) {
                return isPositive ? INT_MAX : INT_MIN;
            }
        }
        return isPositive ? result : -result;
    }
};

class Solution {
public:
    int myAtoi(string str) {
        if (str.empty())
            return 0;
        int pos = 0;
        int len = str.length();
        for (; pos < len && isspace(str[pos]); pos++);
        bool isPositive = true;
        if (pos < len && (str[pos] == '-' || str[pos] == '+')) {
            isPositive = str[pos] == '-' ? false : true;
            ++pos;
        }
        int result = 0;
        for (; pos < len && isdigit(str[pos]); pos++) {
            int digit = str[pos] - '0';
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > INT_MAX % 10))
                return isPositive ? INT_MAX : INT_MIN;
            result = result * 10 + digit;
        }
        return isPositive ? result : -result;
    }
};
