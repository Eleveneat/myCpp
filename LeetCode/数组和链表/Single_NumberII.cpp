class Solution {
public:
    int singleNumber(vector<int>& nums) {
        const int W = sizeof(int) * 8; // 一个整数的bit数，即整数字长
        int count[W];
        fill_n(&count[0], W, 0);
        for(size_t i = 0; i < nums.size(); i++) {
            for (size_t j = 0; j < W; j++) {
                size_t bit = (nums[i] >> j) & 1;
                count[j] = (count[j] + bit) % 3;
            }
        }
        
        int result = 0;
        for (size_t i = 0; i < W; i++) {
            result += (count[i] << i);
        }

        return result;
    }
};

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one = 0, two = 0, three = 0;
        for (auto i : nums) {
            two |= (one & i);
            one ^= i;
            three = ~(one & two);
            one &= three;
            two &= three;
        }
        
        return one;
    }
};
