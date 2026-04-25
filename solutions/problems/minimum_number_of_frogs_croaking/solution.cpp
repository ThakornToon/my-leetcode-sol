class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int n = croakOfFrogs.length();
        if (n % 5 != 0) return -1;
        
        vector<int> count(5, 0);  // c,r,o,a,k
        int activeFrogs = 0;
        int maxFrogs = 0;
        
        // Map ตัวอักษรกับ index
        unordered_map<char, int> idx = {{'c',0}, {'r',1}, {'o',2}, {'a',3}, {'k',4}};
        
        for (char c : croakOfFrogs) {
            int i = idx[c];
            
            if (i == 0) {
                // เริ่มร้องใหม่
                count[i]++;
                activeFrogs++;
                maxFrogs = max(maxFrogs, activeFrogs);
            } else {
                // ต้องมีเสียงก่อนหน้า
                if (count[i-1] <= count[i]) return -1;
                count[i]++;
                if (i == 4) activeFrogs--;  // จบการร้อง
            }
        }
        
        // ตรวจสอบว่าทุกเสียงจบสมบูรณ์
        if (count[0] != count[4] || count[1] != count[4] || 
            count[2] != count[4] || count[3] != count[4]) {
            return -1;
        }
        
        return maxFrogs;
    }
};