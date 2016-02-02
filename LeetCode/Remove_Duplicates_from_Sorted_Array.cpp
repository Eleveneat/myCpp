// Version 1
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int result = 0;
        for (auto x : nums)
            if (!result || nums[result-1] != x)
                nums[result++] = x;
        return result;
    }
};

// Version 2
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        return distance(nums.begin(), unique(nums.begin(), nums.end()));
    }
};

// Version 3
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        return distance(nums.begin(), removeDuplicates(nums.begin(), nums.end(), nums.begin()));
    }
    
    template<typename InIt, typename OutIt>
    OutIt removeDuplicates(InIt first, InIt last, OutIt output) {
        while (first != last) {
            *output++ = *first;
            first = upper_bound(first, last, *first);
        }
        
        return output;
    }
};
