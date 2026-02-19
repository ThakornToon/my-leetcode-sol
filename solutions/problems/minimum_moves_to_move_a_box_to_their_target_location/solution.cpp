class Solution {
public:
    int minPushBox(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // หาตำแหน่งเริ่มต้น
        int startBX = -1, startBY = -1;
        int startPX = -1, startPY = -1;
        int targetX = -1, targetY = -1;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 'B') {
                    startBX = i; startBY = j;
                } else if (grid[i][j] == 'S') {
                    startPX = i; startPY = j;
                } else if (grid[i][j] == 'T') {
                    targetX = i; targetY = j;
                }
            }
        }
        
        // visited[box_x][box_y][player_x][player_y]
        bool visited[20][20][20][20] = {false};
        
        // queue: (box_x, box_y, player_x, player_y, push)
        queue<tuple<int, int, int, int, int>> q;
        q.push({startBX, startBY, startPX, startPY, 0});
        visited[startBX][startBY][startPX][startPY] = true;
        
        // ทิศทาง
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        
        while (!q.empty()) {
            auto [bx, by, px, py, push] = q.front();
            q.pop();
            
            // ตรวจสอบว่ากล่องถึงเป้าหมายแล้ว
            if (bx == targetX && by == targetY) {
                return push;
            }
            
            // พยายามผลักกล่องใน 4 ทิศทาง
            for (int d = 0; d < 4; d++) {
                // ตำแหน่งใหม่ของกล่อง
                int nbx = bx + dx[d];
                int nby = by + dy[d];
                
                // ตำแหน่งที่ผู้เล่นต้องยืนเพื่อผลักกล่อง
                int pushX = bx - dx[d];
                int pushY = by - dy[d];
                
                // ตรวจสอบว่าตำแหน่งถูกต้อง
                if (isValid(nbx, nby, grid) && isValid(pushX, pushY, grid)) {
                    // ตรวจสอบว่าผู้เล่นสามารถไปยังจุดผลักได้หรือไม่
                    if (canPlayerReach(grid, px, py, pushX, pushY, bx, by)) {
                        if (!visited[nbx][nby][bx][by]) {
                            visited[nbx][nby][bx][by] = true;
                            q.push({nbx, nby, bx, by, push + 1});
                        }
                    }
                }
            }
        }
        
        return -1;
    }
    
private:
    bool isValid(int x, int y, const vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        return x >= 0 && x < m && y >= 0 && y < n && grid[x][y] != '#';
    }
    
    bool canPlayerReach(const vector<vector<char>>& grid, int startX, int startY,
                        int targetX, int targetY, int boxX, int boxY) {
        if (startX == targetX && startY == targetY) return true;
        
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        
        q.push({startX, startY});
        visited[startX][startY] = true;
        
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            
            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                
                if (isValid(nx, ny, grid) && !visited[nx][ny] && !(nx == boxX && ny == boxY)) {
                    if (nx == targetX && ny == targetY) return true;
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
        
        return false;
    }
};