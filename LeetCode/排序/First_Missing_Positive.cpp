class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        bucket_sort(nums);
        
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] != (i + 1))
                return i + 1;
        return nums.size() + 1;
    }
private:
    static void bucket_sort(vector<int> &A) {
        const int LEN = A.size();
        for (int i = 0; i < LEN; i++) {
            while (A[i] != i + 1) {
                if (A[i] <= 0 || A[i] > LEN || A[i] == A[A[i] - 1])
                    break;
                swap(A[i], A[A[i] - 1]);
            }
        }
    }
};
