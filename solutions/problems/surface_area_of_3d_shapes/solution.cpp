class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int area = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) continue;
                
                // พื้นที่ผิวของ stack นี้ถ้าแยกกัน
                area += 6 * grid[i][j];
                
                // ลบพื้นที่ที่ซ้อนกันในแนวตั้ง (ใน stack เดียวกัน)
                area -= 2 * (grid[i][j] - 1);
                
                // ลบพื้นที่ที่ซ้อนกับ cell ทางซ้าย (ถ้ามี)
                if (j > 0) {
                    area -= 2 * min(grid[i][j], grid[i][j-1]);
                }
                
                // ลบพื้นที่ที่ซ้อนกับ cell ด้านบน (ถ้ามี)
                if (i > 0) {
                    area -= 2 * min(grid[i][j], grid[i-1][j]);
                }
            }
        }
        
        return area;
    }
};