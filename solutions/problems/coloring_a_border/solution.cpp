class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int m = grid.size(), n = grid[0].size();
        int originalColor = grid[row][col];
        
        if (originalColor == color) return grid;
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<vector<bool>> isBorder(m, vector<bool>(n, false));
        
        // DFS function
        function<void(int, int)> dfs = [&](int r, int c) {
            visited[r][c] = true;
            
            // Check if on boundary
            if (r == 0 || r == m-1 || c == 0 || c == n-1) {
                isBorder[r][c] = true;
            }
            
            // Directions
            vector<pair<int, int>> dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}};
            
            for (auto [dr, dc] : dirs) {
                int nr = r + dr;
                int nc = c + dc;
                
                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    if (!visited[nr][nc]) {
                        if (grid[nr][nc] == originalColor) {
                            dfs(nr, nc);
                        } else {
                            // Different color neighbor
                            isBorder[r][c] = true;
                        }
                    }
                } else {
                    // Out of bounds
                    isBorder[r][c] = true;
                }
            }
        };
        
        dfs(row, col);
        
        // Create result
        vector<vector<int>> result = grid;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isBorder[i][j]) {
                    result[i][j] = color;
                }
            }
        }
        
        return result;
    }
};