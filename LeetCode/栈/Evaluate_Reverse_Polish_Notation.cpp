class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        string ops = "+-*/";
        for (auto str : tokens) {
            if (ops.find(str) != string::npos) {
                int a, b, result;
                a = stk.top(); stk.pop();
                b = stk.top(); stk.pop();
                switch (str[0]) {
                    case '+':
                        result = a + b;
                        break;
                    case '-':
                        result = b - a;
                        break;
                    case '*':
                        result = a * b;
                        break;
                    case '/':
                        result = b / a;
                        break;
                }
                stk.push(result);
            } else {
                stk.push(stoi(str));
            }
        }
        return stk.top();
    }
};
