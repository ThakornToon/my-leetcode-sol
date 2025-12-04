class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // ขั้นตอน 1: ทำให้บิตแรกเป็น 1
        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 0) {
                for (int j = 0; j < n; j++) {
                    grid[i][j] = 1 - grid[i][j];
                }
            }
        }
        
        // ขั้นตอน 2: ปรับคอลัมน์
        for (int j = 1; j < n; j++) {
            int countOne = 0;
            for (int i = 0; i < m; i++) {
                countOne += grid[i][j];
            }
            
            if (countOne < m - countOne) {
                for (int i = 0; i < m; i++) {
                    grid[i][j] = 1 - grid[i][j];
                }
            }
        }
        
        // ขั้นตอน 3: คำนวณคะแนน
        int score = 0;
        for (int i = 0; i < m; i++) {
            int rowValue = 0;
            for (int j = 0; j < n; j++) {
                rowValue = (rowValue << 1) | grid[i][j];
            }
            score += rowValue;
        }
        
        return score;
    }
};