class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // จุดเริ่มต้นหรือจุดปลายเป็นกำแพง
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) {
            return -1;
        }
        
        // 8 ทิศทาง
        vector<pair<int, int>> directions = {
            {-1, -1}, {-1, 0}, {-1, 1},
            {0, -1},           {0, 1},
            {1, -1},  {1, 0},  {1, 1}
        };
        
        // distance matrix
        vector<vector<int>> dist(n, vector<int>(n, -1));
        
        // queue สำหรับ BFS
        queue<pair<int, int>> q;
        q.push({0, 0});
        dist[0][0] = 1;
        
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            
            // ถ้าถึงจุดหมาย
            if (r == n-1 && c == n-1) {
                return dist[r][c];
            }
            
            // ตรวจสอบ 8 ทิศทาง
            for (auto& dir : directions) {
                int nr = r + dir.first;
                int nc = c + dir.second;
                
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && 
                    grid[nr][nc] == 0 && dist[nr][nc] == -1) {
                    
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }
        
        return -1;
    }
};