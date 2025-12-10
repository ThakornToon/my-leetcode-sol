class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int onesCount = 0;
        int flips = 0;
        
        for (char c : s) {
            if (c == '1') {
                onesCount++;
            } else {
                // เมื่อเจอ 0, เราตัดสินใจ:
                // 1. เปลี่ยน 0 นี้เป็น 1 (flips++)
                // 2. หรือเปลี่ยน onesCount ทั้งหมดที่ผ่านมาเป็น 0
                flips = min(flips + 1, onesCount);
            }
        }
        
        return flips;
    }
};