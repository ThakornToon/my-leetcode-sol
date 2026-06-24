class Solution {
public:
    int minimumBoxes(int n) {
        // หาจำนวนชั้นที่สมบูรณ์โดยใช้สูตร
        // 1 + 3 + 6 + ... + k*(k+1)/2 <= n
        // ผลรวม = k*(k+1)*(k+2)/6 <= n
        
        long long k = 0;
        while ((k + 1) * (k + 2) * (k + 3) / 6 <= n) {
            k++;
        }
        
        // k = จำนวนชั้นที่สมบูรณ์
        // กล่องที่ใช้ = k*(k+1)*(k+2)/6
        long long boxesUsed = k * (k + 1) * (k + 2) / 6;
        long long boxesInLastLayer = k * (k + 1) / 2;
        long long remaining = n - boxesUsed;
        
        // หาแถวที่เหลือในชั้นถัดไป
        long long row = 1;
        while (remaining > 0) {
            if (remaining >= row) {
                remaining -= row;
                boxesInLastLayer++;
                row++;
            } else {
                boxesInLastLayer++;
                remaining = 0;
            }
        }
        
        return (int)boxesInLastLayer;
    }
};