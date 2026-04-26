class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j]) continue;
                
                char target = grid[i][j];
                // {curri, currj, previ, prevj}
                queue<tuple<int, int, int, int>> q;
                q.push({i, j, -1, -1});
                visited[i][j] = true;
                
                while (!q.empty()) {
                    auto [x, y, px, py] = q.front();
                    q.pop();
                    
                    for (auto& dir : dirs) {
                        int nx = x + dir[0];
                        int ny = y + dir[1];
                        
                        if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                        if (grid[nx][ny] != target) continue;
                        if (nx == px && ny == py) continue;
                        
                        if (visited[nx][ny]) return true;
                        
                        visited[nx][ny] = true;
                        q.push({nx, ny, x, y});
                    }
                }
            }
        }
        
        return false;
    }
};