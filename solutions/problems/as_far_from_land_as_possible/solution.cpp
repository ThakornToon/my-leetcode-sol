class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        
        queue<pair<int, int>> q;
        
        // เริ่ม BFS จากจุดที่เป็นที่ดินทั้งหมด
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                }
            }
        }
        
        // ถ้าไม่มีที่ดินหรือมีแต่น้ำทั้งหมด
        if (q.size() == 0 || q.size() == n * n) {
            return -1;
        }
        
        // Directions: up, down, left, right
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int maxDistance = -1;
        
        // BFS
        while (!q.empty()) {
            int size = q.size();
            maxDistance++;  // เพิ่มระยะทางในแต่ละ level
            
            for (int i = 0; i < size; i++) {
                auto [x, y] = q.front();
                q.pop();
                
                for (auto [dx, dy] : directions) {
                    int nx = x + dx;
                    int ny = y + dy;
                    
                    // ตรวจสอบขอบเขตและว่าเป็นน้ำที่ยังไม่เคยเยือน
                    if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 0) {
                        // ทำเครื่องหมายว่าเยือนแล้ว
                        grid[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
            }
        }
        
        return maxDistance;
    }
};