class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        
        if (m == 1 && n == 1) return 0;
        
        bool visited[m][n][k + 1];
        memset(visited, 0, sizeof(visited));
        
        // queue เก็บ struct
        struct State {
            int row, col, k, dist;
        };
        
        queue<State> q;
        q.push({0, 0, k, 0});
        visited[0][0][k] = true;
        
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while (!q.empty()) {
            State curr = q.front();
            q.pop();
            
            for (auto& dir : dirs) {
                int nr = curr.row + dir[0];
                int nc = curr.col + dir[1];
                
                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                
                int newK = curr.k;
                if (grid[nr][nc] == 1) {
                    if (newK == 0) continue;
                    newK--;
                }
                
                if (!visited[nr][nc][newK]) {
                    if (nr == m - 1 && nc == n - 1) {
                        return curr.dist + 1;
                    }
                    
                    visited[nr][nc][newK] = true;
                    q.push({nr, nc, newK, curr.dist + 1});
                }
            }
        }
        
        return -1;
    }
};