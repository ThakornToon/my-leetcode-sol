class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
    
        // ทิศทาง
        int dir[4][2] = {{-1,0}, {0,1}, {1,0}, {0,-1}};
        
        // 1. หาเกาะแรก (DFS)
        queue<pair<int,int>> q;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        
        bool found = false;
        for (int i = 0; i < n && !found; i++) {
            for (int j = 0; j < n && !found; j++) {
                if (grid[i][j] == 1) {
                    // DFS
                    queue<pair<int,int>> stack;
                    stack.push({i, j});
                    visited[i][j] = true;
                    
                    while (!stack.empty()) {
                        auto [x, y] = stack.front();
                        stack.pop();
                        
                        // เก็บขอบเกาะไว้ใน q สำหรับ BFS
                        q.push({x, y});
                        
                        // ไปทุกทิศทาง
                        for (int d = 0; d < 4; d++) {
                            int nx = x + dir[d][0];
                            int ny = y + dir[d][1];
                            
                            if (nx >= 0 && nx < n && ny >= 0 && ny < n && 
                                !visited[nx][ny] && grid[nx][ny] == 1) {
                                visited[nx][ny] = true;
                                stack.push({nx, ny});
                            }
                        }
                    }
                    found = true; // เจอเกาะแรกแล้ว
                }
            }
        }
        
        // 2. BFS หาสะพาน
        int steps = 0;
        while (!q.empty()) {
            int size = q.size();
            
            for (int i = 0; i < size; i++) {
                auto [x, y] = q.front();
                q.pop();
                
                for (int d = 0; d < 4; d++) {
                    int nx = x + dir[d][0];
                    int ny = y + dir[d][1];
                    
                    if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if (visited[nx][ny]) continue;
                    
                    // เจอเกาะที่สอง
                    if (grid[nx][ny] == 1) return steps;
                    
                    // เป็นน้ำ
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
            steps++;
        }
        
        return -1;
    }
};