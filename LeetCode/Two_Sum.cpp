class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        
        unordered_map<int, int> map;
        for (int i = 1; i <= nums.size(); i++)
            map[nums[i-1]] = i;
        
        for (int i = 1; i <= nums.size(); i++) {
            int a = nums[i-1];
            int b = target - a;

            if (map.find(b) != map.end() && map[b] > i) {
                int aIndex = i, bIndex = map[b];
                result.push_back(min(aIndex, bIndex));
                result.push_back(max(aIndex, bIndex));
                break;
            }
        }
        
        return result;
    }
};
