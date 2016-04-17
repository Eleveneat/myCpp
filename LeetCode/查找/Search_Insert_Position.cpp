class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        auto first = nums.begin();
        auto last = nums.end();
        while (first != last) {
            auto mid = next(first, distance(first, last) / 2);
            
            if (target > *mid)
                first = ++mid;
            else
                last = mid;
        }
        
        return distance(nums.begin(), first);
    }
};
