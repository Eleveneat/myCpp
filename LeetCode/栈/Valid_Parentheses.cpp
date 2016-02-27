class Solution {
public:
    bool isValid(string s) {
        stack<char> sta;
        for (auto c : s) {
            if (c == '(' || c == '{' || c == '[') {
                sta.push(c);
            } else if (sta.empty()) {
                return false;
            } else if (c == ')') {
                if (sta.top() != '(')
                    return false;
                sta.pop();
            } else if (c == '}') {
                if (sta.top() != '{')
                    return false;
                sta.pop();
            } else { // c == ']'
                if (sta.top() != '[')
                    return false;
                sta.pop();
            }
        }
        return sta.empty();
    }
};

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
