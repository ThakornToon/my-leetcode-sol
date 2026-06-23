class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> result(n);
        
        // ลองแต่ละคอลัมน์
        for (int col = 0; col < n; col++) {
            int c = col; // ตำแหน่งคอลัมน์ปัจจุบัน
            
            // ไล่ลงมาแต่ละแถว
            for (int r = 0; r < m; r++) {
                int direction = grid[r][c];
                
                // ตรวจสอบการเคลื่อนที่
                if (direction == 1) {
                    // เช็คขอบขวา และ cell ถัดไป
                    if (c + 1 >= n || grid[r][c + 1] != 1) {
                        c = -1; // ติด
                        break;
                    }
                    c++; // เลื่อนลงขวา
                } else { // direction == -1
                    // เช็คขอบซ้าย และ cell ก่อนหน้า
                    if (c - 1 < 0 || grid[r][c - 1] != -1) {
                        c = -1; // ติด
                        break;
                    }
                    c--; // เลื่อนลงซ้าย
                }
            }
            
            result[col] = c;
        }
        
        return result;

    }
};