class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        vector<vector<int>> result;
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        
        // Directions: up, down, left, right
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        queue<pair<int, int>> q;
        q.push({rCenter, cCenter});
        visited[rCenter][cCenter] = true;
        
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            result.push_back({r, c});
            
            for (auto [dr, dc] : dirs) {
                int nr = r + dr;
                int nc = c + dc;
                
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && !visited[nr][nc]) {
                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
        
        return result;
    }
};