class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.size() < 3) return -1;
        sort(nums.begin(), nums.end());

        auto i = nums.begin();
        int closestTarget = *i + *(i + 1) + *(i + 2);
        for(; i < nums.end() - 2; i++) {
            if (i > nums.begin() && *(i) == *(i - 1)) continue;
            auto j = i + 1;
            auto k = nums.end() - 1;
            
            while (j < k) {
                if (abs(target - closestTarget) > abs(target - (*i + *j + *k) ) )
                    closestTarget = *i + *j + *k;

                if (*i + *j + *k < target) {
                    j++;
                    while (*j == *(j - 1) && j < k) j++;
                } else if (*i + *j + *k > target) {
                    k--;
                    while (*k == *(k + 1) && j < k) k--;
                } else {
                    return closestTarget;
                }
            }
        }
        
        return closestTarget;
    }
};
