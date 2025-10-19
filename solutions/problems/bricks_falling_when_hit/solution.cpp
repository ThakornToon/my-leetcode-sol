class Solution {
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        int m = grid.size(), n = grid[0].size();
        vector<int> result(hits.size(), 0);
        
        // สำรอง grid เดิมไว้ตรวจสอบ
        vector<vector<int>> original = grid;
        
        // จำลองการตีอิฐทั้งหมดก่อน
        for (auto& hit : hits) {
            int i = hit[0], j = hit[1];
            if (grid[i][j] == 1) {
                grid[i][j] = 0;
            }
        }
        
        // Mark stable bricks (ที่ยังเชื่อมต่อกับด้านบน)
        vector<vector<bool>> stable(m, vector<bool>(n, false));
        
        // Mark top row as stable
        for (int j = 0; j < n; j++) {
            if (grid[0][j] == 1) {
                markStable(grid, stable, 0, j);
            }
        }
        
        // Process hits in reverse
        for (int k = hits.size() - 1; k >= 0; k--) {
            int i = hits[k][0], j = hits[k][1];
            
            if (original[i][j] == 1) { // ถ้าตีโดนอิฐจริงๆ
                grid[i][j] = 1; // เอาก้อนอิฐกลับมา
                
                // เช็คว่าก้อนนี้เชื่อมกับ stable หรือไม่
                bool connected = false;
                if (i == 0) connected = true; // อยู่แถวบนสุด
                
                // เช็คเพื่อนบ้านว่ามี stable ไหม
                vector<pair<int, int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};
                for (auto [di, dj] : dirs) {
                    int ni = i + di, nj = j + dj;
                    if (ni >= 0 && ni < m && nj >= 0 && nj < n && stable[ni][nj]) {
                        connected = true;
                        break;
                    }
                }
                
                // ถ้าก้อนนี้่ stable
                if (connected) {
                    // นับอิฐที่กลับมาเชื่อมต่อใหม่
                    int count = markStable(grid, stable, i, j) - 1; // ไม่นับก่อนที่ตี
                    result[k] = count;
                }
            }
        }
        
        return result;
    }

private:
    // นับอิฐไม่ stable ที่จะกลายเป็น stable และ mark ไปด้วย(นับอิฐฟื้นฟู)
    int markStable(vector<vector<int>>& grid, vector<vector<bool>>& stable, int i, int j) {
        int m = grid.size(), n = grid[0].size();
        // ดูว่าเงื่อนไขปัจจุบันจะทำให้เปลี่ยนเป็น stable ไหม (ถ้า stable อยู่แล้วเราจะไม่สนใจ)
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != 1 || stable[i][j]) {
            return 0;
        }
        
        // ถ้าปัจจุบัน stable จะขยายไปรอบๆด้วย
        stable[i][j] = true;
        int count = 1;
        
        vector<pair<int, int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        for (auto [di, dj] : dirs) {
            count += markStable(grid, stable, i + di, j + dj);
        }
        
        return count;
    }
};