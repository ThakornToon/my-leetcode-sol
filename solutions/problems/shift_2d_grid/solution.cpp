class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int total = m * n;
        
        // ลด k
        k = k % total;
        if (k == 0) {
            return grid;  // ไม่ต้องเลื่อน
        }
        
        // สร้าง grid ผลลัพธ์
        vector<vector<int>> result(m, vector<int>(n));
        
        // ใส่ค่าในตำแหน่งใหม่
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // คำนวณตำแหน่งใหม่ใน 1 มิติ
                int newIndex = (i * n + j + k) % total;
                
                // แปลงกลับเป็น 2 มิติ
                int newRow = newIndex / n;
                int newCol = newIndex % n;
                
                result[newRow][newCol] = grid[i][j];
            }
        }
        
        return result;
    }
};