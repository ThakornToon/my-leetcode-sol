class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Directions
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        queue<pair<int, int>> q;
        
        // Add all boundary land cells to queue
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if ((i == 0 || i == m-1 || j == 0 || j == n-1) && grid[i][j] == 1) {
                    q.push({i, j});
                    grid[i][j] = 0; // Mark as visited
                }
            }
        }
        
        // BFS to mark all reachable land cells
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            
            for (auto [dx, dy] : dirs) {
                int nx = x + dx;
                int ny = y + dy;
                
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                    grid[nx][ny] = 0;
                    q.push({nx, ny});
                }
            }
        }
        
        // Count remaining land cells (enclaves)
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    count++;
                }
            }
        }
        
        return count;
    }
};