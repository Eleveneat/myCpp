class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.empty())
            return;
        const size_t rowSize = matrix.size();
        const size_t colSize = matrix[0].size();
        
        bool row[rowSize], col[colSize];
        
        memset(row, false, sizeof(row));
        memset(col, false, sizeof(col));
        
        for (int i = 0; i < rowSize; i++) {
            for (int j = 0; j < colSize; j++) {
                if (matrix[i][j] == 0)
                    row[i] = col[j] = true;
            }
        }
        
        for (int i = 0; i < rowSize; i++) {
            if (row[i])
                fill(matrix[i].begin(), matrix[i].end(), 0);
        }
        
        for (int i = 0; i < colSize; i++) {
            if (col[i]) {
                for (int j = 0; j < rowSize; j++)
                    matrix[j][i] = 0;
            }
        }
    }
};

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.empty())
            return;
        const size_t rowSize = matrix.size();
        const size_t colSize = matrix[0].size();
        
        size_t row_has_zero = false;
        size_t col_has_zero = false;
        
        for (size_t i = 0; i < colSize; i++) {
            if (matrix[0][i] == 0) {
                row_has_zero = true;
                break;
            }
        }
        
        for (size_t i = 0; i < rowSize; i++) {
            if (matrix[i][0] == 0) {
                col_has_zero = true;
                break;
            }
        }
        
        for (size_t i = 1; i < rowSize; i++) {
            for (size_t j = 1; j < colSize; j++) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = matrix[i][0] = 0;
                }
            }
        }
        
        for (size_t i = 1; i < rowSize; i++) {
            for (size_t j = 1; j < colSize; j++) {
                if (matrix[0][j] == 0 || matrix[i][0] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        if (row_has_zero) {
            fill(matrix[0].begin(), matrix[0].end(), 0);
        }
        
        if (col_has_zero) {
            for (int i = 0; i < rowSize; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};
