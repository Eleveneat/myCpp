// 超时咯
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty())
            return false;
        const size_t m = matrix.size();
        const size_t n = matrix.front().size();
        
        int first = 0;
        int last = m * n;
        
        while (first < last) {
            int mid = first = (last - first) / 2;
            int value = matrix[mid / n][mid % n];
            
            if (value == target)
                return true;
            else if (value < target)
                first = mid + 1;
            else
                last = mid;
        }
        return false;
    }
};

// 右上角大法
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) return false;
        const size_t m = matrix.size();
        const size_t n = matrix.front().size();
        
        for (int mm = 0, nn = n - 1; mm < m && nn >= 0;) {
            if (matrix[mm][nn] > target) {
                nn--;
            } else if (matrix[mm][nn] < target) {
                mm++;
            } else {
                return true;
            }
        }
        return false;
    }
};
