class Solution {
public:
    const vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    bool isClosed = true;
                    dfs(grid, i, j, isClosed);
                    if (isClosed) {
                        count++;
                    }
                }
            }
        }
        
        return count;
    }

private:
    void dfs(vector<vector<int>>& grid, int i, int j, bool& isClosed) {
        int m = grid.size();
        int n = grid[0].size();
        
        // ถ้าเจอขอบ -> ไม่ใช่ closed island
        if (i == 0 || i == m-1 || j == 0 || j == n-1) {
            isClosed = false;
        }
        
        // mark visited
        grid[i][j] = 2;
        
        // สำรวจ 4 ทิศทาง
        for (auto [dx, dy] : dirs) {
            int ni = i + dx;
            int nj = j + dy;
            
            if (ni >= 0 && ni < m && nj >= 0 && nj < n && grid[ni][nj] == 0) {
                dfs(grid, ni, nj, isClosed);
            }
        }
    }
};