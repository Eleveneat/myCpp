class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        nums.erase(remove(nums.begin(), nums.end(), val), nums.end());
        return nums.size();
    }
};

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int index = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[index++] = nums[i];
            }
        }
        
        int popNum = nums.size() - index + 1;
        while (popNum--) nums.pop_back();
        return index;
    }
};
