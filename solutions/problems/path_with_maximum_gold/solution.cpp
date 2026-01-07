class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxGold = 0;
        
        // ทิศทางที่สามารถเดินได้
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        // ฟังก์ชัน DFS แบบ backtracking
        function<int(int, int)> dfs = [&](int row, int col) -> int {
            // ตรวจสอบขอบเขตและว่าเซลล์มีทองคำหรือไม่
            if (row < 0 || row >= m || col < 0 || col >= n || grid[row][col] == 0) {
                return 0;
            }
            
            // เก็บค่าทองคำในเซลล์ปัจจุบัน
            int currentGold = grid[row][col];
            
            // เก็บเซลล์ปัจจุบันและตั้งค่าเป็น 0 เพื่อป้องกันการวนลูป
            grid[row][col] = 0;
            
            int maxPathGold = 0;
            
            // สำรวจทุกทิศทาง
            for (auto& dir : directions) {
                int newRow = row + dir.first;
                int newCol = col + dir.second;
                
                maxPathGold = max(maxPathGold, dfs(newRow, newCol));
            }
            
            // คืนค่าเซลล์กลับสู่สถานะเดิม (backtrack)
            grid[row][col] = currentGold;
            
            // คืนค่าทองคำที่รวบรวมได้ (ค่าปัจจุบัน + ค่าจากเส้นทางที่ดีที่สุด)
            return currentGold + maxPathGold;
        };
        
        // พยายามเริ่มจากทุกเซลล์ที่มีทองคำ
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    maxGold = max(maxGold, dfs(i, j));
                }
            }
        }
        
        return maxGold;
    }
};