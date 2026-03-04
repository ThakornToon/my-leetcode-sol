class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int result = 0;
        
        // หาแถวที่มี 1 เพียงตัวเดียว
        for (int i = 0; i < m; i++) {
            int colOfOne = -1;
            int oneCount = 0;
            
            // หาตำแหน่งของ 1 ในแถวนี้
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    oneCount++;
                    colOfOne = j;
                }
            }
            
            // ถ้ามี 1 เพียงตัวเดียวในแถว
            if (oneCount == 1) {
                // ตรวจสอบคอลัมน์ว่ามี 1 เพียงตัวเดียวหรือไม่
                int colOneCount = 0;
                for (int k = 0; k < m; k++) {
                    if (mat[k][colOfOne] == 1) {
                        colOneCount++;
                    }
                }
                
                if (colOneCount == 1) {
                    result++;
                }
            }
        }
        
        return result;
    }
};