class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int m = grid.size();
        int n = grid[0].size();
        
        // ตรวจสอบขอบเขต
        if (x < 0 || x + k > m || y < 0 || y + k > n) {
            return grid;
        }
        
        // สร้างผลลัพธ์โดย copy จาก grid
        vector<vector<int>> result = grid;
        
        // Flip submatrix แนวตั้ง
        for (int row = 0; row < k / 2; row++) {
            int topRow = x + row;
            int bottomRow = x + k - 1 - row;
            
            for (int col = 0; col < k; col++) {
                int actualCol = y + col;
                swap(result[topRow][actualCol], result[bottomRow][actualCol]);
            }
        }
        
        return result;
    }
};