class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if (digits.empty())
            digits.push_back(0);
        const int n = digits.size();
        
        int tmp = 1;
        for (int i = n - 1; i >= 0; i--) {
            digits[i] += tmp;
            tmp = digits[i] / 10;
            digits[i] %= 10;
        }
        
        if (tmp == 1)
            digits.insert(digits.begin(), 1);
            
        return digits;
    }
};
