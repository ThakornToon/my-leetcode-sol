class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int matrixSize = matrix.size();
        int matrixColSize = matrix[0].size();
        int row = 0;
        int col = matrixColSize - 1; // เริ่มจากมุมขวาบน

        while (row < matrixSize && col >= 0) {
            if (matrix[row][col] == target) {
                return true;
            } else if (matrix[row][col] > target) {
                col--; // ไปทางซ้าย (ค่าลดลง)
            } else {
                row++; // ไปทางล่าง (ค่าเพิ่มขึ้น)
            }
        }
        return false;
    }
};