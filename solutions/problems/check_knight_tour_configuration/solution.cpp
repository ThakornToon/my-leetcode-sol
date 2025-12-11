class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // ต้องเริ่มจาก 0 ที่ (0,0)
        if (grid[0][0] != 0) return false;
        
        // Knight moves ทั้ง 8 ทิศทาง
        vector<pair<int, int>> moves = {
            {-2, -1}, {-2, 1}, {-1, -2}, {-1, 2},
            {1, -2}, {1, 2}, {2, -1}, {2, 1}
        };
        
        int currentNum = 0;
        int x = 0, y = 0;
        
        while (currentNum < n * n - 1) {
            bool foundNext = false;
            
            for (auto& [dx, dy] : moves) {
                int nx = x + dx;
                int ny = y + dy;
                
                if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                    if (grid[nx][ny] == currentNum + 1) {
                        x = nx;
                        y = ny;
                        currentNum++;
                        foundNext = true;
                        break;
                    }
                }
            }
            
            if (!foundNext) return false;
        }
        
        return true;
    }
};