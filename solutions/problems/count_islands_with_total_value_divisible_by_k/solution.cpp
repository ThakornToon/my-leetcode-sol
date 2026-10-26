class Solution {
private:
    long long dfs(int r, int c, std::vector<std::vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 0) {
            return 0;
        }
        
        long long sum = grid[r][c];
        grid[r][c] = 0; // Mark as visited
        
        // 4 directions
        sum += dfs(r + 1, c, grid);
        sum += dfs(r - 1, c, grid);
        sum += dfs(r, c + 1, grid);
        sum += dfs(r, c - 1, grid);
        
        return sum;
    }
    
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] > 0) {
                    long long sum = dfs(i, j, grid);
                    if (sum % k == 0) {
                        cnt++;
                    }
                }
            }
        }
        
        return cnt;
    }
};