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

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        add(digits, 1);
        return digits;
    }
private:
     void add(vector<int>& digits, int digit) {
         int c = digit; // carry
         
         for (auto it = digits.rbegin(); it != digits.rend(); it++) {
             *it += c;
             c = *it / 10;
             *it %= 10;
         }
         
         if (c > 0) digits.insert(digits.begin(), 1);
     }
};

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        add(digits, 1);
        return digits;
    }
private:
     void add(vector<int>& digits, int digit) {
         int c = digit; // carry
         
         for_each(digits.rbegin(), digits.rend(), [&c](int& d) {
             d += c;
             c = d / 10;
             d %= 10;
         });
         
         if (c > 0) digits.insert(digits.begin(), 1);
     }
};
