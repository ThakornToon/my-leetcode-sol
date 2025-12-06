class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> result;
        
        // ทิศทาง: ขวา, ล่าง, ซ้าย, บน
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        int r = rStart, c = cStart;
        int step = 1;        // ความยาวก้าวเริ่มต้น
        int dir = 0;         // เริ่มทิศขวา
        
        // เพิ่มจุดเริ่มต้น
        result.push_back({r, c});
        
        while (result.size() < rows * cols) {
            // เดิน 2 ทิศทางด้วยความยาว step เดิม
            for (int i = 0; i < 2; i++) {
                // เดิน step ก้าวในทิศทางปัจจุบัน
                for (int j = 0; j < step; j++) {
                    r += dirs[dir][0];
                    c += dirs[dir][1];
                    
                    // ตรวจสอบว่าอยู่ใน grid
                    if (r >= 0 && r < rows && c >= 0 && c < cols) {
                        result.push_back({r, c});
                        if (result.size() == rows * cols) {
                            return result;
                        }
                    }
                }
                // เปลี่ยนทิศทาง
                dir = (dir + 1) % 4;
            }
            // ทุก 2 ทิศทาง เพิ่ม step
            step++;
        }
        
        return result;
    }
};