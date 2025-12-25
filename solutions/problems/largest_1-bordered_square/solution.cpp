class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // prefix sum สำหรับนับจำนวน 1 ในแนวนอนและแนวตั้ง
        vector<vector<int>> hor(m, vector<int>(n, 0));  // horizontal prefix
        vector<vector<int>> ver(m, vector<int>(n, 0));  // vertical prefix
        
        // คำนวณ prefix sum นับ 1 ที่ต่อเนื่องกัน
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    hor[i][j] = (j == 0) ? 1 : hor[i][j-1] + 1;
                    ver[i][j] = (i == 0) ? 1 : ver[i-1][j] + 1;
                } else {
                    hor[i][j] = 0;
                    ver[i][j] = 0;
                }
            }
        }
        
        int maxSize = 0;
        
        // ตรวจการสร้างสี่เหลี่ยมจัตุรัสจากมุมขวาล่างถ้าเป็น 1 
        for (int i = m-1; i >= maxSize; i--) {
            for (int j = n-1; j >= maxSize; j--) {
                if (grid[i][j] == 0) continue;
                
                // side length ที่เป็นไปได้มากสุดจาก prefix sum (เริ่มจากขนาดใหญ่ไปเล็ก)
                int possibleSize = min(hor[i][j], ver[i][j]);
                
                // ตรวจสอบจากขนาดที่ใหญ่สุดเท่าที่เป็นไปได้
                for (int size = possibleSize; size > maxSize; size--) {
                    // ตรวจสอบว่าเป็นสี่เหลี่ยมจัตุรัสจริงๆ หรือไม่
                    // ต้องตรวจสอบทั้ง 4 ด้าน(ก่อนหน้าตรวจไปสองด้านแล้ว)
                    int top = i - size + 1;
                    int left = j - size + 1;
                    
                    // ตรวจสอบด้านบน (top row)
                    if (hor[top][j] >= size && 
                        // ตรวจสอบด้านซ้าย (left column)
                        ver[i][left] >= size) {
                        maxSize = max(maxSize, size);
                        break;  // ไม่ต้องตรวจสอบขนาดที่เล็กกว่า
                    }
                }
            }
        }
        
        return maxSize * maxSize;  // return area
    }
};