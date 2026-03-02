class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> trailingZeros(n);
        
        // คำนวณ trailing zeros ของแต่ละแถว
        for (int i = 0; i < n; i++) {
            int zeros = 0;
            // นับจากขวาไปซ้าย
            for (int j = n - 1; j >= 0; j--) {
                if (grid[i][j] == 0) {
                    zeros++;
                } else {
                    break;
                }
            }
            trailingZeros[i] = zeros;
        }
        
        int swaps = 0;
        
        // จัดเรียงแถว
        for (int i = 0; i < n; i++) {
            int required = n - i - 1;  // จำนวน trailing zeros ที่ต้องการ
            int found = -1;
            
            // หาแถวที่เหมาะสมจากตำแหน่ง i ลงไป
            for (int j = i; j < n; j++) {
                if (trailingZeros[j] >= required) {
                    found = j;
                    break;
                }
            }
            
            // ถ้าไม่พบ แสดงว่าเป็นไปไม่ได้
            if (found == -1) {
                return -1;
            }
            
            // สลับแถว found ขึ้นมาที่ i (bubble up)
            for (int j = found; j > i; j--) {
                swap(trailingZeros[j], trailingZeros[j - 1]);
                swaps++;
            }
        }
        
        return swaps;
    }
};