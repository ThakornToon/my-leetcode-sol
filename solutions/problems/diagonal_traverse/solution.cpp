class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> result;
        int row = 0, col = 0;
        int direction = 1; // 1 for upward, -1 for downward
        
        for (int i = 0; i < m * n; i++) {
            result.push_back(mat[row][col]);
            
            if (direction == 1) { // Moving upward
                if (col == n - 1) {
                    row++;
                    direction = -1;
                } else if (row == 0) {
                    col++;
                    direction = -1;
                } else {
                    row--;
                    col++;
                }
            } else { // Moving downward
                if (row == m - 1) {
                    col++;
                    direction = 1;
                } else if (col == 0) {
                    row++;
                    direction = 1;
                } else {
                    row++;
                    col--;
                }
            }
        }
        
        return result;   
    }
};