class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk;
        int result = 0;
        heights.push_back(0);
        for (int i = 0; i < heights.size(); ) {
            if (stk.empty() || heights[i] > heights[stk.top()]) {
                stk.push(i++);
            } else { // heights[i] <= stk.top()
                int pos = stk.top();
                stk.pop();
                result = max(result, heights[pos] * (stk.empty() ? i : i - stk.top() - 1));
            }
        }
        return result;
    }
};
