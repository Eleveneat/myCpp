class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.size() < 3) return result;
        sort(nums.begin(), nums.end());
        const int target = 0;
        
        auto i = nums.begin();
        for(; i < nums.end() - 2; i++) {
            if (i > nums.begin() && *(i) == *(i - 1)) continue;
            auto j = i + 1;
            auto k = nums.end() - 1;
            
            while (j < k) {
                if (*i + *j + *k < target) {
                    j++;
                    while (*j == *(j - 1) && j < k) j++;
                } else if (*i + *j + *k > target) {
                    k--;
                    while (*k == *(k + 1) && j < k) k--;
                } else {
                    result.push_back({*i, *j, *k});
                    j++;
                    k--;
                    while (*j == *(j - 1) && *k == *(k + 1) && j < k) ++j;
                }
            }
        }
        
        return result;
    }
};
