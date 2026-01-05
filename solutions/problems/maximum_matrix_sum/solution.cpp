class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        // ย้ายเครื่องหมายไปไหนก็ได้ ถ้าเจอเพื่อนที่อยู่ติดกันสามารถทำลายเครื่องหมายทั้งคู่ได้
        int n = matrix.size();
        long long totalSum = 0;
        int minAbs = INT_MAX;
        int negativeCount = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int val = matrix[i][j];
                totalSum += abs(val);
                
                if (val < 0) {
                    negativeCount++;
                }
                
                // หาค่าสัมบูรณ์ที่น้อยที่สุด
                minAbs = min(minAbs, abs(val));
            }
        }
        
        // ถ้าจำนวนลบคู่ เราสามารถกำจัดลบทั้งหมดได้
        // ถ้าจำนวนลบคี่ เราต้องเหลือลบ 1 ตัว → ลบค่า 2*minAbs
        if (negativeCount % 2 == 0) {
            return totalSum;
        } else {
            return totalSum - 2 * minAbs;
        }
    }
};