class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        
        // dp0: ไม่เคยลบ, dp1: ลบไปแล้ว 1 ตัว
        int dp0 = arr[0];  // ผลรวมที่จบที่ i โดยไม่ลบ
        int dp1 = 0;       // ผลรวมที่จบที่ i โดยลบแล้ว
        int result = arr[0];
        
        for (int i = 1; i < n; i++) {
            // กรณีลบ element ปัจจุบัน: dp0 ก่อนหน้า (ไม่ลบ) + 0 (ลบตัวปัจจุบัน)
            // กรณีไม่ลบ element ปัจจุบัน: dp1 ก่อนหน้า + arr[i] (เพราะลบไปแล้วตัวก่อนหน้า)
            dp1 = max(dp0, dp1 + arr[i]);
            
            // กรณีไม่ลบ: ใช้ Kadane's algorithm ปกติ
            dp0 = max(arr[i], dp0 + arr[i]);
            
            // อัปเดตคำตอบที่ดีที่สุด
            result = max(result, max(dp0, dp1));
        }
        
        return result;
    }
};