class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        int startX = 0, startY = 0;
        int emptyCount = 1; // รวมจุดเริ่มต้น
        
        // หาจุดเริ่มต้นและนับช่องที่ต้องเดินผ่าน
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    startX = i;
                    startY = j;
                } else if (grid[i][j] == 0) {
                    emptyCount++;
                }
            }
        }
        
        return dfs(grid, startX, startY, emptyCount);
    }
    
private:
    int m, n;
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    int dfs(vector<vector<int>>& grid, int x, int y, int emptyCount) {
        // ตรวจสอบขอบเขตและอุปสรรค
        if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == -1) {
            return 0;
        }
        
        // ถ้าเจอจุดสิ้นสุด
        if (grid[x][y] == 2) {
            return emptyCount == 0 ? 1 : 0;
        }
        
        // Mark as visited
        grid[x][y] = -1;
        int paths = 0;
        
        // สำรวจทุกทิศทาง
        for (auto& dir : dirs) {
            int nx = x + dir[0];
            int ny = y + dir[1];
            paths += dfs(grid, nx, ny, emptyCount - 1);
        }
        
        // Backtrack
        grid[x][y] = 0;
        
        return paths;
    }
};