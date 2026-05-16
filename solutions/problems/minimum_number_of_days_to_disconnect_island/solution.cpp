class Solution {
private:
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
    // DFS เพื่อนับจำนวนเกาะ
    void dfs(int row, int col, vector<vector<bool>>& visited, vector<vector<int>>& grid, int m, int n) {
        visited[row][col] = true;
        
        for (auto& dir : directions) {
            int newRow = row + dir[0];
            int newCol = col + dir[1];
            
            if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n &&
                !visited[newRow][newCol] && grid[newRow][newCol] == 1) {
                dfs(newRow, newCol, visited, grid, m, n);
            }
        }
    }

    // นับจำนวนเกาะ
    int countIslands(vector<vector<int>>& grid, int m, int n) {
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int count = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    count++;
                    dfs(i, j, visited, grid, m, n); // หรือใช้ bfs ก็ได้
                }
            }
        }
        
        return count;
    }
    
    // นับจำนวน cell ของเกาะ
    int countLand(vector<vector<int>>& grid, int m, int n) {
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) count++;
            }
        }
        return count;
    }
public:
    int minDays(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // กรณีที่ 1: ถ้าเกาะไม่เชื่อมต่อกันอยู่แล้ว(มีหลายเกาะ)
        int islands = countIslands(grid, m, n);
        if (islands != 1) return 0;
        
        // กรณีที่ 2: ถ้าเกาะขนาดเพียง 1 เซลล์
        int landCount = countLand(grid, m, n);
        if (landCount == 1) return 1;
        
        // กรณีที่ 3: ทดลองลบทีละเซลล์ ตรวจสอบว่าใช้ 1 วันได้หรือไม่
        /*
            100
            111
        */
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    // ลบเซลล์นี้ชั่วคราว
                    grid[i][j] = 0;
                    
                    // ตรวจสอบว่าเกาะแยกหรือไม่
                    int newIslands = countIslands(grid, m, n);
                    if (newIslands != 1) {
                        return 1; // ใช้เวลา 1 วัน
                    }
                    
                    // คืนค่าเซลล์กลับมา
                    grid[i][j] = 1;
                }
            }
        }

        // กรณีอื่นๆ ใช้ 2 วันเพราะสามารถลบมุมของเกาะได้เสมอ
        return 2;
    }
};