class Solution {
private:
    void dfs(vector<vector<int>>& grid, int x, int y) {
        int n = grid.size();
        if (x < 0 || x >= n || y < 0 || y >= n || grid[x][y] != 0) {
            return;
        }
        
        grid[x][y] = 1;
        
        dfs(grid, x + 1, y);
        dfs(grid, x - 1, y);
        dfs(grid, x, y + 1);
        dfs(grid, x, y - 1);
    }
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        int size = 3 * n;
        
        // สร้าง expanded grid
        vector<vector<int>> expanded(size, vector<int>(size, 0));
        
        // แปลงแต่ละ cell เป็น 3×3 block
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int baseX = 3 * i;
                int baseY = 3 * j;
                
                if (grid[i][j] == '/') {
                    expanded[baseX][baseY + 2] = 1;
                    expanded[baseX + 1][baseY + 1] = 1;
                    expanded[baseX + 2][baseY] = 1;
                } else if (grid[i][j] == '\\') {
                    expanded[baseX][baseY] = 1;
                    expanded[baseX + 1][baseY + 1] = 1;
                    expanded[baseX + 2][baseY + 2] = 1;
                }
            }
        }
        
        // DFS เพื่อนับ regions
        int regions = 0;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (expanded[i][j] == 0) {
                    regions++;
                    dfs(expanded, i, j);
                }
            }
        }
        
        return regions;
    }
};