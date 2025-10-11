class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxNum = *max_element(nums.begin(), nums.end());
        vector<int> points(maxNum + 1, 0);
        
        // สร้าง points array แทนบ้านแต่ละหลัง / เมื่อลลบเลขนั้นๆ
        for (int num : nums) {
            points[num] += num;
        }
        
        // เหมือน House Robber
        int prev2 = 0; // ลบหมายเลข 0
        int currentMax = points[1]; // ลบหมายเลข 1
        for (int i = 2; i <= maxNum; i++) {
            int current = max(currentMax, prev2 + points[i]); // ค่ามากสุดโดยเลือกว่าจะลบหรือไม่ลบอันปัจจุบัน
            prev2 = currentMax; // ไม่ลบอันปัจจุบัน
            currentMax = current; // ค่ามากสุดโดยเลือกว่าจะลบหรือไม่ลบอันปัจจุบัน
        }
        
        return currentMax;
    }
};