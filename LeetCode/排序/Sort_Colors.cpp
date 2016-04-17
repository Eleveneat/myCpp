class Solution {
public:
    void sortColors(vector<int>& nums) {
        const int LEN = nums.size();
        int start = 0;
        int end = LEN - 1;
        for (int i = 0; i < end + 1; i++) {
            if (nums[i] == 0) {
                swap(nums[i], nums[start]);
                start++;
            } else if (nums[i] == 2) {
                swap(nums[i], nums[end]);
                end--; i--;
            }
        }
    }
};
