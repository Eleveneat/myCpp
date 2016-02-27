class Solution {
public:
    bool isValid(string s) {
        string left = "([{";
        string right = ")]}";
        stack<char> stk;
        
        for (auto c : s) {
            if (left.find(c) != string::npos) {
                stk.push(c);
            } else {
                if (stk.empty() || stk.top() != left[right.find(c)])
                    return false;
                else
                    stk.pop();
            }
        }
        return stk.empty();
    }
};

class Solution {
public:
    int longestValidParentheses(string s) {
        int result = 0, last = -1, depth = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                depth++;
            } else {
                depth--;
                if (depth < 0) {
                    last = i;
                    depth = 0;
                } else if (depth == 0) {
                    result = max(result, i - last);
                }
            }
        }
        last = s.size(); depth = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == ')') {
                depth++;
            } else {
                depth--;
                if (depth < 0) {
                    last = i;
                    depth = 0;
                } else if (depth == 0) {
                    result = max(result, last - i);
                }
            }
        }
        return result;
    }
};
