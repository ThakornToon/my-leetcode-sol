class Solution {
public:
    // DFS Solution
    int maxAreaOfIsland(vector<vector<int>>& grid) {        
        int maxArea = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    maxArea = max(maxArea, dfs(grid, i, j));
                }
            }
        }
        
        return maxArea;
    }
    
private:
    int dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0) {
            return 0;
        }
        
        grid[i][j] = 0; // Mark as visited
        
        return 1 + dfs(grid, i + 1, j) 
                 + dfs(grid, i - 1, j)
                 + dfs(grid, i, j + 1)
                 + dfs(grid, i, j - 1);
    }
};