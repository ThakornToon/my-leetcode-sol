class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.length();
        int maxLength = 0;
        int currentCost = 0;
        int left = 0;
        
        for (int right = 0; right < n; right++) {
            // คำนวณค่าใช้จ่ายสำหรับตัวอักษรปัจจุบัน
            int cost = abs(s[right] - t[right]);
            currentCost += cost;
            
            // ถ้าเกิน budget ให้ขยับหน้าต่างซ้าย
            while (currentCost > maxCost) {
                currentCost -= abs(s[left] - t[left]);
                left++;
            }
            
            // อัปเดตความยาวสูงสุด
            maxLength = max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};